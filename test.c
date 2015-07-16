#include "Ciphers/DES.h"
#include <stdio.h>

int main() {
    printf("a");
    BinStr block = ASCII_to_BinStr("abcdefgh");
    BinStr key = ASCII_to_BinStr("abcdefgh");
    printf("a");
    BinStr b = encryptBlock(block, key);
    print(b);
    return 0;
}
