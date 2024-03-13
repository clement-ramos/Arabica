//
// Created by Clément² on 13/03/2024. (Pas elie trop nul)
//

#include "../include/main.h"


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


