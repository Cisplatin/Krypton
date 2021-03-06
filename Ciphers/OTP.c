/* OTP.c - Written by Xenonstory on April 21, 2015 *
 * An implementation of the One Time Pad cipher    */

#include "OTP.h"
#include <assert.h>
#include <stdlib.h>

// OTP_PRNG(key, n) is the lamest function I've ever written. Just returns
//   the key after assuring everything is OK.
// requires: key is a valid BinStr, n >= 0
// effects: allocates memory to a new key
BinStr OTP_PRNG(BinStr key, int n) {
    assert(key != NULL && n >= 0);
    return copyStr(key);
}

// See OTP.h for details                                                        
StreamCipher OTP_initialize(BinStr key) {                                       
    assert(key != NULL);                                                        
    StreamCipher OTP = malloc(sizeof(struct streamcipher));                     
    OTP->key = key;                                                             
    OTP->PRNG = OTP_PRNG;                                                         
    return OTP;                                                                 
}                                                                               
                                                                                
// See OTP.h for details                                                        
void OTP_destroy(StreamCipher OTP) {                                            
    free(OTP);                                                                  
}                 
