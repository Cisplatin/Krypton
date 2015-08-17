/* MD4.h - Created by Xenonstory on August 17
   An implementation of the MD4 cryptographic hash */

#ifndef MD4_H
#define MD4_H

#include "Generics/Hash.h"
#include "../Structures/BinStr.h"

// MD4_initialize() returns a copy of an MD4 hash structure
// effects: allocates memory to a new hash structure
Hash MD4_initialize();

// MD4_destroy() destroys the given copy of the MD4 hash structure
// requires: MD4 is a valid Hash
// effects: frees memory associated with MD4
void MD4_destroy(Hash MD4);

#endif
