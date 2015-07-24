#include "Ciphers/DES.h"
#include <stdio.h>

int main() {
    BinStr m = ASCII_to_BinStr("abcdefgh");
    BinStr k = ASCII_to_BinStr("abcdefgh");
    BinStr IV = ASCII_to_BinStr("abcdefgh");

    BlockCipher DES = DES_initialize(k, "ECB");
    BinStr c = BlockEncrypt(m, IV, DES);
    BinStr d = BlockDecrypt(m, IV, DES);

    printBin(m); printf("\n"); printBin(c); printf("\n"); printBin(d);
    printf("\n");
    return 0;
}

