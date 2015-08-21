# Krypton
An implementation of some cryptographic standards written in C. This includes standards such as cryptographic hashes, ciphers, pseudorandom number generators, and other primitives.

Krypton should not be used for security purposes. Many constructions implemented in Krypton have been openly broken for many years, such as DES and RC4, both of which contain inherent security flaws. Moreover, there are many attacks (such as hardware attacks) that were not accounted for during the designing of Krypton.

## Features
Krypton currently offers the following:
* Stream ciphers (OTP, RC4)
* Block ciphers (DES)
* Pseudo-random number generators (RC4, ANSI X9.17)
* Cryptographic hash functions (MDC-2, MD4)
* Message authentication codes (CBC-MAC)
* Statistical tests (Monobit, Two-bit)
* Various modes of encryption (ECB, CBC, CTR, OFB)
* Various structures (Binary strings, Binary matrices)

## Example
All ciphers are designed to function in a similar manner. Following is an example of an implementation of the DES block cipher, which can be easily adapted to work with another cipher, such as RC4.

```C
#include <stdio.h>
#include "Ciphers/DES.h"

int main() {
    // Our message, key and nonce are defined here.
    BinStr message = ASCII_to_BinStr("Jet fuel can't melt steel beams.");
    BinStr key     = ASCII_to_BinStr("@I[u*/7W");
    BinStr nonce   = ASCII_to_BinStr("&a3F");

    // We now create the BlockCipher struct and encrypt in CTR mode.
    BlockCipher DES = DES_initialize(key, "CTR");
    BinStr cipher = BlockEncrypt(message, nonce, DES);

    // We now decrypt the cipher text
    BinStr decrypted = BlockDecrypt(cipher, nonce, DES);

    // We can print out the message and the decrypted message in binary
    printf("My original message was:\n");
    printStr(message); printf("\n");
    printf("My cipher text was:\n");
    printStr(cipher); printf("\n");
    printf("My decrypted message was:\n");
    printStr(decrypted); printf("\n");

    // Time for garbage collection
    destroy_BinStr(message);
    destroy_BinStr(key);
    destroy_BinStr(cipher);
    destroy_BinStr(decrypted);
    DES_destroy(DES);

    return 0;
}

```

To compile the above file (named 'Example.c'), the following should be used:

```Bash
sh COMPILE.sh Example.c
```

## TODO:

- Fix MD4 (gives the wrong hash!)
