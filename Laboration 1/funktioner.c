//
//  funktioner.c
//  Laboration 1. Final
//
//  Created by Robin Johansson Speelgren on 2021-12-05.
//

#include "header.h"

// Funktioner
void printMeny() {

	// Reserverar hundra platser i vektor[]
	double vektor[100];
	// counter = "flagga" för att inte kunna göra val 3 och 4 innan 1 och 2.
	int counter = 1;
	int input = -1;

	printf("\n");
	printf(" | ---------------------------------------------- |\n");
	printf(" |-------- [ VÄLJ PROGRAM ATT AKTIVERA ] ---------|\n");
	printf(" |------------------------------------------------|\n");
	printf(" |----------------- [ PROGRAM: ] -----------------|\n");
	printf(" |------------------------------------------------|\n");
	printf(" |------------------------------------------------|\n");
	printf(" | 1) [ SLUMPGENERATOR ] -------------------------|\n");
	printf(" | 2) [ SORTERA SLUMPGENERATOR ] -----------------|\n");
	printf(" | 3) [ MEDEL, MEDIAN, MIN-, & MAXVÄRDE ] --------|\n");
	printf(" | 4) [ BINÄRSÖKNING ] ---------------------------|\n");
	printf(" |------------------------------------------------|\n");
	printf(" |------------------------------------------------|\n");
	printf(" |------------------------------------------------|\n");
	printf(" |------------------------------------------------|\n");
	printf(" | 0) [ AVSLUTA PROGRAMMET ] ---------------------|\n");
	printf(" |------------------------------------------------|\n");
	printf(" | ---------------------------------------------- |\n");
	printf("\n");
	printf(" [ ANGE INPUT: ");
	scanf("%i", &input);
	printf("\n");

	while(input != 0) {

		if(input == 1 && counter == 1) {

			slumpGen(vektor);
			counter++;
		} else if(input == 2 && counter == 2) {

			sortGen(vektor);
			counter++;
		} else if(input == 3 && counter > 2) {

			medMediMaxMin(vektor);
			counter++;
		} else if(input == 4 && counter > 2) {

			binSok(vektor);
			counter++;
		} if(counter == 5) {

			break;
		}

		printf("\n");
		printf(" [ ANGE INPUT: ");
		scanf("%i", &input);
		printf("\n");
	}
}

void slumpGen(double vektor[]) {

	printf(" | --------------- [ PROGRAMVAL ] --------------- |\n");
	printf(" | 1) [ SLUMPGENERATOR ] ------------------------ |\n");
	printf(" | ---------------------------------------------- |\n");
	printf("\n");

	// (int) omvandla seed för rand() till signed int (?).
	srand((int)time(NULL));

	for(int i = 0; i < 100; i++) {

		vektor[i] = rand() % 801 + 100;
		printf("%5.lf", vektor[i]);

		if((i + 1) % 10 == 0)
			printf("\n");
	}
}

void sortGen(double vektor[]) {

	printf(" | --------------- [ PROGRAMVAL ] --------------- |\n");
	printf(" | 2) [ SORTERA SLUMPGENERATOR ] ---------------- |\n");
	printf(" | ---------------------------------------------- |\n");
	printf("\n");

	for(int i = 0; i < 100; i++) {

		for(int j = 99; j > i; j--)
			if(vektor[j - 1] > vektor[j]) {

				int slask = vektor[j - 1];
				vektor[j - 1] = vektor[j];
				vektor[j] = slask;

			}

			printf("%5.lf", vektor[i]);

			if((i + 1) % 10 == 0)
				printf("\n");
		}
}

void medMediMaxMin(double vektor[]) {

	double sum = 0;

	// Loop för att summera talen från index 0 till 99 i sum
	for(int i = 0; i < 100; i++) {

		sum += vektor[i];
	}

	double medel = (sum / 100);
	double median = ((vektor[49] + vektor[50]) / 2);
	double min = vektor[0];
	double max = vektor[99];

	printf(" | --------------- [ PROGRAMVAL ] --------------- |\n");
	printf(" | 3) [ MEDEL, MEDIAN, MIN-, & MAXVÄRDE ] ------- |\n");
	printf(" | ---------------------------------------------- |\n");
	printf("\n");
	printf(" | ---------------------------------------------- |\n");
	printf(" | ---------- [ MEDELVÄRDET: %7.2lf ] ---------- |\n", medel);
	printf(" | ---------------------------------------------- |\n");
	printf(" | ---------- [ MEDIANVÄRDET: %4.2lf ] ---------- |\n", median);
	printf(" | ---------------------------------------------- |\n");
	printf(" | ---------- [ MINIMUMVÄRDET: %5.lf ] ---------- |\n", min);
	printf(" | ---------------------------------------------- |\n");
	printf(" | ---------- [ MAXVÄRDET: %9.lf ] ---------- |\n", max);
	printf(" | ---------------------------------------------- |\n");
}

void binSok(double vektor[]) {

	int high = 100;
	int low = 0;
	int mid = ((low + high) / 2);
	int tal;

	printf(" | --------------- [ PROGRAMVAL ] --------------- |\n");
	printf(" | 4) [ BINÄRSÖKNING ] -------------------------- |\n");
	printf(" | ---------------------------------------------- |\n");
	printf("\n");
	printf(" [ SÖK EFTER ETT TAL I SLUMPGENERATOR: ");
	scanf("%i", &tal);
	printf("\n");


	while((high-low) > 1) {

		mid = ((low+high) / 2);
		if(tal >= vektor[mid])
			low = mid;

		else
			high = mid;
	}

	if(tal==vektor[low]) {

		int plats = (low + 1);
		int rad = ((low / 10) + 1);
		int kolumn = ((low % 10) + 1);


		printf(" | ---------------------------------------------- |\n");
		printf(" | ------ [ TAL FUNNET VID POSITION %4i ] ------ |\n", plats);
		printf(" | ------ [ TAL FUNNET VID RAD %9i ] ------ |\n", rad);
		printf(" | ------ [ TAL FUNNET VID KOLUMN %6i ] ------ |\n", kolumn);
		printf(" | ---------------------------------------------- |\n");
		printf("\n");
	} else {

		printf(" | ---------------------------------------------- |\n");
		printf(" | ----- [ TAL FINNS EJ I SLUMPGENERATORN ] ----- |\n");
		printf(" | ---------------------------------------------- |\n");
		printf("\n");
	}
}
