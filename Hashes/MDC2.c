/* MDC2.c - Created by Xenonstory on August 3, 2015 
   An implementation of the MDC-2 cryptographic hash */

#include "MDC2.h"
#include <assert.h>

const int MDC2_BLOCK_SIZE = 64;

// See MDC2.h for details
BinStr MDC2(BinStr str, BinStr IV_1, BinStr IV_2) {
    assert(str->length % MDC2_BLOCK_SIZE == 0 &&
           IV_1->length == MDC2_BLOCK_SIZE &&
           IV_2->length == MDC2_BLOCK_SIZE);
    // TODO
    return str;
}
