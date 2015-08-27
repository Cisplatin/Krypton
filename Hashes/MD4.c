/* MD4.c - Created by Xenonstory on August 17, 2015 
   An implementation of the MD4 cryptographic hash */

#include "MD4.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

const int MD4_OUT_SIZE = 128;
const int MD4_BLOCK_SIZE = 1;

// MD4funcF(X, Y, Z) returns a new BinStr that is the result of MD4's 
//   f-function on the given strings
// requires: X, Y, Z are valid BinStrs of the same length
// effects: allocates memory to a new BinStr
BinStr MD4funcF(BinStr X, BinStr Y, BinStr Z) {
    assert(X != NULL && Y != NULL && Z != NULL &&
           X->length == Y->length && Y->length == Z->length);
    BinStr new = AND(X, Y);
    BinStr buffer = NOT(X);
    buffer = set(buffer, AND(buffer, Z));
    new = set(new, OR(new, buffer));
    destroy_BinStr(buffer);
    return new;
}

// MD4funcG(X, Y, Z) returns a new BinStr that is the result of MD4's
//   g-function on the given strings
// requires: X, Y, Z are valid BinStrs of the same length
// effects: allocates memory to a new BinStr
BinStr MD4funcG(BinStr X, BinStr Y, BinStr Z) {
    assert(X != NULL && Y != NULL && Z != NULL &&
           X->length == Y->length && Y->length == Z->length);
    BinStr new = AND(X, Y);
    BinStr buffer = AND(X, Z);
    new = set(new, OR(new, buffer));
    buffer = set(buffer, AND(Y, Z));
    new = set(new, OR(new, buffer));
    destroy_BinStr(buffer);
    return new;
}

// MD4funcH(X, Y, Z) returns a new BinStr that is the result of MD4's
//   h-function on the given strings
// requires: X, Y, Z are valid BinStrs of the same length
// effects: allocates memory to a new BinStr
BinStr MD4funcH(BinStr X, BinStr Y, BinStr Z) {
    assert(X != NULL && Y != NULL && Z != NULL &&
           X->length == Y->length && Y->length == Z->length);
    BinStr new = copyStr(X);
    new = set(new, XOR(new, Y));
    new = set(new, XOR(new, Z));
    return new;
}

// MD4funcFF(A, B, C, D, s, X) returns the result of the MD4 FF function
// requires: A, B, C, D are valid BinStrs, X is a valid array
BinStr MD4funcFF(BinStr A, BinStr B, BinStr C, BinStr D, 
                 int i, int s, BinStr *X) {
    assert(A != NULL && B != NULL && C != NULL && D != NULL && X != NULL);
    BinStr new = MD4funcF(B, C, D);
    new = set(new, modAdd(new, A, A->length));
    new = set(new, modAdd(new, X[i], X[i]->length));
    new = set(new, rotateL(new, s));
    A = set(A, new);
    return A;
}

// MD4funcGG(A, B, C, D, s, X) returns the result of the MD4 GG function
// requires: A, B, C, D are valid BinStrs, X is a valid array
BinStr MD4funcGG(BinStr A, BinStr B, BinStr C, BinStr D, 
                 int i, int s, BinStr *X) {
    assert(A != NULL && B != NULL && C != NULL && D != NULL && X != NULL);
    BinStr new = MD4funcG(B, C, D);
    BinStr sqrt2 = hex_to_BinStr("5A827999");
    new = set(new, modAdd(new, A, A->length));
    new = set(new, modAdd(new, X[i], X[i]->length));
    new = set(new, modAdd(new, sqrt2, new->length));
    new = set(new, rotateL(new, s));
    destroy_BinStr(sqrt2);
    A = set(A, new);
    return A;
}

// MD4funcHH(A, B, C, D, s, X) returns the result of the MD4 HH function
// requires: A, B, C, D are valid BinStrs, X is a valid array
BinStr MD4funcHH(BinStr A, BinStr B, BinStr C, BinStr D, 
                 int i, int s, BinStr *X) {
    assert(A != NULL && B != NULL && C != NULL && D != NULL && X != NULL);
    BinStr new = MD4funcH(B, C, D);
    BinStr sqrt3 = hex_to_BinStr("6ED9EBA1");
    new = set(new, modAdd(new, A, A->length));
    new = set(new, modAdd(new, X[i], X[i]->length));
    new = set(new, modAdd(new, sqrt3, new->length));
    new = set(new, rotateL(new, s));
    destroy_BinStr(sqrt3);
    A = set(A, new);
    return A;
}

// MD4func(str) returns the MD4 hash of the given string, using the
//   default IVs in MD4's specifications
// requires: str is a valid BinStr
// effects: allocates new memory to the resulting BinStr
BinStr MD4func(BinStr str) {
    assert(str != NULL);
    
    // Pad the until it is congruent to 448 mod 512
    BinStr tag = copyStr(str);
    BinStr to_app = str_to_BinStr("1", 1);
    tag = set(tag, append(tag, to_app));
    to_app = set(to_app, str_to_BinStr("0", 1));
    while(tag->length % 512 != 448) {
        tag = set(tag, append(tag, to_app));
    }

    // Pad the length of the string at the end
    to_app = set(to_app, int_to_BinStr(str->length));
    to_app = set(to_app, cut(to_app, MD4_OUT_SIZE / 2));
    BinStr front_pad = snip(to_app, 0, to_app->length / 2 - 1);
    to_app = set(to_app, snip(to_app, to_app->length / 2, to_app->length - 1));
    tag = set(tag, append(tag, to_app));
    tag = set(tag, append(tag, front_pad));
    destroy_BinStr(to_app);
    destroy_BinStr(front_pad);

    // Initialize the MD4 buffer
    BinStr A = hex_to_BinStr("67452301");
    BinStr B = hex_to_BinStr("efcdab89");
    BinStr C = hex_to_BinStr("98badcfe");
    BinStr D = hex_to_BinStr("10325476");
   
    // Process in 16-word blocks
    int word_blocks = 16;
    for(int i = 0; i < tag->length / (BITS_PER_WORD * word_blocks); i++) {
        // Get a chunk of 16 word blocks
        BinStr *X = malloc(sizeof(BinStr) * word_blocks);
        for(int j = 0; j < word_blocks; j++) {
            X[j] = snip(tag, 
                i * BITS_PER_WORD * word_blocks + j * BITS_PER_WORD,
                i * BITS_PER_WORD * word_blocks + (j + 1) * BITS_PER_WORD - 1);
        }

        // Make copies of current A, B, C, D
        BinStr AA = copyStr(A);
        BinStr BB = copyStr(B);
        BinStr CC = copyStr(C);
        BinStr DD = copyStr(D);

        // Round 1
        A = MD4funcFF(A, B, C, D,  0,  3, X);
        D = MD4funcFF(D, A, B, C,  1,  7, X);
        C = MD4funcFF(C, D, A, B,  2, 11, X);
        B = MD4funcFF(B, C, D, A,  3, 19, X);
        A = MD4funcFF(A, B, C, D,  4,  3, X);
        D = MD4funcFF(D, A, B, C,  5,  7, X);
        C = MD4funcFF(C, D, A, B,  6, 11, X);
        B = MD4funcFF(B, C, D, A,  7, 19, X);
        A = MD4funcFF(A, B, C, D,  8,  3, X);
        D = MD4funcFF(D, A, B, C,  9,  7, X);
        C = MD4funcFF(C, D, A, B, 10, 11, X);
        B = MD4funcFF(B, C, D, A, 11, 19, X);
        A = MD4funcFF(A, B, C, D, 12,  3, X);
        D = MD4funcFF(D, A, B, C, 13,  7, X);
        C = MD4funcFF(C, D, A, B, 14, 11, X);
        B = MD4funcFF(B, C, D, A, 15, 19, X);

        // Round 2
        A = MD4funcGG(A, B, C, D,  0,  3, X);
        D = MD4funcGG(D, A, B, C,  4,  5, X);
        C = MD4funcGG(C, D, A, B,  8,  9, X);
        B = MD4funcGG(B, C, D, A, 12, 13, X);
        A = MD4funcGG(A, B, C, D,  1,  3, X);
        D = MD4funcGG(D, A, B, C,  5,  5, X);
        C = MD4funcGG(C, D, A, B,  9,  9, X);
        B = MD4funcGG(B, C, D, A, 13, 13, X);
        A = MD4funcGG(A, B, C, D,  2,  3, X);
        D = MD4funcGG(D, A, B, C,  6,  5, X);
        C = MD4funcGG(C, D, A, B, 10,  9, X);
        B = MD4funcGG(B, C, D, A, 14, 13, X);
        A = MD4funcGG(A, B, C, D,  3,  3, X);
        D = MD4funcGG(D, A, B, C,  7,  5, X);
        C = MD4funcGG(C, D, A, B, 11,  9, X);
        B = MD4funcGG(B, C, D, A, 15, 13, X);     

        // Round 3
        A = MD4funcHH(A, B, C, D,  0,  3, X);
        D = MD4funcHH(D, A, B, C,  8,  9, X);
        C = MD4funcHH(C, D, A, B,  4, 11, X);
        B = MD4funcHH(B, C, D, A, 12, 15, X);
        A = MD4funcHH(A, B, C, D,  2,  3, X);
        D = MD4funcHH(D, A, B, C, 10,  9, X);
        C = MD4funcHH(C, D, A, B,  6, 11, X);
        B = MD4funcHH(B, C, D, A, 14, 15, X);
        A = MD4funcHH(A, B, C, D,  1,  3, X);
        D = MD4funcHH(D, A, B, C,  9,  9, X);
        C = MD4funcHH(C, D, A, B,  5, 11, X);
        B = MD4funcHH(B, C, D, A, 13, 15, X);
        A = MD4funcHH(A, B, C, D,  3,  3, X);
        D = MD4funcHH(D, A, B, C, 11,  9, X);
        C = MD4funcHH(C, D, A, B,  7, 11, X);
        B = MD4funcHH(B, C, D, A, 15, 15, X);     

        // Add to the original values
        A = set(A, modAdd(A, AA, A->length));
        B = set(B, modAdd(B, BB, B->length));
        C = set(C, modAdd(C, CC, C->length));
        D = set(D, modAdd(D, DD, D->length));

        // Free the blocks
        for(int j = 0; j < word_blocks; j++) {
            free(X[j]);        
        }
        free(X);
        free(AA);
        free(BB);
        free(CC);
        free(DD);
    }
 
    // Concatenate A, B, C, D
    tag = set(tag, append(D, C));
    tag = set(tag, append(tag, B));
    tag = set(tag, append(tag, A));
    tag = set(tag, reverse(tag));

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
