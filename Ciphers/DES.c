/* DES.c - Written by Xenonstory on June 23, 2015      *
 * An implementation of the Data Encryption Standard   */

#include "DES.h"
#include <assert.h>
#include <stdlib.h>

// See DES.h for details
BinStr DESencrypt(BinStr msg, BinStr key) {
	assert(msg != NULL && key != NULLi && key->length = 64);
	return;
}

// See DES.h for details
BinStr DESdecrypt(BinStr cip, BinStr key) {
	assert(cip != NULL && key != NULL);
	return;
}

// DESencryptBlock(BinStr block, BinStr key) encrypts the given 64 bit block
//   and 64 bit key using the DES protocol.
// requires: block and key are valid BinStrs, block->length = key->length = 64
BinStr DESencryptBlock(BinStr block, BinStr key) {
	assert(block != NULL && key != NULL && 
	       block->length == 64 && key->length == 64);
}
