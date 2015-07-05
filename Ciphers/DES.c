/* DES.c - Written by Xenonstory on June 24, 2015    *
 * An implementation of the Data Encryption Standard */

#include "DES.h"
#include <assert.h>
#include <stdlib.h>

int msgPermutation[] = {58, 50, 42, 34, 26, 18, 10, 2,
                        60, 52, 44, 36, 28, 20, 12, 4,
                        62, 54, 46, 38, 30, 22, 14, 6,
                        64, 56, 48, 40, 32, 24, 16, 8,
                        57, 49, 41, 33, 25, 17,  9, 1,
                        59, 51, 43, 35, 27, 19, 11, 3,
                        61, 53, 45, 37, 29, 21, 13, 5,
                        63, 55, 47, 39, 31, 23, 15, 7};

int eBitSelection[] = {32,  1,  2,  3,  4,  5,
		        4,  5,  6,  7,  8,  9,
			8,  9, 10, 11, 12, 13,
		       12, 13, 14, 15, 16, 17,
                       16, 17, 18, 19, 20, 21,
                       20, 21, 22, 23, 24, 25,
                       24, 25, 26, 27, 28, 29,
                       28, 29, 30, 31, 32,  1};

// initialPermutation(block) returns a new BinStr in the form of the initial
//   permutation for the DES cipher
// effects: allocates memory to a new BinStr
// requires: block is a valid BinStr and block->length == DES_BLOCK_SIZE
BinStr initialPermutation(BinStr block) {
	assert(block != NULL && block->length == DES_BLOCK_SIZE);
	BinStr new = empty_BinStr(DES_BLOCK_SIZE);
	for(int i = 0; i < DES_BLOCK_SIZE; i++) {
		new->bits[i] = block->bits[msgPermutation[i]];
	}
	return new;
}

// finalPermutation(block) returns a new BinStr in the form of the final
//   permutation for the DES cipher
// effects: allocates memory to a new BinStr
// requires: block is a valid BinStr and block->length == DES_BLOCK_SIZE
BinStr finalPermutation(BinStr block) {
        assert(block != NULL && block->length == DES_BLOCK_SIZE);
        BinStr new = empty_BinStr(DES_BLOCK_SIZE);
        for(int i = 0; i < DES_BLOCK_SIZE; i++) {
                new->bits[msgPermutation[i]] = block->bits[i];
        }
        return new;
}

// rPermutation(R) returns a new BinStr that expands the given right block
//   using the DES E-bit selection.
// effects: allocates memory to a new BinStr
// requires: block is a valid BinStr and block->length == DES_BLOCK_SIZE / 2
BinStr rPermutation(BinStr R) {
	assert(R != NULL && R->length == DES_BLOCK_SIZE / 2);
	BinStr new = empty_BinStr(DES_BLOCK_SIZE);
	for(int i = 0; i < DES_BLOCK_SIZE; i++) {
		new->bits[i] = R->bits[eBitPermutation[i]];
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
