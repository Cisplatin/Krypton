/* AES.c - Written by Xenonstory on June 24, 2015        *
 * An implementation of the Advanced Encryption Standard */

#include "AES.h"
#include <assert.h>
#include <stdlib.h>

const int AES_BLOCK_SIZE = 128;

// AESencrypt(block, key) encrypts the given block using the given key
//   using the AES cipher.
// requires: block and key are valid BinStrs, block->length == AES_BLOCK_SIZE,
//           key->length == a valid AES key length
BinStr AESencrypt(BinStr block, BinStr key) {
}

// See AES.h for details
BlockCipher AES_initialize(BinStr key, char* mode) {
    assert(key != NULL && mode != NULL && key->length == DES_KEY_SIZE);
    BlockCipher AES = malloc(sizeof(struct blockcipher));
    AES->key = key;
    AES->encryptionMode = mode;
    AES->blockSize = AES_BLOCK_SIZE;
    AES->encrypt = AESencrypt;
    AES->decrypt = AESdecrypt;
    return AES;
}

// See AES.h for details
void AES_destroy(BlockCipher AES) {
    free(AES);
}
                                                                                                                                                                                             339,1         Bot


