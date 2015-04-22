/* OneTimePad.c - Written by Xenonstory on April 21, 2015 *
 * An implementation of the One Time Pad cipher           */

#include "OneTimePad.h"
#include <assert.h>
#include <stdlib.h>

// See OneTimePad.h for details
BinStr OTPencrypt(BinStr msg, BinStr key) {
	assert(msg != NULL && key != NULL && msg->length == key->length);
	BinStr cip = empty_BinStr(msg->length);
	for(int i = 0; i < msg->length; i++) {
		cip->bits[i] = msg->bits[i] ^ key->bits[i];
	}
	return cip;
}

// See OneTimePad.h for details
BinStr OTPdecrypt(BinStr cip, BinStr key) {
	assert(cip != NULL && key != NULL && cip->length == key->length);
	BinStr msg = empty_BinStr(msg->length);
	for(int i = 0; i < msg->length; i++) {
		msg->bits[i] = cip->bits[i] ^ key->bits[i];
	}
	return msg;
}
