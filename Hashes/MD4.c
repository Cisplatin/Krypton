/* MD4.c - Created by Xenonstory on August 7, 2015
   An implementation of the MD4 hashing algorithm */

#include "MD4.h"
#include <stdlib.h>
#include <assert.h>

const int MD4_OUT_SIZE = 128;
const int MD4_BLOCK_SIZE = 1;

// MD4func(str) returns the MD4 hash value of the given string
// requires: str is a valid BinStr
// effects: allocates memory to a new BinStr
BinStr MD4func(BinStr str) {
    assert(str != NULL);
    
    // Start with the MD4 padding
    BinStr value = copy(str);
    BinStr zero = str_to_BinStr("0", 1);
    BinStr one = str_to_BinStr("1", 1);
    hash = set(hash, append(hash, one));
    while(hash->length % 512 != 448) {
        hash = set(hash, append(hash, zero));
    }

    // Append the original message length
    BinStr length = int_to_BinStr(str->length);
    length = set(length, cut(length, 64));
    hash = set(hash, append(hash, length));

    // Garbage collection
    destroy_BinStr(zero);
    destroy_BinStr(one);
    destroy_BinStr(length);
    return hash;
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
