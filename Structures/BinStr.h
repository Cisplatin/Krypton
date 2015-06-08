/* BinStr.h - Written by Xenonstory on April 21, 2015 *
 * A structure used to store binary strings           */

#ifndef BINSTR_H
#define BINSTR_H

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

// copy(str) returns a copy of the given BinStr. Returned BinStr must be freed by the user.
// requires: str is a valid BinStr
// effects: allocated memory to a new BinStr
// time: O(n), where n = length
BinStr copy(BinStr str);

// replace(str1, str2) returns the second BinStr and frees the first one.
// requires: str1 and str2 are valid BinStr
// effects: frees memory associated with str1 and repoints str1 to str2
// time: O(n), where n = length
BinStr replace(BinStr str1, BinStr str2);

// flush(str) returns the given BinStr without leading zeroes
// requires: str is a valid BinStr
// effects: frees memory associated with the bits of BinStr, changes its length
// time: O(n), where n = length
BinStr flush(BinStr str);

// cut(str, n) returns a new BinStr with only the n least significant digits. Expect leading
//   zeroes if n < str->length. User must free the returned BinStr
// requires: str is a valid BinStr, n > 0
// time: O(n), where n = length
BinStr cut(BinStr str, int n);

// bytes(str) returns the number of bytes that the given BinStr takes up.
// requires: str is a valid BinStr
// time: O(1)
int bytes(BinStr str);

// getByte(str, n) returns the nth byte of str. User must free the returned BinStr.
// requiers: str is a valid BinStr, 0 <= n <= str->length / 8
// effects: allocates memory to a new BinStr
BinStr getByte(BinStr str, int n);

// XOR(str1, str2) returns a new BinStr that is the XOR of the two given strings. The new BinStr
//   must be freed by the user.
// requires: str1 and str2 are valid BinStrs of the same length
// effects: allocated memory for a new BinStr
// time: O(n), where n = length
BinStr XOR(BinStr str1, BinStr str2);

// OR(str1, str2) returns a new BinStr that is the OR of the two given strings. The new BinStr
//   must be freed by the user.
// requires: str1 and str2 are valid BinStrs of the same length
// effects: allocated memory for a new BinStr
// time: O(n), where n = length
BinStr OR(BinStr str1, BinStr str2);

// AND(str1, str2) returns a new BinStr that is the AND of the two given strings. The new BinStr
//   must be freed by the user.
// requires: str1 and str2 are valid BinStrs of the same length
// effects: allocated memory for a new BinStr
// time: O(n), where n = length
BinStr AND(BinStr str1, BinStr str2);

// shiftL(str) returns a new BinStr that is the shift left of str. The new BinStr must be freed by
//   the user.
// requires: str is a valid BinStr
// effects: allocates memory for a new BinStr
// time: O(n)
BinStr shiftL(BinStr str);

// shiftR(str) returns a new BinStr that is the shift right of str. The new BinStr must be freed by
//   the user.
// requires: str is a valid BinStr
// effects: allocates memory for a new BinStr
// time: O(n)
BinStr shiftR(BinStr str);

// toString(str) returns a string with the bits in the given BinStr. The given string must be freed
//   by the user.
// requires: str is a valid BinStr
// effects: allocated memory to a new string
// time: O(n), where n = length
char *toString(BinStr str);

// toDecimal(str) returns a decimal representation of the given BinStr. If its too big, returns -1.
// requires: str is a valid BinStr
// time: O(n), where n = length
int toDecimal(BinStr str);

// append(str1, str2) returns a BinStr which consists of str1 appended to str2. The given string
//   must be freed by the user.
// requires: str1 and str2 are valid BinStrs
// effects: allocated memory to a new BinStr
// time: O(n + m), where n = length of str1 and m = length of str2
BinStr append(BinStr str1, BinStr str2);

// print(str) prints out the given str
// requires: str is a valid BinStr
// effects: prints out the given string
// time: O(n), where n = length
void print(BinStr str);

// msb(str) returns the most significant bit of the given string
// requires: str is a valid BinStr
// time: O(1)
int msb(BinStr str);

// lsb(str) returns the least significant bit of the given string
// requires: str is a valid BinStr
// time: O(1)
int lsb(BinStr str);

// modpwr(str, n) returns a BinStr equivalent to str mod 2^n. New BinStr must be freed by the user.
// requires: str is a valid BinStr, n > 0
// effects: allocates memory to a new BinStr
// time: O(n)
BinStr modpwr(BinStr str, int n);

// compare(str1, str2) returns 1 if str1 > str2, -1 if str1 < str2, and 0 if str1 = str2
// requires: str1 and str2 are valid BinStrs
// time: O(n + m), where n and m are the respective lengths of str1 and str2
int compare(BinStr str1, BinStr str2);

// add(str1, str2) returns the sum of the two given BinStrs. User must free the returned BinStr
// requires: str1 and str2 are valid BinStrs
// time: O(n + m), where n and m are the respective lengths of str1 and str2
BinStr add(BinStr str1, BinStr str2);

// modAdd(str1, str2, n) returns the sum of the two given BinStrs mod 2^n. User must be the BinStr
// requires: str1 and str2 are valid BinStrs, n >= 0
// time: O(n)
BinStr modAdd(BinStr str1, BinStr str2, int n);

#endif

