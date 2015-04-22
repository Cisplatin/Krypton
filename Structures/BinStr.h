/* BinStr.h - Written by Xenonstory on April 21, 2015 *
 * A structure used to store binary strings           */

#include <stdbool.h>

struct binstr {
	bool *bits;
	unsigned int length;
};

typedef struct binstr *BinStr;

// create_BinStr(bits, length) returns a BinStr with the length and bits given. User must free
//   returned BinStr.
// requires: bits is a valid BinStr
// effects: allocates memory to the new BinStr
// time: O(n), where n = length
BinStr create_BinStr(char *bits, unsigned int length);

// empty_BinStr(length) returns a BinStr with the given length with all 0s as bits
// effects: allocates memory to the new BinStr. Must be freed by the user.:x
// time: O(n), where n = length
BinStr empty_BinStr(unsigned int length);

// destroy_BinStr(str) frees the memory allocated to the given str.
// requires: str is a valid BinStr
// effects: frees memory associated to str
// time: O(1)
void destroy_BinStr(BinStr str);

// XOR(str1, str2) returns a new BinStr that is the XOR of the two given strings. The new BinStr
//   must be freed by the user.
// requires: str1 and str2 are valid BinStrs of the same length
// effects: allocated memory for a new BinStr
// time: O(n), where n = length
BinStr XOR(BinStr str1, BinStr str2);

// toString(str) returns a string with the bits in the given BinStr. The given string must be freed
//   by the user.
// requires: str is a valid BinStr
// effects: allocated memory to a new string
// time: O(n), where n = length
char *toString(BinStr str);

// print(str) prints out the given str
// requires: str is a valid BinStr
// effects: prints out the given string
// time: O(n), where n = length
void print(BinStr str);
