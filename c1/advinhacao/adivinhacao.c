/*
 * adivinhacao.c
 *
 *  Created on: 7 de dez de 2015
 *      Author: saocmest
 *
 *      gcc adivinhacao.c -o adivinhacao.exe
 */

// A diretiva include permite incluir bibliotecas
#include <stdio.h>

// A diretiva define permite definir uma constante
#define TIMES_TO_PLAY 5

int main() {

	int secretNumber;
	int userSelection;
	int i;

	// print the header game
	printf("******************************************************\n");
	printf("******************** Chute Certo! ********************\n");
	printf("******************************************************\n");

	secretNumber = 42;

	for (i = 1; i <= TIMES_TO_PLAY; i++) {

		printf("\n\nTentativa %d de %d!", i, TIMES_TO_PLAY);
		printf("\nQual � o seu chute?");

		fflush(stdout);
		scanf("%d", &userSelection);

		printf("\nO numero %d � o chute.", userSelection);

		if (userSelection == secretNumber) {

			printf("\nVoc� acertou!");
			break;

		} else {

			printf("\nN�o foi dessa vez!");

			if (userSelection > secretNumber)
				printf("\nSeu chute foi maior que o n�mero secreto!");
			else
				printf("\nSeu chute foi menor que o n�mero secreto!");
		}

	}

	printf("\nFim de Jogo!");

	return 0;
}
