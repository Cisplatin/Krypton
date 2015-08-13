/* BinStr.h - Written by Xenonstory on April 21, 2015 *
 * A structure used to store binary strings           */

#ifndef BINSTR_H
#define BINSTR_H

#include <stdbool.h>

extern const int BITS_PER_BYTE;
extern const int MAX_BYTE;

struct binstr {
	bool *bits;
	unsigned int length;
};

typedef struct binstr *BinStr;

// str_to_BinStr(bits, length) returns a BinStr with the bits and length given. 
//   User must free returned BinStr.
// requires: bits is a valid array of characters
// effects: allocates memory to the new BinStr
BinStr str_to_BinStr(char *bits, unsigned int length);

// int_to_BinStr(n) converts the given integer into a BinStr. User must free 
//   the returned BinStr.
// requires: n >= 0
// effects: allocates memory to a new BinStr
BinStr int_to_BinStr(int n);

// hex_to_BinStr(str) converts the given hexidecimal string into a BinStr. User 
//   must free the returned BinStr.
// requires: str is a valid hexidecimal string
// effects: allocates memory to a new BinStr
BinStr hex_to_BinStr(char *str);

// ASCII_to_BinStr(str) converts the given ASCII string into a BinStr. User 
//   must free the returned BinStr
// requires: str is a valid pointer
// effects: allocates memory to a new BinStr
BinStr ASCII_to_BinStr(char *str);

// empty_BinStr(length) returns a BinStr with the given length with 
//   all 0s as bits
// effects: allocates memory to the new BinStr. Must be freed by the user.
BinStr empty_BinStr(int length);

// destroy_BinStr(str) frees the memory allocated to the given str.
// requires: str is a valid BinStr
// effects: frees memory associated to str
void destroy_BinStr(BinStr str);

// copyStr(str) returns a copy of the given BinStr. Returned BinStr must be freed
//   by the user.
// requires: str is a valid BinStr
// effects: allocated memory to a new BinStr
BinStr copyStr(BinStr str);

// set(str1, str2) returns the second BinStr and frees the first one.
// effects: frees memory associated with str1 and repoints str1 to str2
BinStr set(BinStr str1, BinStr str2);

// flush(str) returns the given BinStr without leading zeroes
// requires: str is a valid BinStr
// effects: frees memory associated with the bits of BinStr, changes its length
BinStr flush(BinStr str);

// cut(str, n) returns a new BinStr with only the n least significant digits. 
//   Expect leading zeroes if n < str->length. User must free the 
//   returned BinStr
// requires: str is a valid BinStr, n > 0
BinStr cut(BinStr str, int n);

// snip(str, begin, end) returns a new BinStr that is a snippet of the given 
//   str from begin to end inclusively. User must free the returned BinStr.
// requires: str is a valid BinStr and begin <= end < str->length
BinStr snip(BinStr str, int begin, int end);

// bytes(str) returns the number of bytes that the given BinStr takes up.
// requires: str is a valid BinStr
int bytes(BinStr str);

// getByte(str, n) returns the nth byte of str. User must free the 
//   returned BinStr.
// requiers: str is a valid BinStr, 0 <= n <= str->length / 8
// effects: allocates memory to a new BinStr
BinStr getByte(BinStr str, int n);

// XOR(str1, str2) returns a new BinStr that is the XOR of the two given 
//   strings. User must free the returned BinStr.
// requires: str1 and str2 are valid BinStrs of the same length
// effects: allocated memory for a new BinStr
BinStr XOR(BinStr str1, BinStr str2);

// OR(str1, str2) returns a new BinStr that is the OR of the two given strings.
//   The new BinStr must be freed by the user.
// requires: str1 and str2 are valid BinStrs of the same length
// effects: allocated memory for a new BinStr
BinStr OR(BinStr str1, BinStr str2);

// AND(str1, str2) returns a new BinStr that is the AND of the two given 
//   strings. The new BinStr must be freed by the user.
// requires: str1 and str2 are valid BinStrs of the same length
// effects: allocated memory for a new BinStr
BinStr AND(BinStr str1, BinStr str2);

// rotateL(str, n) returns a BinStr that is the n-bit left rotation of
//   the given str.
// requires: str is a valid BinStr, n >= 0
BinStr rotateL(BinStr str, int n);

// rotateR(str, n) returns a BinStr that is the n-bit right rotation of
//   the given str.
// requires: str is a valid BinStr, n >= 0
BinStr rotateR(BinStr str, int n);

// shiftL(str) returns a new BinStr that is the shift left of str. 
//   The new BinStr must be freed by the user.
// requires: str is a valid BinStr
// effects: allocates memory for a new BinStr
BinStr shiftL(BinStr str);

// shiftR(str) returns a new BinStr that is the shift right of str.
//    The new BinStr must be freed by the user.
// requires: str is a valid BinStr
// effects: allocates memory for a new BinStr
BinStr shiftR(BinStr str);

// toString(str) returns a string with the bits in the given BinStr. 
//   The given string must be freed by the user.
// requires: str is a valid BinStr
// effects: allocated memory to a new string
char *toString(BinStr str);

// toASCII(str) returns a string with the ASCII conversion of the BinStr. 
//   The given string must bE freed by the user.
// requires: str is a valid BinStr
// effects: allocated memory to a new string
char *toASCII(BinStr str);

// toDecimal(str) returns a decimal representation of the given BinStr. 
//   If its too big, returns -1.
// requires: str is a valid BinStr
int toDecimal(BinStr str);

// append(str1, str2) returns a BinStr which consists of str1 appended to str2. 
//   The given string must be freed by the user.
// requires: str1 and str2 are valid BinStrs
// effects: allocated memory to a new BinStr
BinStr append(BinStr str1, BinStr str2);

// printStr(str) prints out the given str
// requires: str is a valid BinStr
// effects: prints out the given string
void printStr(BinStr str);

// msb(str) returns the most significant bit of the given string
// requires: str is a valid BinStr
int msb(BinStr str);

// lsb(str) returns the least significant bit of the given string
// requires: str is a valid BinStr
int lsb(BinStr str);

// parity(str) returns the parity of the given BinStr.
// requires: str is a valid BinStr
bool parity(BinStr str);

// number_of_seq(str, seg) returns the number of instances of seg in str
// requires: str is a valid BinStr, seg is a valid BinStr
int number_of_seq(BinStr str, BinStr seg);

// modpwr(str, n) returns a BinStr equivalent to str mod 2^n. New BinStr must 
//   be freed by the user.
// requires: str is a valid BinStr, n > 0
// effects: allocates memory to a new BinStr
BinStr modpwr(BinStr str, int n);

// compare(str1, str2) returns 1 if str1 > str2, -1 if str1 < str2, and 
//   0 if str1 = str2
// requires: str1 and str2 are valid BinStrs
int compare(BinStr str1, BinStr str2);

// add(str1, str2) returns the sum of the two given BinStrs. User must free 
//   the returned BinStr
// requires: str1 and str2 are valid BinStrs
BinStr add(BinStr str1, BinStr str2);

// modAdd(str1, str2, n) returns the sum of the two given BinStrs mod 2^n. User 
//   must be the BinStr
// requires: str1 and str2 are valid BinStrs, n >= 0
BinStr modAdd(BinStr str1, BinStr str2, int n);

// permutate(str, order, len) returns the given BinStr but with bits permutated
//   according to the given array of integers, order, where each element 
//   represents the bits to be put at that index. len is the length of the 
//   array. Set offset to 1 or 0 depending on your indexing strategy.
// requires: str is a valid BinStr, order is a valid array of ints, len >= 0, 
//           and offset >= 0
BinStr permutate(BinStr str, int *order, int len, int offset);

// reversePermutate(str, order, len, offset) reverse permutates the given BinStr
//   with similar attributes to the permutate() function.
// requires: str is a valid BinStr, order is a valid array of ints, len >= 0,
//           and offset >= 0
BinStr reversePermutate(BinStr str, int *order, int len, int offset);

// paddingMethod2(str, block) pads the given string using the official padding 
//   method two (i.e. append a 1, and then 0s) until the length of str is
//   a multiple of the given block size
// requires: str is a valid BinStr and block > 0
void paddingMethod2(BinStr str, int block);

#endif

