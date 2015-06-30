/* DES.c - Written by Xenonstory on June 24, 2015    *
 * An implementation of the Data Encryption Standard */

#include "DES.h"
#include <assert.h>
#include <stdlib.h>

int permutation[] = {58, 50, 42, 34, 26, 18, 10, 2,
                     60, 52, 44, 36, 28, 20, 12, 4,
                     62, 54, 46, 38, 30, 22, 14, 6,
                     64, 56, 48, 40, 32, 24, 16, 8,
                     57, 49, 41, 33, 25, 17,  9, 1,
                     59, 51, 43, 35, 27, 19, 11, 3,
                     61, 53, 45, 37, 29, 21, 13, 5,
                     63, 55, 47, 39, 31, 23, 15, 7};

// initialPermutation(block) returns a new BinStr in the form of the initial
//   permutation for the DES cipher
// effects: allocates memory to a new BinStr
// requires: block is a valid BinStr and block->length == DES_BLOCK_SIZE
BinStr initialPermutation(BinStr block) {
	assert(block != NULL && block->length == DES_BLOCK_SIZE);
	BinStr new = empty_BinStr(DES_BLOCK_SIZE);
	for(int i = 0; i < 64; i++) {
		new->bits[i] = block->bits[permutation[i]];
	}
	return new;
}

// finalPermutation(block) returns a new BinStr in the form of the final
//   permutation for the DES cipher
// effects: allocates memory to a new BinStr
// requires: block is a valid BinStr and block->length == DES_BLOCK_SIZE
BinStr initialPermutation(BinStr block) {
        assert(block != NULL && block->length == DES_BLOCK_SIZE);
        BinStr new = empty_BinStr(DES_BLOCK_SIZE);
        for(int i = 0; i < 64; i++) {
                new->bits[permutation[i]] = block->bits[i];
        }
        return new;
}

// See DES.h for details
BinStr DESencrypt(BinStr msg, BinStr key) {
	assert(msg != NULL && key != NULL && key->length == DES_KEY_SIZE);
	// TODO: Encrypt the message using DES
	return msg;
}

// See DES.h for details
BinStr DESdecrypt(BinStr cip, BinStr key) {
	assert(cip != NULL && key != NULL && key->length == DES_KEY_SIZE);
	// TODO: Decrypt the message using DES
	return cip;
}
