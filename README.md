# Krypton
An implementation of some cryptographic standards written in C. Currently availible standards are the One Time Pad, the RC4 stream cipher, and the Data Encryption Standard (DES).

Krypton should not be used for security purposes. Many constructions implemented in Krypton have been openly broken for many years, such as DES and RC4, both of which contain inherent security flaws. Moreover, there are many attacks (such as hardware attacks) that were not accounted for during the designing of Krypton.

## Example
All ciphers are designed to function in a similar manner. Following is an example of an implementation of the RC4 stream cipher, which can be easily adapted to work with another cipher, such as DES.

```C
#include <stdio.h>                                                              
#include "Ciphers/RC4.h"                                                        
                                                                                
int main() {                                                                    
    // The message to be encrypted, "Krypton.", will be encrypted using RC4,    
    // as well as the defined key.
    BinStr message = ASCII_to_BinStr("This is my message to encrypt.");                               
    BinStr key     = ASCII_to_BinStr("This is my key.");                               
                                                                                
    // We now create the StreamCipher struct                                       
    StreamCipher RC4 = RC4_initialize(key);                               
    BinStr cipher = StreamEncrypt(message, RC4);                                 
                                                                                
    // We now decrypt the cipher text                                           
    BinStr decrypted = StreamDecrypt(cipher, RC4);;                               
                                                                                
    // We can print out the message and the decrypted message in binary         
    // to make sure we get the same thing (we do!)                              
    printf("My original message was:\n");                                       
    printBin(message); printf("\n");                                            
    printf("My cipher text was:\n");
    printBin(cipher); printf("\n");
    printf("My decrypted message was:\n");                                      
    printBin(decrypted); printf("\n");                                          
                                                                                
    // Time for garbage collection                                              
    destroy_BinStr(message);                                                    
    destroy_BinStr(key);                                                        
    destroy_BinStr(cipher);                                                     
    destroy_BinStr(decrypted);                                                  
    RC4_destroy(RC4);                                                           
                                                                                
    return 0;                                                                   
}     
```

To compile the above file, the following should be used:

```Shell
gcc Example.c Structures/BinStr.c Generics/StreamCipher.c Cipherss/RC4.c -std=c99 -lm
```

## Upcoming features:
* More block cipher modes of encryption (CBC, CTR, etc.)
* The AES block cipher
* A text file input/output method for BinStr
* A hexadecimal input/output method for BinStr
