#include "Structures/BinStr.h"
#include "PRGs/RC4.h"

int main() {
	BinStr a = create_BinStr("10111111011", 11);
        print(RC4(a, 15));
	return 0;
}
