/* RC4.h - Written by Xenonstory on June 08, 2015 *
 * An implementation of the RC4 PRNG                     */      

#ifndef RC4_H
#define RC4_H

#include "../Structures/BinStr.h"
#include "../Generics/StreamCipher.h"

// RC4_initialize(key) returns an instance of a stream cipher ready for     
//   decryption and encryption using the given key and mode                     
// requires: key != NULL                      
// effects: allocates memory to a new RC4 cipher                                
StreamCipher RC4_initialize(BinStr key);                             
                                                                                
// RC4_destroy(cipher) destroys the given instance of the RC4 block cipher       
// requires: cipher != NULL and cipher is an RC4 stream cipher                    
// effects: frees memory used by the cipher                                     
void RC4_destroy(StreamCipher RC4);       

#endif
