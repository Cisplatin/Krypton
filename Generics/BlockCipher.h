/* BlockCipher.h - Written by Xenonstory on July 20, 2015 *
 * An implementation of a Block Cipher                    */      

#ifndef BLOCKCIPHER_H
#define BLOCKCIPHER_H

#include "../Structures/BinStr.h"

struct blockcipher {
    BinStr key;
    int blockSize;
    char *encryptionMode;
    BinStr (*encrypt)(BinStr, BinStr);
    BinStr (*decrypt)(BinStr, BinStr);
};

typedef struct blockcipher *BlockCipher;

// BlockEncrypt(msg, cipher) encrypts the given message using the given block
//   cipher, with pre-configured settings. Returns NULL if an invalid mode was
//   given.
// requires: msg != NULL and cipher != NULL
// effects: allocates memory to a cipher text
BinStr BlockEncrypt(BinStr msg, BlockCipher cipher);

// BlockDecrypt(cip, cipher) decrypts the given ciphertext using the given
//   block cipher, with pre-configured settings. Returns NULL If an invalid
//   mode was given.
// requires: cip != NULL and cipher != NULL
// effects: allocates memory to a message
BinStr BlockDecrypt(BinStr cip, BlockCipher cipher);

#endif
