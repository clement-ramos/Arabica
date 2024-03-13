#include <stdio.h>

int main() {
    struct {
        char magic[4];
        unsigned int size;
        char name[16];
    } header = {
        .magic = {'C', 'O', 'D', 'E'}, 
        .size = 0, 
        .name = {'C','O','M','P','I','L','E','R'}
    };

    ((unsigned char * )(&header.size))[3] = 0x0c;

    // unsigned char data[] = {0x01, 0x00, 0x00, 0x00, 0x03, 0x01, 0x00, 0x00, 0x00, 0x04, 0x04, 0x12};

    FILE *fichier = fopen("code.bin", "wb");
    if (fichier != NULL) {
        fwrite(&header, sizeof(header), 1, fichier);
        // fwrite(data, sizeof(data), 1, fichier);
        fclose(fichier);
    } else {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }
    return 0;
}