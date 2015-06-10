/* RC4.h - Written by Xenonstory on June 08, 2015 *
 * An implementation of the RC4 PRNG                     */      

#ifndef RC4_H
#define RC4_H

#include "..\Structures\BinStr.h"

// RC4(key, n) returns the first n bits of the RC4 key-expansion of key. Returned BinStr must be
//   freed by the user.
// requires: key is a valid BinStr and n >= 0
// effects: allocates memory to a new BinStr
BinStr RC4(BinStr key, int n);

#endif
