/*Question n° 3
Ouvrir le fichier « source.txt » en lecture, et un fichier que vous nommerez « dest2.txt » en
écriture, puis vous copier chaque caractère du fichier source dans le fichier de destination
mais sans copier la lettre ‘a’ dès que vous la trouverez dans le fichier source.
Refermez le fichier.*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    FILE* fichier1 = fopen("source.txt", "r");

    if (fichier1 == NULL) {
        printf("Impossible d'ouvrir le fichier source.txt.\n");
        return 1;
    }

    FILE* fichier2 = fopen("dest2.txt", "w");

    if (fichier2 == NULL) {
        printf("Impossible d'ouvrir le fichier dest2.txt.\n");
        fclose(fichier1);
        return 1;
    }

    for (int sauve = getc(fichier1); sauve != EOF; sauve = getc(fichier1)) {
        if (sauve != 'a') {
            putc(sauve, fichier2);
        }
    }

    fclose(fichier1);
    fclose(fichier2);

    return 0;
}