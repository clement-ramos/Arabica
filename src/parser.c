#include <stdio.h>
#include <string.h>

#define MAX_LINES 100 // Nombre maximum de lignes que vous pouvez lire
#define MAX_LINE_LENGTH 256 // Longueur maximale de chaque ligne

int readLinesFromFile(const char *fileName, char lines[MAX_LINES][MAX_LINE_LENGTH]) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Erreur en ouvrant le fichier");
        return -1;
    }

    int count = 0;
    while (fgets(lines[count], MAX_LINE_LENGTH, file) && count < MAX_LINES) {
        // Supprime le saut de ligne à la fin si présent
        lines[count][strcspn(lines[count], "\n")] = 0;
        count++;
    }

    fclose(file);
    return count;
}
