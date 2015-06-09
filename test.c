#include "Structures/BinStr.h"
#include "PRGs/RC4.h"

int main() {
	BinStr a = create_BinStr("10110010111111011", 11);
        print(RC4(a, 13));
	return 0;
}
