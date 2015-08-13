/* CBCMAC.h - Created by Xenonstory on August 13 
   An implementation of the CBC-MAC algorithm   */

#ifndef CBCMAC_H
#define CBCMAC_H

#include "../Structures/BinStr.h"
#include "../Ciphers/Generics/BlockCipher.h"

// CBCMAC(str, cipher, key) is an implementation of the CBC MAC algorithm
//   using the given block cipher.
// requires: str, cipher, and key are all not NULL
// effects: allocates memory to a new BinStr
BinStr CBCMAC(BinStr str, BlockCipher cipher, BinStr key);

#endif
