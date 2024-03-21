//
// Created by Clément² on 13/03/2024. (Pas elie trop nul)
//

#include "../include/parser.h"

// List of instructions along with their hex values and argument counts
Instruction instructions[] = {
        {"LOAD_VAL",    LOAD_VAL,    1},
        {"READ_VAR",    READ_VAR,    1},
        {"STORE_VAR",   STORE_VAR,   1},
        {"ADD",         ADD,         0},
        {"SUB",         SUB,         0},
        {"MUL",         MUL,         0},
        {"DIV",         DIV,         0},
        {"MOD",         MOD,         0},
        {"JMP",         JMP,         1},
        {"JMP_IF_ZERO", JMP_IF_ZERO, 1},
        {"JMP_IF_TRUE", JMP_IF_TRUE, 1},
        {"JMP_IF_TRUE", JMP_IF_TRUE, 1},
        {"EQ",          EQ,          0},
        {"NEQ",         NEQ,         0},
        {"GT",          GT,          0},
        {"LT",          LT,          0},
        {"GTE",         GTE,         0},
        {"LTE",         LTE,         0},
        {"PRINT_VAL",   PRINT_VAL,   0},
        {"INPUT_VAL",   INPUT_VAL,   0},
        {"HALT",        HALT,        0},
        {"LOAD_STR",    LOAD_STR,    1},
        {"PRINT_STR",   PRINT_STR,   0},
        {"INPUT_STR",   INPUT_STR,   0},
        {"STR_LEN",     STR_LEN,     0},
        {"CONCAT",      CONCAT,      0},
        {"GET_CHAR",    GET_CHAR,    0},
        {"SET_CHAR",    SET_CHAR,    0},
        {"STR_CMP",     STR_CMP,     0},
        {NULL, -1,                   0} // Sentinel value to mark the end of the list
};

void int_to_big_endian(int num, uint8_t *buffer) {
    buffer[0] = (num >> 24) & 0xFF;
    buffer[1] = (num >> 16) & 0xFF;
    buffer[2] = (num >> 8) & 0xFF;
    buffer[3] = num & 0xFF;
}

void parseLine(FILE *binaryFile, char *line) {
    char *token;
    char *delimiter = " \t\n"; // Whitespace characters
    char *args[10]; // Array to store arguments

    // Split the line into tokens
    token = strtok(line, delimiter);

    // Check if token is not NULL
    if (token != NULL) {
        // Lookup the instruction in the list
        int i = 0;
        while (instructions[i].name != NULL) {
            if (strcmp(token, instructions[i].name) == 0) {
                // Write hex value to binary file
                fwrite(&instructions[i].hexValue, 1, 1, binaryFile);

                // Store arguments
                for (int j = 0; j < instructions[i].numArgs; j++) {
                    token = strtok(NULL, delimiter);
                    if (token != NULL) {
                        args[j] = token;
                    } else {
                        printf("<missing argument>\n"); // Print <missing argument> if no argument found
                        return;
                    }
                }

                // Write arguments to binary file
                for (int j = 0; j < instructions[i].numArgs; j++) {
                    int arg = atoi(args[j]); // Convert argument to integer
                    uint8_t buffer[sizeof(int)];
                    int_to_big_endian(arg, buffer);
                    fwrite(buffer, sizeof(uint8_t), sizeof(int), binaryFile);
                }

                return; // Exit function once found
            }
            i++;
        }
        printf("Instruction not found: %s\n", token);
    }
}