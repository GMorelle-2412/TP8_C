/*Question n° 4
Ecrire une fonction ayant un pointeur de fichier en argument (pointeur sur un fichier qui sera
déjà ouvert dans le programme principal) et qui retournera un entier. Cette fonction aura pour
but de calculer et de retourner la taille du fichier (en octets).
Essayez votre fonction avec les trois fichiers utilisés (source.txt, dest1.txt,dest2.txt).
La fermeture du fichier se fera dans le programme principal.*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int calcule_taille_fichier(FILE* fichier) {
	int max = 0;

	while (getc(fichier) != EOF) max++;

	return max;
}

int main() {
	FILE* source = fopen("source.txt", "r");
	FILE* dest1 = fopen("dest1.txt", "r");
	FILE* dest2 = fopen("dest2.txt", "r");

	printf("Fichier source = %d\n", calcule_taille_fichier(source));
	printf("Fichier dest1 = %d\n", calcule_taille_fichier(dest1));
	printf("Fichier dest2 = %d\n", calcule_taille_fichier(dest2));

	fclose(source);
	fclose(dest1);
	fclose(dest2);

	return 0;
}