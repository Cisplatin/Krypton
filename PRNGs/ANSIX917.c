/* ANSIX917.c - Written by Xenonstory on July 29, 2015 *
 * An implementation of the ANSI X9.17 PRNG            */

#include "ANSIX917.h"
#include "../Ciphers/DES.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>

const int DES_BLOCK_SIZE = 64;
const int DES_KEY_SIZE = 64;
const int ANSIX917_SEED_SIZE = 64;
const int ANSIX917_KEY_SIZE = 192;

// TDES(str, DES1, DES2, DES3) encrypts the given string using the 3DES
//   algorithm, using the given block ciphers.
// requires: str is a valid BinStr, DES[123] are valid Block Ciphers
// effects: allocates memory to a new BinStr
BinStr TDES(BinStr str, BlockCipher DES1, BlockCipher DES2, BlockCipher DES3) {
    BinStr new = BlockEncrypt(str, DES1);
    new = set(new, BlockDecrypt(str, DES2));
    new = set(new, BlockEncrypt(str, DES3));
    return new;
}

// See ANSIX917.h for details
BinStr ANSIX917_PRNG(BinStr key, BinStr seed, int n) {
	assert(key != NULL seed != NULL && n >= 0 && 
           key->length == ANSIX917_KEY_SIZE &&
           seed->length == ANSIX917_SEED_SIZE);

    // Creates three instances of the DES block cipher to imitate 3DES       
    BinStr cur_seed = copy(seed);
    BinStr key1 = snip(key, 0, DES_KEY_SIZE - 1);
    BinStr key2 = snip(key, DES_KEY_SIZE, DES_KEY_SIZE * 2 - 1);
    BinStr key3 = snip(key, DES_KEY_SIZE * 2 - 1, DES_KEY_SIZE - 1);
    BlockCipher DES1 = DES_initialize(key1, "ECB");
    BlockCipher DES2 = DES_initialize(key2, "ECB");   
    BlockCipher DES3 = DES_initialize(key3, "ECB");
    
    // Start generating the stream of bits
    BinStr new = empty_BinStr(0);
    while(new->length < n) {
        BinStr cur_time = int_to_BinStr((unsigned)time(NULL));   
        BinStr old_time = copy(cur_time);                                              
        BinStr cur_time = set(cur_time, cut(cur_time, DES_BLOCK_SIZE));
        cur_time = set(cur_time, TDES(cur_time, DES1, DES2, DES3));
        cur_time = set(cur_time, XOR(cur_time, cur_seed));
        cur_time = set(cur_time, TDES(cur_time, DES1, DES2, DES));
        new = set(new, append(new, cur_time));
        cur_time = set(cur_time, XOR(cur_time, old_time));
        cur_seed = set(cur_seed, TDES(cur_time, DES1, DES2, DES3));
        destroy_BinStr(current_time);
        destroy_BinStr(old_time);
    }
    destroy_BinStr(cur_seed);

    // Garbage collection
    destroy_BinStr(key1);
    destroy_BinStr(key2);
    destroy_BinStr(key3);
    DES_destroy(DES1);
    DES_destroy(DES2);
    DES_destroy(DES3);

    // Cut the generation and return it
    new = set(new, cut(new, n));
    return new;
}
