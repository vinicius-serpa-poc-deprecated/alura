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
#include <stdlib.h>
#include <time.h>

// A diretiva define permite definir uma constante
#define TIMES_TO_PLAY 7

int main() {

	// Declara variaveis mas nao limpa o espaco de armazenamento anterior
	// Tipos de dados num�ricos: short(2 bytes), int(4 bytes/32 bits, 2 elevado a 32), long(8 bytes, 64 bits), float(4 bytes), double(8 bytes)
	int secretNumber;
	int userSelection;
	int i;
	int acertou;
	int maior;
	double pontos;
	int level;
	int times;

	// print the header game
	printf("\n\n");
	printf("          P  /_\\  P                              \n");
	printf("         /_\\_|_|_/_\\                            \n");
	printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
	printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinha��o! \n");
	printf("    |\" \"  |  |_|  |\"  \" |                     \n");
	printf("    |_____| ' _ ' |_____|                         \n");
	printf("          \\__|_|__/                              \n");
	printf("\n\n");

	// Timestamp � usado como semente para que rand() retorne randomicos diferentes a cada chamada.
	// Resto da divis�o inteira de 100 � um n�mero entre 0 e 99.
	srand(time(0));
	secretNumber = rand() % 100;
	pontos = 1000;

	printf("Escolha o n�vel de dificuldade\n");
	printf("(1) F�cil (2) M�dio (3) Dif�cil\n\n");
	printf("Escolha: ");
	fflush(stdout);
	scanf("%d", &level);

	switch (level) {
	case 1:
		times = 7;
		break;
	case 2:
		times = 5;
		break;
	default:
		times = 3;
		break;
	}

	printf("\nChute um n�mero de 0 a 99!");

	for (i = 1; i <= times; i++) {

		printf("\n\nTentativa %d de %d!", i, times);
		printf("\nQual � o seu chute?");

		fflush(stdout);
		scanf("%d", &userSelection);

		if (userSelection < 0) {
			printf("\nVoc� n�o pode digitar n�meros negativos!");
			i--;
			continue;
		}

		acertou = userSelection == secretNumber;
		maior = userSelection > secretNumber;

		if (acertou) {
			break;
		} else if (maior) {
			printf("\nSeu chute foi maior que o n�mero secreto!");
		} else {
			printf("\nSeu chute foi menor que o n�mero secreto!");
		}

		// Converte (casting) 2 para double para a fun��o retornar um double
		pontos -= abs(userSelection - secretNumber) / (double) 2;
	}

	if (acertou) {
		printf("\n\n");
		printf("             OOOOOOOOOOO               \n");
		printf("         OOOOOOOOOOOOOOOOOOO           \n");
		printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
		printf("    OOOOOO      OOOOO      OOOOOO      \n");
		printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
		printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
		printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
		printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
		printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
		printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
		printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
		printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
		printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
		printf("         OOOOOO         OOOOOO         \n");
		printf("             OOOOOOOOOOOO              \n");
		printf("\nParab�ns! Voc� acertou!\n");
		printf("Voc� fez %.2f pontos. At� a pr�xima!\n\n", pontos);
		printf("\n\n");
	} else {
		printf("\n\n");
		printf("       \\|/ ____ \\|/    \n");
		printf("        @~/ ,. \\~@      \n");
		printf("       /_( \\__/ )_\\    \n");
		printf("          \\__U_/        \n");
		printf("\nVoc� perdeu! Tente novamente!\n\n");
		printf("\n\n");
	}

	// %.1f = imprime double com uma casa decimal
	printf("\nFim de Jogo! \nO n�mero secreto era: %d. \nPontos: %.1f", secretNumber, pontos);

	return 0;
}
