/* MDC2.h - Created by Xenonstory on August 3
   An implementation of the MDC-2 cryptographic hash */

#ifndef MDC2_H
#define MDC2_H

#include "../Structures/BinStr.h"

// MDC2(str, IV_1, IV_2) returns the MDC-2 hash of the given string
// requires: string has a bit length that is a multiple of 64, and
//           IV_1->length == IV_2->length == 64
// effects: allocates new memory to the resulting BinStr
BinStr MDC2(BinStr str, BinStr IV_1, BinStr IV_2);

#endif
