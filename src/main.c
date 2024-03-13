//
// Created by Clément² on 13/03/2024. (Pas elie trop nul)
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "../include/main.h"

#define MAX_LINE_LENGTH 100

// Structure to store instruction names and their hex values
typedef struct {
    char *name;
    int hexValue;
    int numArgs;
} Instruction;

struct {
    char magic[4];
    unsigned int size;
    char name[16];
} header = {
    .magic = {'C', 'O', 'D', 'E'},
    .size = 0,
    .name = {'C','O','M','P','I','L','E','R'}
};


// List of instructions along with their hex values and argument counts
Instruction instructions[] = {
        {"LOAD_VAL", LOAD_VAL, 1},
        {"READ_VAR", READ_VAR, 1},
        {"STORE_VAR", STORE_VAR, 1},
        {"ADD", ADD, 0},
        {"SUB", SUB, 0},
        {"MUL", MUL, 0},
        {"DIV", DIV, 0},
        {"MOD", MOD, 0},
        {"JMP", JMP, 1},
        {"JMP_IF_ZERO", JMP_IF_ZERO, 1},
        {"JMP_IF_TRUE", JMP_IF_TRUE, 1},
        {"EQ", EQ, 0},
        {"NEQ", NEQ, 0},
        {"GT", GT, 0},
        {"LT", LT, 0},
        {"GTE", GTE, 0},
        {"LTE", LTE, 0},
        {"PRINT_VAL", PRINT_VAL, 0},
        {"INPUT_VAL", INPUT_VAL, 0},
        {"HALT", HALT, 0},
        {"LOAD_STR", LOAD_STR, 1},
        {"PRINT_STR", PRINT_STR, 0},
        {"INPUT_STR", INPUT_STR, 0},
        {"STR_LEN", STR_LEN, 0},
        {"CONCAT", CONCAT, 0},
        {"GET_CHAR", GET_CHAR, 0},
        {"SET_CHAR", SET_CHAR, 0},
        {"STR_CMP", STR_CMP, 0},
        {NULL, -1, 0} // Sentinel value to mark the end of the list
};

void int_to_big_endian(int num, uint8_t *buffer) {
    buffer[0] = (num >> 24) & 0xFF;
    buffer[1] = (num >> 16) & 0xFF;
    buffer[2] = (num >> 8) & 0xFF;
    buffer[3] = num & 0xFF;
}

// Function to parse a line and write its hex value along with arguments to a binary file
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

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is passed
    if (argc != 3) {
        printf("Usage: %s <input_filename> <output_filename>\n", argv[0]);
        return 1;
    }

    // Open the input file
    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open the output binary file
    FILE *outputFile = fopen(argv[2], "wb");
    if (outputFile == NULL) {
        printf("Error opening output binary file.\n");
        fclose(inputFile);
        return 1;
    }

    // Write the header to the output binary file
    fwrite(&header, sizeof(header), 1, outputFile);

    char line[MAX_LINE_LENGTH]; // Buffer to hold each line

    // Read each line from the input file and parse it
    while (fgets(line, sizeof(line), inputFile)) {
        // Remove trailing newline character if present
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        parseLine(outputFile, line); // Parse and write the hex value of the line to the binary file
    }

    // Determine the size of the output file
    fseek(outputFile, 0, SEEK_END);
    unsigned int fileSize = ftell(outputFile);
    rewind(outputFile);

    // Update the size in the header to reflect the actual file size minus the header size
    uint8_t sizeBytes[4];
    int_to_big_endian(fileSize - 24, sizeBytes);
    memcpy(&header.size, sizeBytes, sizeof(header.size));

    // Seek back to the beginning of the file and write the updated header
    rewind(outputFile);
    fwrite(&header, sizeof(header), 1, outputFile);

    fclose(inputFile); // Close the input file
    fclose(outputFile); // Close the output binary file
    return 0;
}


