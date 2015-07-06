/* DES.c - Written by Xenonstory on June 24, 2015    *
 * An implementation of the Data Encryption Standard */

#include "DES.h"
#include <assert.h>
#include <stdlib.h>

int mBitPermutation[] = {58, 50, 42, 34, 26, 18, 10, 2,
                        60, 52, 44, 36, 28, 20, 12, 4,
                        62, 54, 46, 38, 30, 22, 14, 6,
                        64, 56, 48, 40, 32, 24, 16, 8,
                        57, 49, 41, 33, 25, 17,  9, 1,
                        59, 51, 43, 35, 27, 19, 11, 3,
                        61, 53, 45, 37, 29, 21, 13, 5,
                        63, 55, 47, 39, 31, 23, 15, 7};

int eBitPermutation[] = {32,  1,  2,  3,  4,  5,
		          4,  5,  6,  7,  8,  9,
	 	          8,  9, 10, 11, 12, 13,
		         12, 13, 14, 15, 16, 17,
                         16, 17, 18, 19, 20, 21,
                         20, 21, 22, 23, 24, 25,
                         24, 25, 26, 27, 28, 29,
                         28, 29, 30, 31, 32,  1};

int pBitPermutation[] = {16,  7, 20, 21, 29, 12, 28, 17,
                          1, 15, 23, 26,  5, 18, 31, 10,
                          2,  8, 24, 14, 32, 27,  3,  9,
                         19, 13, 30,  6, 22, 11,  4, 25};

// initialPermutation(block) returns a new BinStr in the form of the initial
//   permutation for the DES cipher
// effects: allocates memory to a new BinStr
// requires: block is a valid BinStr and block->length == DES_BLOCK_SIZE
BinStr initialPermutation(BinStr block) {
	assert(block != NULL && block->length == DES_BLOCK_SIZE);
	BinStr new = empty_BinStr(DES_BLOCK_SIZE);
	for(int i = 0; i < DES_BLOCK_SIZE; i++) {
		new->bits[i] = block->bits[mBitPermutation[i]];
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
                new->bits[mBitPermutation[i]] = block->bits[i];
        }
        return new;
}

// ePermutation(R) returns a new BinStr that expands the given right block
//   using the DES E-bit selection.
// effects: allocates memory to a new BinStr
// requires: R is a valid BinStr and R->length == DES_BLOCK_SIZE / 2
BinStr ePermutation(BinStr R) {
	assert(R != NULL && R->length == DES_BLOCK_SIZE / 2);
	BinStr new = empty_BinStr(DES_ROUND_KEY_SIZE);
	for(int i = 0; i < DES_BLOCK_SIZE; i++) {
		new->bits[i] = R->bits[eBitPermutation[i]];
	}
	return new;
}

// pPermutation(R) returns a new BinStr that permutates the given right
//   block after being processed through the S boxes.
// effects: allocates memory to a new BinStr
// requires: R is a valid BinStr and R->length == DES_BLOCK_SIZE / 2
BinStr pPermutation(BinStr R) {
	assert(R != NULL && R->length == DES_BLOCK_SIZE / 2);
	BinStr new = empty_BinStr(DES_BLOCK_SIZE);
	for(int i = 0; i < DES_BLOCK_SIZE / 2; i++) {
		new->bits[i] = R->bits[pBitPermutation[i]];
	}
	return new;
}

// blockCipher(block, key) returns a new BinStr that is the evaluation of
//   the DES block cipher applied to R using the given key
// effects: allocates memory to a new BinStr
// requires: block is a valid BinStr and block->length == DES_BLOCK_SIZE / 2
//           and key is a valid BinStr and key->length = DES_ROUND_KEY_SIZE
BinStr blockCipher(BinStr block, BinStr key) {
	assert(block != NULL && block->length == DES_BLOCK_SIZE / 2
	       && key != NULL && key->length == DES_ROUND_KEY_SIZE);	
	// Start by ePermutating the block and XOR'ing with the key
	BinStr new = ePermutation(block);
	new = replace(new, XOR(new, key));
	// TODO: Finish blockCipher
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
