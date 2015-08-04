/* HMAC.c - Created by Xenonstory on August 4th, 2015
   HMAC is an implementation of the HMAC message authentication code */

#include "HMAC.h"
#include <assert.h>
#include <stdlib.h>

// See HMAC.h for details
BinStr HMAC(BinStr msg, BinStr key, BinStr (*hash)(BinStr)) {
    assert(msg != NULL && key != NULL && hash != NULL);
    // TODO: Finish function
    return msg;
}
