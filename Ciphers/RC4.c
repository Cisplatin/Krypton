/* RC4.c - Written by Xenonstory on June 8, 2015 *
 * An implementation of the RC4 stream cipher    */

#include "RC4.h"
#include <assert.h>
#include <stdlib.h>

// See RC4.h for details                                                     
StreamCipher RC4_initialize(BinStr key) {                            
    assert(key != NULL);
    StreamCipher RC4 = malloc(sizeof(struct streamcipher));                       
    RC4->key = key;                                                             
    RC4->generated = empty_BinStr(0);
    RC4->PRNG = RC4_PRNG;
    return RC4;                                                                 
}                                                                               
                                                                                
// See RC4.h for details                                                        
void RC4_destroy(StreamCipher RC4) { 
    free(RC4->generated);
    free(RC4);                                                                                                                     
}                          
