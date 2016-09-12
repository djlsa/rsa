/*
 ============================================================================
 Name        : rsa8.c
 Author      : David Salsinha
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "util.h"

#define	E	163L	/* chave publica */
#define	N	221L	/* modulo */
#define	D	139L	/* chave privada */

int main(int argc, char **argv) {
	char comando;
	unsigned long e_d;
	if (argc == 2) {
		comando = argv[1][0];
		if (comando == 'c' || comando == 'd') {
			/* utiliza-se a chave publica ou privada dependendo do argumento */
			e_d = comando == 'c' ? E : D;
			int caractere;
			/* percorrem-se todos os caracteres em stdin */
			while ((caractere = fgetc(stdin)) != EOF) {
				/* codifica-se ou descodifica-se e põe-se resultado em output */
				printf("%c", rsa(N, e_d, caractere));
			}
			return EXIT_SUCCESS;
		}
	}
	printf("Modo de uso: rsa8 c|d < texto.txt > texto.cif");
	return EXIT_FAILURE;
}
