/* BlockCipher.h - Written by Xenonstory on July 20, 2015 *
 * An implementation of a Block Cipher                    */      

#ifndef BLOCKCIPHER_H
#define BLOCKCIPHER_H

#include "../../Structures/BinStr.h"

struct blockcipher {
    BinStr key;
    BinStr *roundKeys;
    int blockSize;
    char *encryptionMode;
    BinStr (*encrypt)(BinStr, BinStr *);
    BinStr (*decrypt)(BinStr, BinStr *);
};

typedef struct blockcipher *BlockCipher;

// BlockEncrypt(msg, cipher) encrypts the given message using the given block
//   cipher, with pre-configured settings. Returns NULL if an invalid mode was
//   given.
// requires: msg != NULL and cipher != NULL and IV != NULL (unless on a mode
//           without an IV).
// effects: allocates memory to a cipher text
BinStr BlockEncrypt(BinStr msg, BinStr IV, BlockCipher cipher);

// BlockDecrypt(cip, cipher) decrypts the given ciphertext using the given
//   block cipher, with pre-configured settings. Returns NULL If an invalid
//   mode was given.
// requires: cip != NULL and cipher != NULL and IV != NULL (unless on a mode
//           without an IV)
// effects: allocates memory to a message
BinStr BlockDecrypt(BinStr cip, BinStr IV, BlockCipher cipher);

#endif
