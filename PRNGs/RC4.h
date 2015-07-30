/* RC4.h - Written by Xenonstory on July 29, 2015        *
 * An implementation of the RC4 PRNG                     */      

#ifndef RC4P_H
#define RC4P_H

#include "../Structures/BinStr.h"

// RC4_PRNG(key, seed, n) returns the result of the RC4 pseudorandom number generator
//   when seeded with the given key. Only the first n bits are returned.
// requires: key is a valid BinStr, n >= 0, seed is NULL
// effects: allocates memory to a new BinStr
BinStr RC4_PRNG(BinStr key, BinStr seed, int n);

#endif
