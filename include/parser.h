#ifndef ARABICA_PARSER_H
#define ARABICA_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define LOAD_VAL       0x01 // LOAD_VAL <valeur> : Empile une valeur numérique (int32) sur la pile. (4args, 0Pops)
#define READ_VAR       0x02 // READ_VAR <identifiant> : Empile la valeur de la variable spécifiée(uint8 pour l'ID de la variable). (1args, 0Pops)
#define STORE_VAR      0x03 // STORE_VAR <nom> : Stocke la valeur au sommet de la pile dans une variable. (1args, 1Pops)
#define ADD            0x04 // ADD : Additionne les deux valeurs au sommet de la pile. (0args, 2Pops)
#define SUB            0x05 // SUB : Soustrait la valeur au sommet de la pile par celle juste en dessous. (0args, 2Pops)
#define MUL            0x06 // MUL : Multiplie les deux valeurs au sommet de la pile. (0args, 2Pops)
#define DIV            0x07 // DIV : Divise la valeur juste en dessous par celle au sommet de la pile. (0args, 2Pops)
#define MOD            0x08 // MOD : Prend le modulo de la valeur juste en dessous par celle au sommet de la pile. (0args, 2Pops)
#define JMP            0x09 // JMP <offset> : Saute à l'instruction en se décalant de la valeur de l'offset (int32) (4args, 0Pops)
#define JMP_IF_ZERO    0x0A // JMP_IF_ZERO <offset> : Saute à l'instruction en se décalant de la valeur de l'offset (int32) si la valeur au sommet de la pile est 0. (4args, 1Pops)
#define JMP_IF_TRUE    0x0B // JMP_IF_TRUE <offset> : Saute à l'instruction en se décalant de la valeur de l'offset (int32) si la valeur au sommet de la pile est vraie. (4args, 1Pops)
#define EQ             0x0C // EQ : Empile 1 si les deux valeurs au sommet de la pile sont égales, 0 sinon. (0args, 2Pops)
#define NEQ            0x0D // NEQ : Empile 1 si les deux valeurs au sommet de la pile sont différentes, 0 sinon. (0args, 2Pops)
#define GT             0x0E // GT : Empile 1 si la valeur juste en dessous est plus grande que celle au sommet de la pile, 0 sinon. (0args, 2Pops)
#define LT             0x0F // LT : Empile 1 si la valeur juste en dessous est plus petite que celle au sommet de la pile, 0 sinon. (0args, 2Pops)
#define GTE            0x10 // GTE : Empile 1 si la valeur juste en dessous est plus grande ou égale à celle au sommet de la pile, 0 sinon. (0args, 2Pops)
#define LTE            0x11 // LTE : Empile 1 si la valeur juste en dessous est plus petite ou égale à celle au sommet de la pile, 0 sinon. (0args, 2Pops)
#define PRINT_VAL      0x12 // PRINT_VAL : Affiche la valeur au sommet de la pile. (0args, 1Pops)
#define INPUT_VAL      0x13 // INPUT_VAL : Demande à l'utilisateur de rentrer une valeur et l'empile sur la pile. (0args, 0Pops)
#define HALT           0x14 // HALT : Arrête l'exécution du programme. (0args, 0Pops)
#define LOAD_STR       0x15 // LOAD_STR <valeur> : Empile une chaîne de caractères sur la pile. (1args+var, 0Pops)
#define PRINT_STR      0x16 // PRINT_STR : Affiche la chaîne de caractères au sommet de la pile. (0args, 1Pops)
#define INPUT_STR      0x17 // INPUT_STR : Demande à l'utilisateur de rentrer une chaîne de caractères et l'empile sur la pile. (0args, 0Pops)
#define STR_LEN        0x18 // STR_LEN : Empile la longueur de la chaîne de caractères au sommet de la pile. (0args, 1Pops)
#define CONCAT         0x19 // CONCAT : Concatène les deux chaînes de caractères au sommet de la pile. (0args, 2Pops)
#define GET_CHAR       0x1A // GET_CHAR : Empile le caractère à l'index donné de la chaîne de caractères au sommet de la pile. (0args, 1Pops)
#define SET_CHAR       0x1B // SET_CHAR : Modifie le caractère à l'index donné de la chaîne de caractères au sommet de la pile. (3args, 0Pops)
#define STR_CMP        0x1C // STR_CMP : Empile 1 si les deux chaînes de caractères au sommet de la pile sont égales, 0 sinon. (0args, 2Pops)

// Structure to store instruction names and their hex values
typedef struct {
    char *name;
    int hexValue;
    int numArgs;
} Instruction;

/**
 * Parses a line of code and writes the corresponding binary representation to a file.
 *
 * @param binaryFile The file to write the binary representation to.
 * @param line The line of code to parse.
 */
void parseLine(FILE *binaryFile, char *line);

/**
 * Converts an integer to big endian byte order and stores it in a buffer.
 *
 * @param num The integer to convert.
 * @param buffer The buffer to store the converted bytes.
 */
void int_to_big_endian(int num, uint8_t *buffer);

#endif //ARABICA_PARSER_H