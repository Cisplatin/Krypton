/* RC4.c - Written by Xenonstory on June 8, 2015 *
 * An implementation of the RC4 PRNG                    */

#include "OneTimePad.h"
#include <assert.h>
#include <stdlib.h>

// See OneTimePad.h for details
BinStr RC4(BinStr key, int n) {
	// Start with the key-scheduling algorithm
	int *S = malloc(sizeof(int) * 256);
	for(int i = 0; i < 255; i++) {
		S[i] = i;
	}
	int j = 0;
	for(int i = 0; i < 255; i++) {
		j = (j + S[i] + toDecimal(key->getByte(i % bytes(key)))) % 256;
		int buffer = S[i];
		S[i] = S[j];
		S[j] = buffer;
	}

	// End with the pseudo-random generation algorithm
	int k = 0, f = 0;
	BinStr new = empty_BinStr(n);
	for(int m = 0; m < n; m++) {
		k = (k + 1) % 256;
		j = (j + S[k]) % 256;
		int buffer = S[k];
		S[k] = S[j];
		S[j] = buffer;
		app = S[(S[i] + S[j]) % 256];
	}
	return new;
}
