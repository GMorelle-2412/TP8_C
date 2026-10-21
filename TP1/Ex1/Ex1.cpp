/*Question n° 1
Avec une application écrite en C, vous allez ouvrir le fichier « source.txt » en lecture, et
afficher son contenu caractère par caractère à l’écran à l’aide de la fonction getc.
Refermez ensuite le fichier.*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(){
	FILE* fichier = fopen("source.txt", "r");

	if (fichier == NULL) {
		printf("Impossible d'ouvrir le fichier source.txt.\n");
		return 1;
	}

	for (int sauve = 0; sauve != EOF; sauve = getc(fichier)) {
		printf("%c", sauve);
	}

	fclose(fichier);

	return 0;
}