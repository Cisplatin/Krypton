/* Hash.h - Created by Xenonstory on August 4, 2015
   An implementation of a generic hash function    */

#include "../../Structures/BinStr.h"

struct hashstruct {
    int outSize;
    int blockSize;
    BinStr (*hashFunc)(BinStr);
};

typedef struct hashstruct *Hash;

// hash(str, alg) returns the hash value of the given string using the
//   given cryptographic hash algorithm
// requires: str is a valid BinStr, alg is a valid Hash
BinStr hash(BinStr str, Hash alg);
