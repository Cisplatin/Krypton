/* BlockCipher.c - Written by Xenonstory on July 20, 2015    *
 * An implementation of a generic block cipher               */

#include "BlockCipher.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>


// ECBencrypt(msg, cipher) encrypts the given message using an  
//   ECB mode block cipher and the given key                                    
// requires: msg is a valid BinStr, cipher is a block cipher            
BinStr ECBencrypt(BinStr msg, BlockCipher cipher) {                                              
    assert(msg != NULL && cipher != NULL && 
           msg->length % cipher->blockSize == 0);                                       
    BinStr cip = empty_BinStr(0);                                               
    for(int i = 0; i < msg->length; i += cipher->blockSize) {                           
        BinStr to_app = snip(msg, i, i + cipher->blockSize - 1);                        
        to_app = replace(to_app, (*cipher->encrypt)(to_app, cipher->key));                       
        cip = replace(cip, append(cip, to_app));                                
        destroy_BinStr(to_app);                                                 
    }                                                                           
    return cip;                                                                 
}                                                                               
                                                                                
// ECBdecrypt(cip, cipher) decrypts the given message using an  
//   ECB mode block cipher and the given key                                    
// requires: cip is a valid BinStr, cipher is a block cipher            
BinStr ECBdecrypt(BinStr cip, BlockCipher cipher) {
    assert(cip != NULL && cipher != NULL &&
           cip->length % cipher->blockSize == 0);
    BinStr msg = empty_BinStr(0);
    for(int i = 0; i < cip->length; i += cipher->blockSize) {
        BinStr to_app = snip(cip, i, i + cipher->blockSize - 1);
        to_app = replace(to_app, (*cipher->decrypt)(to_app, cipher->key));
        msg = replace(msg, append(msg, to_app));
        destroy_BinStr(to_app);
    }
    return msg;
}

// See BlockCipher.h for details
BinStr BlockEncrypt(BinStr msg, BlockCipher cipher) {
    assert(msg != NULL && cipher != NULL);
    if(strcmp(cipher->encryptionMode, "ECB") == 0) {
        return ECBencrypt(msg, cipher);
    } else {
        return NULL; // TODO: Throw an error instead of returning NULL
    }
}
