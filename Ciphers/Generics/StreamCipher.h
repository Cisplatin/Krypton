/* StreamCipher.h - Written by Xenonstory on April 27, 2015 *
 * An implementation of a Stream Cipher                     */      

#ifndef STREAMCIPHER_H
#define STREAMCIPHER_H

#include "../../Structures/BinStr.h"

struct streamcipher {                                                            
    BinStr key;                                                                 
    BinStr generated;
    BinStr (*PRNG)(BinStr, int);
};                                                                              
                                                                                
typedef struct streamcipher *StreamCipher; 

// StreamEncrypt(msg, cipher) encrypts the given message using the given 
//   key via the stream cipher with the given PRNG.
// requires: msg is a valid BinStr, cipher is a stream cipher
BinStr StreamEncrypt(BinStr msg, StreamCipher cipher);

// StreamDecrypt(cip, cipher) decrypts the given cipher text using the given 
//   key via the stream cipher with the given PRNG.
// requires: cip is a valid BinStr, cipher is a stream cipher
BinStr StreamDecrypt(BinStr cip, StreamCipher cipher);

#endif
