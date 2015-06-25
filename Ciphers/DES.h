/* DES.h - Written by Xenonstory on June 24, 2015    *
 * An implementation of the Data Encryption Standard */      

#ifndef DES_H
#define DES_H

#include "../Structures/BinStr.h"

// DESencrypt(msg, key) encrypts the given message using the given key via the DES.
// requires: msg and key are valid BinStr and key->length == 64
BinStr DESencrypt(BinStr msg, BinStr key);

// DESdecrypt(cip, key) decrypts the given cipher using the given key via the DES.
// requires: cip and key are valid BinStr and key->length == 64
BinStr DESdecrypt(BinStr cip, BinStr key);

#endif