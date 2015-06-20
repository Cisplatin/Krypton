/* RC4.c - Written by Xenonstory on June 8, 2015 *
 * An implementation of the RC4 PRNG                    */

#include "RC4.h"
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
		BinStr byte = getByte(key, i % bytes(key));
		int a = toDecimal(byte);
		destroy_BinStr(byte);
                j = (j + S[i] + a) % 256;
		int buffer = S[i];
		S[i] = S[j];
		S[j] = buffer;
	}

	// End with the pseudo-random generation algorithm
	int k = 0, f = 0;
	BinStr new = create_BinStr("", 0);
	for(int m = 0; m < 1 + n / 8; m++) {
		k = (k + 1) % 256;
		j = (j + S[k]) % 256;
		int buffer = S[k];
		S[k] = S[j];
		S[j] = buffer;
		BinStr app = int_to_BinStr(S[(S[k] + S[j]) % 256]);
                new = replace(new, append(new, app));
		destroy_BinStr(app);
        }
        new = replace(new, cut(new, n));
	free(S);
	return new;
}
