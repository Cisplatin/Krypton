/* Hash.c - Created by Xenonstory on August 4, 2015
   An implementation of a generic hash function    */

#include "Hash.h"
#include "../../Structures/BinStr.h"
#include <assert.h>

// padding(str, blockSize) pads the given string with a 1 followed by an
//   amount of zeroes so that the resulting text is a multiple of the given
//   block size
// requires: str is a valid BinStr, blockSize > 0
void padding(BinStr str, int blockSize) {
    assert(str != NULL && blockSize > 0);
    // TODO: Finish padding function
}

// See Hash.h for details
BinStr hashValue(BinStr str, Hash alg) {
    assert(str->length % alg->blockSize == 0);
    return alg->hashFunc(str);
}
