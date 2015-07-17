/* StreamCipher.h - Written by Xenonstory on April 27, 2015 *
 * An implementation of a Stream Cipher                     */      

#ifndef STREAMCIPHER_H
#define STREAMCIPHER_H

#include "../Structures/BinStr.h"

// StreamEncrypt(msg, key, cipher) encrypts the given message using the given 
//   key via the stream cipher with the given PRNG.
// requires: msg and key are valid BinStrs, cipher is a stream cipher
BinStr StreamEncrypt(BinStr msg, BinStr key, BinStr (*cipher)(BinStr, int));

// StreamDecrypt(cip, key cipher) decrypts the given cipher text using the given 
//   key via the stream cipher with the given PRNG.
// requires: cip and key are valid BinStrs, cipher is a stream cipher
BinStr StreamDecrypt(BinStr cip, BinStr key, BinStr (*cipher)(BinStr, int));

#endif
