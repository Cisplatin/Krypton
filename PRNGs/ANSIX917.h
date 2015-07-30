/* ANSIX917.h - Written by Xenonstory on July 29, 2015        *
 * An implementation of the ANSI X9.17 PRNG                   */      

#ifndef ANSIX917_H
#define ANSIX917_H

#define ANSIX917_KEY_SIZE 192
#define ANSIX917_SEED_SIZE 64

#include "../Structures/BinStr.h"

// ANSIX917_PRNG(key, n) returns the result of the ANSI X9.17 pseudorandom 
//   number generator when seeded with the given key. Only the first 
//   n bits are returned.
// requires: key and seed are valid BinStrs of appropriate length, n >= 0
// effects: allocates memory to a new BinStr
BinStr ANSIX917_PRNG(BinStr key, BinStr seed, int n);

#endif
