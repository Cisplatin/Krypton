/* BlockCipher.c - Written by Xenonstory on July 17, 2015 *
 * An implementation of a generic block cipher            */

#include "BlockCipher.h"
#include <assert.h>
#include <stdlib.h>

// See BlockCipher.h for details
BinStr BlockEncrypt(BinStr msg, BinStr key, BinStr (*cipher)(BinStr, BinStr),
                     char *mode) {
	assert(msg != NULL && key != NULL);
    // TODO: Actually write the function
    return msg;
}

// See BlockCipher.h for details
BinStr BlockDecrypt(BinStr cip, BinStr key, BinStr (*cipher)(BinStr, BinStr),
                     char *mode) {
	assert(cip != NULL && key != NULL);
	// TODO: Actually write the function
    return cip;
}
