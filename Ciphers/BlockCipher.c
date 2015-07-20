/* BlockCipher.c - Written by Xenonstory on July 20, 2015    *
 * An implementation of a generic block cipher               */

#include "BlockCipher.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// TODO: Document the function
BinStr ECBencrypt(BinStr msg, BlockCipher cipher) {
    // TODO: Write the function
    return msg;
}

// See BlockCipher.h for details
BinStr BlockEncrypt(BinStr msg, BlockCipher cipher) {
    assert(msg != NULL && cipher != NULL);
    if(strcmp(cipher->encryptionMode, "ECB") == 0) {
        return ECBencrypt(msg, cipher);
    } else {
        return NULL; // TODO: Throw an error instead of returning NULL
    }
}
