/* MDC2.c - Created by Xenonstory on August 3, 2015 
   An implementation of the MDC-2 cryptographic hash */

#include "MDC2.h"
#include <assert.h>
#include <stdlib.h>

const int MDC2_BLOCK_SIZE = 64;

// generateG1(H) returns the result of the first g function for MDC-2
// requires: H is a valid BinStr and H->length == MDC2_BLOCK_SIZE
// effects: allocates memory to a new BinStr
BinStr generateG1(BinStr H) {
    assert(H != NULL && H->length == MDC2_BLOCK_SIZE);
    BinStr key = copyStr(H);
    key->bits[1] = 1;
    key->bits[2] = 0;
    for(int i = 0; i + BITS_PER_BYTE - 1 < H->length; i += BITS_PER_BYTE) {
        BinStr seg = snip(key, i, i + BITS_PER_BYTE - 1);
        if(!parity(seg)) { 
            int verify_bit = i + BITS_PER_BYTE - 1;
            key->bits[verify_bit] = !key->bits[verify_bit];
        }
        destroy_BinStr(seg);
    }
    return key;
}

// generateG2(H) returns the result of the second g function for MDC-2
// requires: H is a valid BinStr and H->length == MDC2_BLOCK_SIZE
// effects: allocates memory to a new BinStr
BinStr generateG2(BinStr H) {
    assert(H != NULL && H->length == MDC2_BLOCK_SIZE);
    BinStr key = copyStr(H);
    key->bits[1] = 0;
    key->bits[2] = 1;
    for(int i = 0; i + BITS_PER_BYTE - 1 < H->length; i += BITS_PER_BYTE) {
        BinStr seg = snip(key, i, i + BITS_PER_BYTE - 1);
        if(!parity(seg)) { 
            int verify_bit = i + BITS_PER_BYTE - 1;
            key->bits[verify_bit] = !key->bits[verify_bit];
        }
        destroy_BinStr(seg);
    }
    return key;
}

// See MDC2.h for details
BinStr MDC2(BinStr str, BinStr IV_1, BinStr IV_2) {
    assert(str != NULL && IV_1 != NULL && IV_2 != NULL &&
           str->length % MDC2_BLOCK_SIZE == 0 &&
           IV_1->length == MDC2_BLOCK_SIZE &&
           IV_2->length == MDC2_BLOCK_SIZE);
    BinStr H_0 = copyStr(IV_1);
    BinStr H_1 = copyStr(IV_2);

    for(int i = 0; i < str->length / MDC2_BLOCK_SIZE; i += MDC2_BLOCK_SIZE) {
        // Generate the DES encryption keys
        BinStr seg = snip(str, i, i + MDC2_BLOCK_SIZE - 1);
        BinStr key1 = generateG1(H_0);
        BinStr key2 = generateG2(H_1);

        // Encrypt using the generated keys
        BlockCipher DES1 = DES_initialize(key1, "ECB");
        BlockCipher DES2 = DES_initialize(key2, "ECB");
        key1 = set(key1, BlockEncrypt(seg, NULL, DES1));
        key2 = set(key2, BlockEncrypt(seg, NULL, DES2));
        key1 = set(key1, XOR(key1, seg));
        key2 = set(key2, XOR(key2, seg));
        
        // Set the new values of H
        H_0 = snip(key1, 0, MDC2_BLOCK_SIZE / 2 - 1);
        BinStr buffer = snip(key2, MDC2_BLOCK_SIZE / 2, MDC2_BLOCK_SIZE - 1);
        H_0 = set(H_0, append(H_0, buffer));
        H_1 = snip(key2, 0, MDC2_BLOCK_SIZE / 2 - 1);
        buffer = snip(key1, MDC2_BLOCK_SIZE / 2, MDC2_BLOCK_SIZE - 1);
        H_1 = set(H_1, append(H_1, buffer));

        // Garbage collection
        destroy_BinStr(seg);
        destroy_BinStr(key1);
        destroy_BinStr(key2);
        destroy_BinStr(buffer);
        DES_destroy(DES1);
        DES_destroy(DES2);
    }

    // Return the resulting concatenation
    H_0 = set(H_0, append(H_0, H_1));
    destroy_BinStr(H_1);
    return H_0;
}
