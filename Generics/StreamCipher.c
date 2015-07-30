/* StreamCipher.c - Written by Xenonstory on April 27, 2015 *
 * An implementation of a Stream Cipher                 */

#include "StreamCipher.h"
#include <assert.h>
#include <stdlib.h>

// See StreamCipher.h for details
BinStr StreamEncrypt(BinStr msg, BinStr seed, StreamCipher cipher) {
	assert(msg != NULL && cipher != NULL);
	bool generatedNew = false;
    BinStr expKey;
    if(cipher->generated->length >= msg->length) {
        expKey = cut(cipher->generated, msg->length);
    } else {
        generatedNew = true;
        BinStr expKey = (*cipher->PRNG)(cipher->key, seed, msg->length);
	    cipher->generated = set(cipher->generated, expKey);
    }
    BinStr cip = empty_BinStr(msg->length);
	for(int i = 0; i < msg->length; i++) {
		cip->bits[i] = msg->bits[i] ^ expKey->bits[i];
	}
    if(!generatedNew) {
	    destroy_BinStr(expKey);
    }
	return cip;
}

// See StreamCipher.h for details
BinStr StreamDecrypt(BinStr cip, BinStr seed, StreamCipher cipher) {
	assert(cip != NULL && cipher != NULL);
    bool generatedNew = false;
    BinStr expKey;
    if(cipher->generated->length >= cip->length) {
        expKey = cut(cipher->generated, cip->length);
    } else {
        generatedNew = true;
        BinStr expKey = (*cipher->PRNG)(cipher->key, seed, cip->length);
        cipher->generated = set(cipher->generated, expKey);
    }
    BinStr msg = empty_BinStr(cip->length);
	for(int i = 0; i < msg->length; i++) {
		msg->bits[i] = cip->bits[i] ^ expKey->bits[i];
	}
    if(!generatedNew) {
	    destroy_BinStr(expKey);
    }
	return msg;
}
