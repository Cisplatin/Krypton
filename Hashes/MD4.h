/* MD4.h - Created by Xenonstory on August 7, 2015
   An implementation of the MD4 cryptographic hash */

#ifndef MD4_H
#define MD4_H

#include "Generics/Hash.h"

// MD4_initialize() returns an instance of an MD4 hash
// effects: allocates memory to a new Hash
Hash MD4_initialize();

// MD4_destroy(MD4) frees all memory associated with the given MD4 hash
// effects: allocates memory to a new Hash
void MD4_destroy(Hash MD4);

#endif
