/*Exercice 3 : 
Exercice extrait du document suivant : 
http://chamilo2.grenet.fr/inp/courses/ESISAR3AMCS313/document/TP/CS313-314-TP5-sujet.pdf 

Ecrire un programme qui permet de lire dans un fichier des entiers et de les trier avant de les 
enregistrer dans un autre fichier. Vous devez écrire les fonctions suivantes :  

1. int lireDonnees(char * nomFichier, int * T) qui lit les données dans le fichier nommé nomFichier 
des entiers, puis les stocke dans un tableau T. La valeur de retour est le nombre d’entiers qui ont été 
lus (c’est-à-dire le nombre d’éléments du tableau).  

2. void afficherTableau(int * T, int nb) qui affiche le contenu du tableau T qui comprend nb éléments.  

3. void triABulles(int * T, int nb) qui trie le tableau T de nb éléments avec la méthode du tri à bulles et 
qui retourne le tableau trié. 

4. void enregistrerDonnees(char * nomFichier, int * T, int nb) qui enregistre les nb valeurs du tableau 
T dans le fichier nommé nomFichier.  

Pour tester vos fonctions, vous réaliserez un programme principal. Vous choisirez le nom du fichier 
pour la lecture des données ainsi que celui pour l’enregistrement des valeurs (vous pouvez mettre 
ces noms en dur dans votre code).*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

int lireDonnees(char* nomFichier, int* T) {
	FILE* fichier_source = fopen(nomFichier, "r");

	int max = 0;

	while (fscanf(fichier_source, "%d", &T[max]) == 1) {
		max++;
	}

	fclose(fichier_source);

	return max;
}

void afficherTableau(int* T, int nb) {
	for (int i = 0; i < nb; i++) {
		printf("%d",T[i]);
	}

	printf("\n");
}

void triABulles(int* T, int nb) {
	int sauve = 0;

	for (int i = 0; i < nb; i++) {
		for (int j = 0; j < nb-1; j++) {
			if (T[j] > T[j + 1]) {
				sauve = T[j+ 1];
				T[j + 1] = T[j];
				T[j] = sauve;
			}
		}
	}
}

void enregistrerDonnees(char* nomFichier, int* T, int nb) {
	FILE* fichier_suivant = fopen(nomFichier, "w");

	for (int i = 0; i < nb; i++) {
		fprintf(fichier_suivant, "%d", T[i]);
	}
	fclose(fichier_suivant);
}


int main() {
	int T[1000];

	char nomFichier_source[255] = "fichier_source.txt";
	char nomFichier_suivant[255] = "fichier_suivant.txt";

	int nb = lireDonnees(nomFichier_source, T);
	
	afficherTableau(T, nb);
	
	triABulles(T, nb);

	enregistrerDonnees(nomFichier_suivant, T, nb);

	return 0;
}