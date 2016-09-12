/*
 ============================================================================
 Name        : rsa_d.c
 Author      : David Salsinha
 ============================================================================
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//#include "util.h"

#define	E	163L	/* chave publica */
#define	N	221L	/* modulo */

int _main(void) {
	unsigned long p, q, phi_N, d;

	/* inicia-se a pesquisa pelo valor de P no valor inteiro da raiz de N */
	p = floorl(sqrtl(N));
	/* caso seja par, decrementa-se para percorrer apenas os impares */
	if (p % 2 == 0)
		p--;
	/* faz-se a busca em todos os impares entre raiz de N e 3 (exclusive) */
	for (; p > 3; p -= 2) {
		/* se N for divisivel pelo valor atual de P e este for um numero primo
		 * entao será esse o valor correto
		 */
		//if (N % p == 0 && isprime(p))
			break;
	}
	/* se P chegar ao valor 3, testa-se esse valor e 2 porque tambem é primo */
	if (p == 3 && N % p != 0 && N % --p != 0) {
		printf("Nao foi possivel determinar p");
		return EXIT_FAILURE;
	}
	/* como N = P * Q então Q = N / P */
	q = N / p;
	/* tendo os valores de P e Q é possivel calcular Phi(N) = (P - 1)*(Q - 1) */
	phi_N = (p - 1) * (q - 1);

	/* inicia-se agora a busca brute-force para encontrar a chave privada */
	d = 2;
	/* primeiro testa-se se é 2 */
	if (E * d % phi_N != 1) {
		/* em seguida percorre-se de 3 até infinito, todos os valores impares */
		for (d = 3;; d += 2) {
			/* testa-se se o D atual é inverso multiplicativo de E mod Phi */
			if (E * d % phi_N == 1)
				break;
		}
	}
	printf("e=%lu, n=%lu, p=%lu, q=%lu, phi(n)=%lu, d=%lu", E, N, p, q,phi_N,d);
	return EXIT_SUCCESS;
}
