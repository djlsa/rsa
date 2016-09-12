/*
 ============================================================================
 Name        : util.h
 Author      : David Salsinha
 ============================================================================
 */

#ifndef RSA_SRC_UTIL_H_
#define RSA_SRC_UTIL_H_

#include <stdbool.h>
#include <stdio.h>

bool isprime(unsigned long a) {
	if (a <= 1)
		return false;
	unsigned long i = 2;
	/* testam-se todos os valores até raiz de A */
	while (i * i <= a) {
		/* se o valor atual for divisor inteiro então não é primo */
		if (a % i == 0)
			return false;
		i++;
	}
	return true;
}

/*
 * Exponenciação modular
 * C = B^k Mod M
 */
unsigned long mod_exp(b, k, m) {
	unsigned long c = 1, i;
	for (i = 1; i <= k; i++)
		c = (c * b) % m;
	return c;
}

/*
 * Função RSA
 * Retorna um caractere codificado ou descodificado
 * N: modulo
 * E_D: chave publica (E) ou chave privada (D)
 * M: caractere a codificar ou descodificar
 */
char rsa(unsigned long n, unsigned long e_d, int m) {
	/* intervalos de caracteres a ignorar */
	if (m < 32 || m > 252)
		return m;
	/* decrementa 32 ao caractere, efetua a exponenciacao modular e retorna o
	 * resultado somado a 32
	 */
	return (char) (32 + mod_exp(m - 32, e_d, n));
}

#endif /* RSA_SRC_UTIL_H_ */
