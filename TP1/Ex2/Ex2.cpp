/*Question n° 2
Ouvrir le fichier « source.txt » en lecture, et un fichier que vous nommerez « dest1.txt » en
écriture, puis copier chaque caractère du fichier source dans le fichier de destination.
Refermez le fichier*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(){
    FILE* fichier1 = fopen("source.txt", "r");
    FILE* fichier2 = fopen("dest1.txt", "w");
    
    for (int sauve = 0; sauve != EOF; sauve = getc(fichier1)) {
        if (sauve == 0) sauve = getc(fichier1);
        putc(sauve, fichier2);
    }

    fclose(fichier1);
    fclose(fichier2);

    return 0;
}