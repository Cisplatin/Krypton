/* MD4.c - Created by Xenonstory on August 17, 2015 
   An implementation of the MD4 cryptographic hash */

#include "MD4.h"
#include <assert.h>
#include <stdlib.h>

const int MD4_OUT_SIZE = 128;
const int MD4_BLOCK_SIZE = 1;

// M4func(str) returns the MD4 hash of the given string, using the
//   default IVs in MD4's specifications
// requires: str is a valid BinStr
// effects: allocates new memory to the resulting BinStr
BinStr MD4func(BinStr str) {
    // TODO
    return str;
}

// See MD4.h for details
Hash MD4_initialize() {
    Hash MD4 = malloc(sizeof(struct hashstruct));
    MD4->outSize = MD4_OUT_SIZE;
    MD4->blockSize = MD4_BLOCK_SIZE;
    MD4->hashFunc = MD4func;
    return MD4;
}

// See MD4.h for details
void MD4_destroy(Hash MD4) {
    assert(MD4 != NULL);
    free(MD4);
}
