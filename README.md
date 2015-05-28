# Krypton
An implementation of some cryptographic ciphers written in C. Following is an
example of an implementation of a one time pad on a binary string:

```
#include <stdio.h>
#include "Ciphers\OneTimePad.h"

int main() {
	BinStr msg = create_BinStr("101110", 6); // This is my plain text
	BinStr key = create_BinStr("100101", 6); // This is my key
	BinStr cip = OTPencrypt(msg, key);       // This is my cipher text

	printf("\nThe cipher text is: "); print(cip);

	BinStr decrypt = OTPdecrypt(cip, key);   // This is the decryption

	printf("\nThe plain text is: "); print(decrypt);

	return 0;
}
```

To compile the above file, the following should be used:

```
gcc Example.c Structures/BinStr.c Ciphers/OneTimePad.c -std=c99
```