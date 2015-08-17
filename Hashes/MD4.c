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
    assert(str != NULL);
    
    // Pad the until it is congruent to 448 mod 512
    BinStr tag = copy(str);
    BinStr to_app = str_to_BinStr('1', 1);
    str = set(str, append(str, to_app));
    to_app = set(to_app, str_to_BinStr('0', 1));
    while(str->length % 512 != 448) {
        str = set(str, append(str, to_app));
    }
    destroy_BinStr(to_app);

    // TODO: Finish MD4 algorithm

    return tag;
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
