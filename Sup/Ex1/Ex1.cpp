/*Exercice 1 :  
Ecrire un programme C permettant de créer un fichier qui contiendra l’alphabet.*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	FILE* fichier = fopen("fichier.txt", "w");

	if (fichier == NULL) {
		printf("Erreur : impossible de creer le fichier.\n");
		return 1;
	}

	for (char c = 'a'; c <= 'z'; c++) {
		putc(c, fichier);
	}

	fclose(fichier);

	return 0;
}