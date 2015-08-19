#include "Hashes/MD4.h"
#include <stdio.h>

int main() {
    Hash MD4 = MD4_initialize();
    BinStr msg = str_to_BinStr("", 0);    
    
    BinStr tag = hash(msg, MD4);
    printStr(tag); printf("\n");

    MD4_destroy(MD4);
    return 0;
}
