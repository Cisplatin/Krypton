/* MD4.c - Created by Xenonstory on August 7, 2015
   An implementation of the MD4 hashing algorithm */

#include "MD4.h"
#include <stdlib.h>
#include <assert.h>

// TODO
BinStr MD4func(BinStr str) {
    return str;
}

// See MD4.h for details
Hash MD4_initialize() {
    Hash MD4 = malloc(sizeof(Hash));
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
