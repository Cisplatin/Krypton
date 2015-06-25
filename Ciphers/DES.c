/* DES.c - Written by Xenonstory on June 24, 2015    *
 * An implementation of the Data Encryption Standard */

#include "DES.h"
#include <assert.h>
#include <stdlib.h>

// See DES.h for details
BinStr DESencrypt(BinStr msg, BinStr key) {
	assert(msg != NULL && key != NULL && key->length == 64);
	// TODO: Encrypt the message using DES
	return msg;
}

// See DES.h for details
BinStr DESdecrypt(BinStr cip, BinStr key) {
	assert(cip != NULL && key != NULL && cip->length == key->length);
	// TODO: Decrypt the message using DES
	return cip;
}
