/* MDC4.c - Created by Xenonstory on August 5, 2015 
   An implementation of the MDC-4 cryptographic hash */

#include "MDC4.h"
#include <assert.h>
#include <stdlib.h>

const int MDC4_BLOCK_SIZE = 64;
const int MDC4_OUT_SIZE = 128;

// MDC4generateG1(H) returns the result of the first g function for MDC-4
// requires: H is a valid BinStr and H->length == MDC4_BLOCK_SIZE
// effects: allocates memory to a new BinStr
BinStr MDC4generateG1(BinStr H) {
    assert(H != NULL && H->length == MDC4_BLOCK_SIZE);
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

// MDC4generateG2(H) returns the result of the second g function for MDC-4
// requires: H is a valid BinStr and H->length == MDC4_BLOCK_SIZE
// effects: allocates memory to a new BinStr
BinStr MDC4generateG2(BinStr H) {
    assert(H != NULL && H->length == MDC4_BLOCK_SIZE);
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

// MDC4func(str) returns the DES-based MDC-4 hash of the given string, using the
//   default IVs in MDC-4's specifications
// requires: string has a bit length that is a multiple of 64
// effects: allocates new memory to the resulting BinStr
BinStr MDC4func(BinStr str) {
    assert(str != NULL &&  str->length % MDC4_BLOCK_SIZE == 0);
    BinStr G_0 = hex_to_BinStr("5252525252525252");
    BinStr G_1 = hex_to_BinStr("2525252525252525");

    for(int i = 0; i + MDC4_BLOCK_SIZE - 1 < str->length
                 ; i += MDC4_BLOCK_SIZE) {
        // Generate the DES encryption keys
        BinStr seg = snip(str, i, i + MDC4_BLOCK_SIZE - 1);
        BinStr key1 = MDC4generateG1(G_0);
        BinStr key2 = MDC4generateG2(G_1);

        // Encrypt using the generated keys
        BlockCipher DES1 = DES_initialize(key1, "ECB");
        BlockCipher DES2 = DES_initialize(key2, "ECB");
        key1 = set(key1, BlockEncrypt(seg, NULL, DES1));
        key2 = set(key2, BlockEncrypt(seg, NULL, DES2));
        key1 = set(key1, XOR(key1, seg));
        key2 = set(key2, XOR(key2, seg));
        
        // Set the new values of H
        BinStr H_0 = snip(key1, 0, MDC4_BLOCK_SIZE / 2 - 1);
        BinStr buffer = snip(key2, MDC4_BLOCK_SIZE / 2, MDC4_BLOCK_SIZE - 1);
        H_0 = set(H_0, append(H_0, buffer));
        BinStr H_1 = snip(key2, 0, MDC4_BLOCK_SIZE / 2 - 1);
        buffer = snip(key1, MDC4_BLOCK_SIZE / 2, MDC4_BLOCK_SIZE - 1);
        H_1 = set(H_1, append(H_1, buffer));

        // Generate the new DES encryption keys and D values
        key1 = set(key1, MDC4generateG1(H_0));
        key2 = set(key2, MDC4generateG2(H_1));
        DES_destroy(DES1);
        DES_destroy(DES2);
        DES1 = DES_initialize(key1, "ECB");
        DES2 = DES_initialize(key2, "ECB");
        key1 = set(key1, BlockEncrypt(G_1, NULL, DES1));
        key2 = set(key2, BlockEncrypt(G_0, NULL, DES2));
        key1 = set(key1, XOR(key1, G_1));
        key2 = set(key2, XOR(key2, G_0));

        // Set the final G values
        G_0 = snip(key1, 0, MDC4_BLOCK_SIZE / 2 - 1);                    
        buffer = snip(key2, MDC4_BLOCK_SIZE / 2, MDC4_BLOCK_SIZE - 1);   
        G_0 = set(G_0, append(G_0, buffer));                                    
        G_1 = snip(key2, 0, MDC4_BLOCK_SIZE / 2 - 1);                    
        buffer = snip(key1, MDC4_BLOCK_SIZE / 2, MDC4_BLOCK_SIZE - 1);          
        G_1 = set(G_1, append(G_1, buffer));  

        // Garbage collection
        destroy_BinStr(seg);
        destroy_BinStr(key1);
        destroy_BinStr(key2);
        destroy_BinStr(buffer);
        destroy_BinStr(H_0);
        destroy_BinStr(H_1);
        DES_destroy(DES1);
        DES_destroy(DES2);
    }

    // Return the resulting concatenation
    G_0 = set(G_0, append(G_0, G_1));
    destroy_BinStr(G_1);
    return G_0;
}

// See MDC4.h for details
Hash MDC4_initialize() {
    Hash MDC4 = malloc(sizeof(struct hash));
    MDC4->outSize = MDC4_OUT_SIZE;
    MDC4->blockSize = MDC4_BLOCK_SIZE;
    MDC4->hashFunc = MDC4func;
    return MDC4;
}

// See MDC4.h for details
void MDC4_destroy(Hash MDC4) {
    assert(MDC4 != NULL);
    free(MDC4);
}
