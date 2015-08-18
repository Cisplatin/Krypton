/* MD4.c - Created by Xenonstory on August 17, 2015 
   An implementation of the MD4 cryptographic hash */

#include "MD4.h"
#include <assert.h>
#include <stdlib.h>

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
    BinStr new = copy(X);
    new = set(new, XOR(new, Y));
    new = set(new, XOR(new, Z));
    return new;
}

// MD4funcFF(A, B, C, D, i, s) returns the result of the MD4 FF function
// requires: A, B, C, D are valid BinStrs, X is a valid array
// effects: allocates memory to a new BinStr
BinStr MD4funcFF(BinStr A, BinStr B, BinStr C, BinStr D, 
                 int i, int s, BinStr *X) {
    assert(A != NULL && B != NULL && C != NULL && D != NULL, X != NULL);
    BinStr new = MD4funcF(B, C, D);
    new = set(new, modAdd(new, A, A->length));
    new = set(new, modAdd(new, X[i], X[i]->length));
    new = set(new, rotateL(new, s));
    return new;
}

// MD4func(str) returns the MD4 hash of the given string, using the
//   default IVs in MD4's specifications
// requires: str is a valid BinStr
// effects: allocates new memory to the resulting BinStr
BinStr MD4func(BinStr str) {
    assert(str != NULL);
    
    // Pad the until it is congruent to 448 mod 512
    BinStr tag = copy(str);
    BinStr to_app = str_to_BinStr('1', 1);
    tag = set(tag, append(tag, to_app));
    to_app = set(to_app, str_to_BinStr('0', 1));
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

    // TODO: Finish MD4 algorithm

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
