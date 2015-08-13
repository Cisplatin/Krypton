/* CBCMAC.c - Created by Xenonstory on August 13
   An implementation of the CBC-MAC algorithm   */

#include "CBCMAC.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

BinStr CBCMAC(BinStr str, BlockCipher cipher) {
    assert(str != NULL && cipher != NULL && 
           strcmp(cipher->encryptionMode, "ECB") == 0);
    BinStr padded = copy(str);
    paddingMethod2(padded, cipher->blockSize);
    BinStr tag = NULL;
    for(int i = 0; i + cipher->blockSize < str->length
                 ; i += cipher->blockSize) {
        BinStr buffer = snip(padded, i, i + cipher->blockSize);
        if(tag != NULL) tag = set(tag, XOR(tag, buffer));
        else            tag = buffer;
        tag = set(tag, BlockEncrypt(tag, NULL, cipher));
        destroy_BinStr(buffer);
    }
    destroy_BinStr(padded);
    return tag;
}
