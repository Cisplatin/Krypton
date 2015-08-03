/* MDC2.c - Created by Xenonstory on August 3, 2015 
   An implementation of the MDC-2 cryptographic hash */

#include "MDC2.h"
#include "../Structures/BinStr.h"
#include "../Ciphers/DES.h"
#include <assert.h>

const int MDC2_BLOCK_SIZE = 64;

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
