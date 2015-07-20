/* DES.h - Written by Xenonstory on June 24, 2015    *
 * An implementation of the Data Encryption Standard */      

#ifndef DES_H
#define DES_H

#include "../Structures/BinStr.h"
#include "BlockCipher.h"

// DESinitialize(key, mode) returns an instance of a block cipher ready for
//   decryption and encryption using the given key and mode
// requires: key != NULL, mode is a valid mode (ECB, etc.)
// effects: allocates memory to a new DES cipher
BinStr DES_initialize(BinStr key, char* mode);

// DESdestroy(cipher) destroys the given instance of the DES block cipher
// requires: cipher != NULL and cipher is a DES block cipher
// effects: frees memory used by the cipher
BinStr DES_destroy(BlockCipher DES);

// DESencrypt(block, key) encrypts the given message using the given key via the DES.
// requires: block and key are valid BinStr and block->length == DES_BLOCK_SIZE and
//           key->length == DES_KEY_SIZE
BinStr DESencrypt(BinStr block, BinStr key);

// DESdecrypt(block, key) decrypts the given cipher using the given key via the DES.
// requires: block and key are valid BinStr and block->length == DES_BLOCK_SIZE
//           and key->length == DES_KEY_SIZE
BinStr DESdecrypt(BinStr block, BinStr key);

#endif
