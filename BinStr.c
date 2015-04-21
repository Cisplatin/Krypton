/* BinStr.c - Written by Xenonstory on April 21, 2015 *
 * A structure used to store binary strings           */

#include "BinStr.h"
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

struct binstr {
	bool *bits;
	unsigned int length;
};

// see BinStr.h for details
BinStr create_BinStr(char *bits, unsigned int length) {
	assert(bits != NULL);
	BinStr new = malloc(sizeof(binstr));
	new->bits = malloc(sizeof(bool) * length);
	for(int i = 0; i < length; i++) {
		new->bits[i] = bits[i] - '0';
	}
	new->length = length;
	return new;
}

// see BinStr.h for details
void destroy_BinStr(BinStr str) {
	assert(str != NULL);
	free(str->bits);
	free(str);
	return;
}

// see BinStr.h for details
BinStr XOR(BinStr str1, BinStr str2) {
	assert(str1 != NULL && str2 != NULL && str1->length == str2->length);
	BinStr new = create_BinStr(str1->bits, str1->length);
	for(int i = 0; i < new->length; i++) {
		new->bits[i] = new->bits[i] ^ str2->bits[i];
	}
	return new;
}

