/*Exercice 2 : 
Ecrire un programme C permettant d’afficher le contenu d’un fichier créé préalablement.*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	FILE* fichier = fopen("fichier.txt", "r");

	if (fichier == NULL) {
		printf("Erreur : impossible de lire le fichier.\n");
		return 1;
	}

	for (int c = 0; c != EOF; c = getc(fichier)) {
		printf("%c", c);
	}

	fclose(fichier);

	return 0;
}