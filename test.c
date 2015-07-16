#include "Ciphers/DES.h"
#include <stdio.h>

int main() {

    BinStr block = ASCII_to_BinStr("abcdefgh");
    BinStr key = ASCII_to_BinStr("abcdefgh");

    BinStr b = encryptBlock(block, key);
    print(b);printf("\n");
    return 0;
}
