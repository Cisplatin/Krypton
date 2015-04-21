/* BinStr.h - Written by Xenonstory on April 21, 2015 *
 * A structure used to store binary strings           */

struct binstr;

typedef binstr *BinStr;

// create_BinStr(bits, length) returns a BinStr with the length and bits given. User must free
//   returned BinStr.
// requires: bits is a valid BinStr
// effects: allocates memory to the new BinStr
// time: O(n), where n = length
BinStr create_BinStr(char *bits, unsigned int length);

// destroy_BinStr(str) frees the memory allocated to the given str.
// requires: str is a valid BinStr
// effects: frees memory associated to str
// time: O(1)
void destroy_BinStr(BinStr str);

// XOR(str1, str2) returns a new BinStr that is the XOR of the two given strings. The new BinStr
//   must be freed by the user.
// requires: str1 and str2 are valid BinStrs of the same length
// time: O(n), where n = length
BinStr XOR(BinStr str1, BinStr str2);
