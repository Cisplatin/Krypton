/* OTP.h - Written by Xenonstory on April 21, 2015 *
 * An implementation of the One Time Pad cipher    */      

#ifndef OTP_H
#define OTP_H

#include "../Structures/BinStr.h"
#include "Generics/StreamCipher.h"

// OTP_initialize(key) returns an instance of a stream cipher ready for         
//   decryption and encryption using the given key and mode                     
// requires: key != NULL                                                        
// effects: allocates memory to a new OTP cipher                                
StreamCipher OTP_initialize(BinStr key);                                        
                                                                                
// OTP_destroy(cipher) destroys the given instance of the OTP block cipher       
// requires: cipher != NULL and cipher is an OTP stream cipher                    
// effects: frees memory used by the cipher                                    
void OTP_destroy(StreamCipher OTP);   

#endif
