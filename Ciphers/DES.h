/* DES.h - Written by Xenonstory on June 24, 2015    *
 * An implementation of the Data Encryption Standard */      

#ifndef DES_H
#define DES_H

#include "../Structures/BinStr.h"

const int DES_KEY_SIZE = 64;
const int DES_BLOCK_SIZE = 64;

// DESencrypt(msg, key) encrypts the given message using the given key via the DES.
// requires: msg and key are valid BinStr and key->length == DES_KEY_SIZE
BinStr DESencrypt(BinStr msg, BinStr key);

// DESdecrypt(cip, key) decrypts the given cipher using the given key via the DES.
// requires: cip and key are valid BinStr and key->length == DES_KEY_SIZE
BinStr DESdecrypt(BinStr cip, BinStr key);

#endif
