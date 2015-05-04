/* StreamCipher.c - Written by Xenonstory on April 27, 2015 *
 * An implementation of the a Stream Cipher                 */

#include "StreamCipher.h"
#include <assert.h>
#include <stdlib.h>

// See StreamCipher.h for details
BinStr OTPencrypt(BinStr msg, BinStr key, BinStr (*PRG)(BinStr, int)) {
	assert(msg != NULL && key != NULL && msg->length == key->length);
	BinStr expKey = PRG(key, msg->length);
	BinStr cip = empty_BinStr(msg->length);
	for(int i = 0; i < msg->length; i++) {
		cip->bits[i] = msg->bits[i] ^ expKey->bits[i];
	}
	destroy_BinStr(expKey);
	return cip;
}

// See StreamCipher.h for details
BinStr OTPdecrypt(BinStr cip, BinStr key, BinStr (*PRG)(BinStr, int)) {
	assert(cip != NULL && key != NULL && cip->length == key->length);
	BinStr expKey = PRG(key, cip->length);
	BinStr msg = empty_BinStr(cip->length);
	for(int i = 0; i < msg->length; i++) {
		msg->bits[i] = cip->bits[i] ^ expKey->bits[i];
	}
	destroy_BinStr(expKey);
	return msg;
}