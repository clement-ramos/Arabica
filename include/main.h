#ifndef main_h
#define main_h

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "../include/parser.h"

#define MAX_LINE_LENGTH 256

// Structure to store the header of the binary file
struct {
    char magic[4];
    unsigned int size;
    char name[16];
} header = {
        .magic = {'C', 'O', 'D', 'E'},
        .size = 0,
        .name = {'C', 'O', 'M', 'P', 'I', 'L', 'E', 'R'}
};

/**
 * Main function of the program.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of strings containing the command-line arguments.
 *             The first argument should be the input filename, and the second argument should be the output filename.
 * @return 0 if the program executed successfully, 1 otherwise.
 */
int main(int argc, char *argv[]);

#endif