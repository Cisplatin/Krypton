#include "Ciphers/DES.h"

int main() {
	BinStr a = ASCII_to_BinStr("this is a test message");
	BinStr k = ASCII_to_BinStr("mykeyisa");
	DESencrypt(a, k);
	return 0;

}
