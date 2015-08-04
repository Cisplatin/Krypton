/* Hash.h - Created by Xenonstory on August 4, 2015
   An implementation of a generic hash function    */

#include "../Structures/BinStr.h"

struct hash {
    int outSize;
    int blockSize;
    BinStr (*hashFunc)(BinStr);
};

typedef struct hash *Hash;
