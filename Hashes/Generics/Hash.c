/* Hash.c - Created by Xenonstory on August 4, 2015
   An implementation of a generic hash function    */

#include "Hash.h"
#include "../../Structures/BinStr.h"
#include <assert.h>

// See Hash.h for details
BinStr hashValue(BinStr str, Hash alg) {
    assert(str->length % alg->blockSize == 0);
    return alg->hashFunc(str);
}

