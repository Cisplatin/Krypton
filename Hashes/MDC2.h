/* MDC2.h - Created by Xenonstory on August 3
   An implementation of the MDC-2 cryptographic hash */

#ifndef MDC2_H
#define MDC2_H

#include "../Structures/BinStr.h"
#include "../Generics/BlockCipher.h"
#include "../Ciphers/DES.h"

// MDC2(str) returns the DES-based MDC-2 hash of the given string, using the
//   default IVs in MDC-2's specifications
// requires: string has a bit length that is a multiple of 64
// effects: allocates new memory to the resulting BinStr
BinStr MDC2(BinStr str);

#endif
