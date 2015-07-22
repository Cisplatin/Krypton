# Krypton
An implementation of some cryptographic standards written in C. Currently availible standards are the One Time Pad, the RC4 stream cipher, and the Data Encryption Standard (DES).

Krypton should not be used for security purposes. Many constructions implemented in Krypton have been openly broken for many years, such as DES and RC4, both of which contain inherent security flaws. Moreover, there are many attacks (such as hardware attacks) that were not accounted for during the designing of Krypton.

## Example
All ciphers are designed to function in a similar manner. Following is an example of an implementation of the DES block cipher, which can be easily adapted to work with another cipher, such as RC4.

```C
#include <stdio.h>                                                              
#include "Ciphers/DES.h"                                                        
                                                                                
int main() {                                                                    
    // The message to be encrypted, "Krypton.", will be encrypted using DES,    
    // which requires an 8-byte key. Both are defined here.                     
    BinStr message = ASCII_to_BinStr("Krypton.");                               
    BinStr key     = ASCII_to_BinStr("8bytekey");                               
                                                                                
    // We now create the BlockCipher object: here I have used the ECB           
    // encryption mode                                                          
    BlockCipher DES = DES_initialize(key, "ECB");                               
    BinStr cipher = BlockEncrypt(message, DES);                                 
                                                                                
    // We now decrypt the cipher text                                           
    BinStr decrypted = BlockDecrypt(cipher, DES);                               
                                                                                
    // We can print out the message and the decrypted message in binary         
    // to make sure we get the same thing (we do!)                              
    printf("My original message was:\n");                                       
    printBin(message); printf("\n");                                            
    PRINTF("My cipher text was:\n");
    printBin(cipher); printf("\n");
    printf("My decrypted message was:\n");                                      
    printBin(decrypted); printf("\n");                                          
                                                                                
    // Time for garbage collection                                              
    destroy_BinStr(message);                                                    
    destroy_BinStr(key);                                                        
    destroy_BinStr(cipher);                                                     
    destroy_BinStr(decrypted);                                                  
    DES_destroy(DES);                                                           
                                                                                
    return 0;                                                                   
}     
```

To compile the above file, the following should be used:

```Shell
gcc Example.c Structures/BinStr.c Generics/StreamCipher.c Cipherss/DES.c -std=c99 -lm
```

## High Priority To-do list:
* Convert from c99 mode (to save encryption time)
* Try to remove -lm requirement as well? (store lg2)
* Add a hex-output method for BinStr
* Finish off all the various TODOs
