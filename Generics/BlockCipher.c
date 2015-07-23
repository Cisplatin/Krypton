/* BlockCipher.c - Written by Xenonstory on July 20, 2015    *
 * An implementation of a generic block cipher               */

#include "BlockCipher.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// CBCencrypt(msg, IV, cipher) encrypts the given message using the given
//   cipher and IV, using CBC mode.
// requires: msg and IV are valid BinStrs, cipher is a block cipher
// effects: allocates memory to a new BinStr
BinStr CBCencrypt(BinStr msg, BinStr IV, BlockCipher cipher) {
    assert(msg != NULL && IV != NULL && cipher != NULL &&
           msg->length % cipher->blockSize == 0 &&
           IV->length % cipher->blockSize == 0);
    // TODO: Actually encrypt
    return msg;
}

// CBCdecrypt(cip, IV, cipher) decrypts the given message using the given
//   cipher and IV, using CBC mode.
// requires: cip and IV are valid BinStrs, cipher is a block cipher
// effects: allocates memory to a new BinStr
BinStr CBCdecrypt(BinStr cip, BinStr IV, BlockCipher cipher) {
    assert(cip != NULL && IV != NULL && cipher != NULL &&
           cip->length % cipher->blockSize == 0 &&
           IV->length % cipher->blockSize == 0);
    // TODO: Actually decrypt
    return cip;
}

// ECBencrypt(msg, cipher) encrypts the given message using an  
//   ECB mode block cipher and the given key                                    
// requires: msg is a valid BinStr, cipher is a block cipher            
// effects: allocates memory to a new BinStr
BinStr ECBencrypt(BinStr msg, BlockCipher cipher) {                                              
    assert(msg != NULL && cipher != NULL && 
           msg->length % cipher->blockSize == 0);                                       
    BinStr cip = empty_BinStr(0);                                               
    for(int i = 0; i < msg->length; i += cipher->blockSize) {                           
        BinStr to_app = snip(msg, i, i + cipher->blockSize - 1);                        
        to_app = set(to_app, (*cipher->encrypt)(to_app, cipher->key));                       
        cip = set(cip, append(cip, to_app));                                
        destroy_BinStr(to_app);                                                 
    }                                                                           
    return cip;                                                                 
}                                                                               
                                                                                
// ECBdecrypt(cip, cipher) decrypts the given message using an  
//   ECB mode block cipher and the given key                                    
// requires: cip is a valid BinStr, cipher is a block cipher            
// effects: allocates memory to a new BinStr
BinStr ECBdecrypt(BinStr cip, BlockCipher cipher) {
    assert(cip != NULL && cipher != NULL &&
           cip->length % cipher->blockSize == 0);
    BinStr msg = empty_BinStr(0);
    for(int i = 0; i < cip->length; i += cipher->blockSize) {
        BinStr to_app = snip(cip, i, i + cipher->blockSize - 1);
        to_app = set(to_app, (*cipher->decrypt)(to_app, cipher->key));
        msg = set(msg, append(msg, to_app));
        destroy_BinStr(to_app);
    }
    return msg;
}

// See BlockCipher.h for details
BinStr BlockEncrypt(BinStr msg, BinStr IV, BlockCipher cipher) {
    assert(msg != NULL && cipher != NULL);
    if(strcmp(cipher->encryptionMode, "ECB") == 0) {
        return ECBencrypt(msg, cipher);
    } else if (strcmp(cipher->encryptionMode, "CBC") == 0) {
        return CBCEncrypt(msg, IV, cipher);
    } else {
        return NULL;
    }
}

// See BlockCipher.h for details
BinStr BlockDecrypt(BinStr cip, BinStr IV, BlockCipher cipher) {
    assert(cip != NULL && cipher != NULL);
    if(strcmp(cipher->encryptionMode, "ECB") == 0) {
        return ECBdecrypt(cip, cipher);
    } else if (strcmp(cipher->encryptionMode, "CBC") == 0) {
        return CBCdecrypt(cip, IV, cipher);
    } else {
        return NULL;
    }
}
