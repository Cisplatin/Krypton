/* StreamCipher.c - Written by Xenonstory on April 27, 2015 *
 * An implementation of a Stream Cipher                 */

#include "StreamCipher.h"
#include <assert.h>
#include <stdlib.h>

// See StreamCipher.h for details
BinStr StreamEncrypt(BinStr msg, StreamCipher cipher) {
	assert(msg != NULL && cipher != NULL);
	BinStr expKey = (*cipher->PRG)(cipher->key, msg->length);
	BinStr cip = empty_BinStr(msg->length);
	for(int i = 0; i < msg->length; i++) {
		cip->bits[i] = msg->bits[i] ^ expKey->bits[i];
	}
	destroy_BinStr(expKey);
	return cip;
}

// See StreamCipher.h for details
BinStr StreamDecrypt(BinStr cip, StreamCipher cipher) {
	assert(cip != NULL && cipher != NULL);
	BinStr expKey = (*cipher->PRG)(cipher->key, cip->length);
	BinStr msg = empty_BinStr(cip->length);
	for(int i = 0; i < msg->length; i++) {
		msg->bits[i] = cip->bits[i] ^ expKey->bits[i];
	}
	destroy_BinStr(expKey);
	return msg;
}
