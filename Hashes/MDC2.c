/* MDC2.c - Created by Xenonstory on August 3, 2015 
   An implementation of the MDC-2 cryptographic hash */

#include "MDC2.h"
#include "../Structures/BinStr.h"
#include "../Ciphers/DES.h"
#include <assert.h>

const int MDC2_BLOCK_SIZE = 64;

// generateG1(H) returns the result of the first g function for MDC-2
// requires: H is a valid BinStr and H->length == MDC2_BLOCK_SIZE
// effects: allocates memory to a new BinStr
BinStr generateG1(BinStr H) {
    assert(H != NULL && H->length == MDC2_BLOCK_LENGTH);
    BinStr key = copy(H);
    key->bits[1] = 1;
    key->bits[2] = 0;
    for(int i = BITS_PER_BYTE - 1; i < H->length; i += BITS_PER_BYTE) {
        BinStr seg = snip(key, i, i + BITS_PER_BYTE - 1);
        if(parity(seg)) { 
            int verify_bit = i + BITS_PER_BYTE - 1;
            key->bits[verify_bit] = !key->bits[verify_bit];
        }
        destroy_BinStr(seg);
    }
    return key
}

// generateG2(H) returns the result of the second g function for MDC-2
// requires: H is a valid BinStr and H->length == MDC2_BLOCK_SIZE
// effects: allocates memory to a new BinStr
BinStr generateG2(BinStr H) {
    assert(H != NULL && H->length == MDC2_BLOCK_LENGTH);
    BinStr key = copy(H);
    key->bits[1] = 0;
    key->bits[2] = 1;
    for(int i = BITS_PER_BYTE - 1; i < H->length; i += BITS_PER_BYTE) {
        BinStr seg = snip(key, i, i + BITS_PER_BYTE - 1);
        if(parity(seg)) { 
            int verify_bit = i + BITS_PER_BYTE - 1;
            key->bits[verify_bit] = !key->bits[verify_bit];
        }
        destroy_BinStr(seg);
    }
    return key
}

// See MDC2.h for details
BinStr MDC2(BinStr str, BinStr IV_1, BinStr IV_2) {
    assert(str != NULL && IV_1 != NULL && IV_2 != NULL &&
           str->length % MDC2_BLOCK_SIZE == 0 &&
           IV_1->length == MDC2_BLOCK_SIZE &&
           IV_2->length == MDC2_BLOCK_SIZE);
    BinStr H_0 = copy(IV_1);
    BinStr H_1 = copy(IV_2);

    // TODO: Finish hashing function

    H_0 = set(H_0, append(H_0, H_1));
    destroy_BinStr(H_1);
    return H_0;
}
