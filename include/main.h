//
// Created by Clément² on 13/03/2024. (Pas elie trop nul)
//

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

#endif