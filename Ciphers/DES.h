/* DES.h - Written by Xenonstory on June 24, 2015    *
 * An implementation of the Data Encryption Standard */      

#ifndef DES_H
#define DES_H

#include "../Structures/BinStr.h"

// DESencrypt(block, key) encrypts the given message using the given key via the DES.
// requires: block and key are valid BinStr and block->length == DES_BLOCK_SIZE and
//           key->length == DES_KEY_SIZE
BinStr DESencrypt(BinStr block, BinStr key);

// DESdecrypt(block, key) decrypts the given cipher using the given key via the DES.
// requires: block and key are valid BinStr and block->length == DES_BLOCK_SIZE
//           and key->length == DES_KEY_SIZE
BinStr DESdecrypt(BinStr block, BinStr key);

#endif
