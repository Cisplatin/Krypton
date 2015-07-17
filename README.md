# Krypton
An implementation of some cryptographic standards written in C. Currently availible standards are the One Time Pad, the RC4 stream cipher, and the Data Encryption Standard (DES).

Krypton should not be used for security purposes. Many constructions implemented in Krypton have been openly broken for many years, such as DES and RC4, both of which contain inherent security flaws. Moreover, there are many attacks (such as hardware attacks) that were not accounted for during the designing of Krypton.

## Example
Following is an example of an implementation of the RC4 stream cipher:

```
#include <stdio.h>
#include "Ciphers/StreamCipher.h"
#include "PRGs/RC4.h"

int main() {
	BinStr msg = ASCII_to_BinStr("This is my plain text, which will be encrypted.");
	BinStr key = ASCII_to_BinStr("This is my key.");
	BinStr cip = StreamEncrypt(msg, key, RC4);

	printf("\nThe cipher text is: "); print(cip);

	BinStr decrypt = StreamDecrypt(cip, key, RC4);

	printf("\nThe plain text is: "); print(decrypt);

	return 0;
}
```

To compile the above file, the following should be used:

```
gcc Example.c Structures/BinStr.c Ciphers/StreamCipher.c PRGs/RC4.c -std=c99 -lm
```

## To-do list:
* Rest of DES algorithm
* Generic method of using different block cipher modes
