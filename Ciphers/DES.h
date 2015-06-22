/* DES.h - Written by Xenonstory on June 22, 2015    *
 * An implementation of the Data Encryption Standard */      

#ifndef DES_H
#define DES_H

#include "../Structures/BinStr.h"

// OTPencrypt(msg, key) encrypts the given message using the given key via the DES.
// requires: msg and key are valid BinStrs
BinStr DESencrypt(BinStr msg, BinStr key);

// OTPdecrypt(cip, key) decrypts the given cipher text using the given key via the DES.
// requires: cip and key are valid BinStrs.
BinStr DESdecrypt(BinStr cip, BinStr key);

#endif
