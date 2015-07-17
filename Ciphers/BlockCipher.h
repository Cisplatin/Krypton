/* BlockCipher.h - Written by Xenonstory on July 17, 2015 *
 * An implementation of a Block Cipher                    */      

#ifndef BLOCKCIPHER_H
#define BLOCKCIPHER_H

#include "../Structures/BinStr.h"

// BlockEncrypt(msg, key, cipher, mode) encrypts the given message using the 
//   given key via the given block cipher and mode.
// requires: msg and key are valid BinStrs, cipher is a block cipher, and mode
//           is 'ECB'
BinStr BlockEncrypt(BinStr msg, BinStr key, BinStr (*cipher)(BinStr, BinStr), 
                    char *mode);

// BlockDecrypt(cip, key, cipher, mode) decrypts the given message using the
//   given key via the given block cipher and mode.
// requires: cip and key are valid BinStrs, cipher is a block cipher, and mode
//           is 'ECB'
BinStr BlockDecrypt(BinStr cip, BinStr key, BinStr (*cipher)(BinStr, BinStr),
                    char *mode);

#endif
