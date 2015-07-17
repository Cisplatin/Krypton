/* BlockCipher.c - Written by Xenonstory on July 17, 2015 *
 * An implementation of a generic block cipher            */

#include "BlockCipher.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// ECBencrypt(msg, key, cipher, blockSize) encrypts the given message using an  
//   ECB mode block cipher and the given key                                    
// requires: msg and key are valid BinStrs, cipher is a block cipher            
BinStr ECBencrypt(BinStr msg, BinStr key, BinStr (*cipher)(BinStr, BinStr),     
                  int blockSize) {                                              
    assert(msg != NULL && key != NULL && blockSize > 0 &&                       
           msg->length % blockSize == 0);                                       
    BinStr cip = empty_BinStr(0);                                               
    for(int i = 0; i < msg->length; i += blockSize) {                           
        BinStr to_app = snip(msg, i, i + blockSize - 1);                        
        to_app = replace(to_app, (*cipher)(to_app, key));                       
        cip = replace(cip, append(cip, to_app));                                
        destroy_BinStr(to_app);                                                 
    }                                                                           
    return cip;                                                                 
}                                                                               
                                                                                
// ECBdecrypt(cip, key, cipher, blockSize) decrypts the given message using an  
//   ECB mode block cipher and the given key                                    
// requires: msg and key are valid BinStrs, cipher is a block cipher            
BinStr ECBdecrypt(BinStr cip, BinStr key, BinStr (*cipher)(BinStr, BinStr),     
                  int blockSize) {                                              
    assert(cip != NULL && key != NULL && blockSize > 0 &&                       
           cip->length % blockSize == 0);                                       
    BinStr msg = empty_BinStr(0);                                               
    for(int i = 0; i < cip->length; i += blockSize) {                           
        BinStr to_app = snip(cip, i, i + blockSize - 1);                        
        to_app = replace(to_app, (*cipher)(to_app, key));                       
        msg = replace(cip, append(msg, to_app));                                
        destroy_BinStr(to_app);                                                 
    }                                                                           
    return msg;                                                                 
}                                                                               

// See BlockCipher.h for details
BinStr BlockEncrypt(BinStr msg, BinStr key, BinStr (*cipher)(BinStr, BinStr),
                    string mode, int blockSize) {
	assert(msg != NULL && key != NULL && blockSize > 0);
    if(strcmp(mode, "ECB") == 0) {
        return ECBencrypt(msg, key, cipher, blockSize);
    }
    return NULL; // TODO: Don't just return NULL, throw an error
}

// See BlockCipher.h for details
BinStr BlockDecrypt(BinStr cip, BinStr key, BinStr (*cipher)(BinStr, BinStr),
                    string mode, int blockSize) {
	assert(cip != NULL && key != NULL && blockSize > 0);
    if(strcmp(mode, "ECB") == 0) {                                              
        return ECBdecrypt(cip, key, cipher, blockSize);                         
    }                                                                           
    return NULL; // TODO: Don't just return NULL, throw an error    
}
