/* BinStr.c - Written by Xenonstory on April 21, 2015 *
 * A structure used to store binary strings           */

#include "BinStr.h"
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// see BinStr.h for details
BinStr create_BinStr(char *bits, unsigned int length) {
	assert(bits != NULL);
	BinStr new = malloc(sizeof(struct binstr));
	new->bits = malloc(sizeof(bool) * length);
	for(int i = 0; i < length; i++) {
		new->bits[i] = bits[i] - '0';
	}
	new->length = length;
	return new;
}

// decToBinStr(num) returns the binary equivalent of the given decimal number.
// requires: 0 <= num
// effects: allocates memory to a new BinStr
// time: O(lg n)
BinStr decToBinStr(int num) {
	int sum = 0;
	int length = 0;
	while(num > 0) {
		sum *= 10;
		length++;
		if(num % 2 == 0) {
			sum += 1;
		}
		num /= 2;
	}
	char *bits = malloc(sizeof(char) * length);
	for(int i = 0; i < length; i++) {
		bits[i] = sum % 10;
		sum /= 10;
	}
	return create_BinStr(bits, length);
}

// hexToBinStr(num) returns the binary equivalent of the given hexidecimal character.
// requires: 0 <= num <= 9 || 'A' <= num <= 'F' || 'a' <= num <= 'f'
// effects: allocates memory to a new BinStr
// time: O(lg n)
BinStr hexToBinStr(char num) {
	assert(('0' <= num && num <= '9') || ('A' <= num && num <= 'F') 
			                  || ('a' <= num && num <= 'f'));
	if('0' <= num && num <= '9') {
		return decToBinStr(num - '0');
	} else if('A' <= num && num <= 'F') {
		return decToBinStr(num - 'A' + 10);
	} else {
		return decToBinStr(num - 'a' + 10);
	}
}

// see BinStr.h for details
BinStr hexStr_to_binStr(char *str); // TODO

// see BinStr.h for details
BinStr empty_BinStr(unsigned int length) {
	BinStr new = malloc(sizeof(struct binstr));
	new->bits = malloc(sizeof(bool) * length);
	for(int i = 0; i < length; i++) {
		new->bits[i] = 0;
	}
	new->length = length;
	return new;
}

// see BinStr.h for details
void destroy_BinStr(BinStr str) {
	assert(str != NULL);
	free(str->bits);
	free(str);
	return;
}

// see BinStr.h for details
BinStr XOR(BinStr str1, BinStr str2) {
	assert(str1 != NULL && str2 != NULL && str1->length == str2->length);
	char bits[str1->length];
	for(int i = 0; i < str1->length; i++) {
		if(str1->bits[i] ^ str2->bits[i] == 0) {
			bits[i] = '0';
		} else {
			bits[i] = '1';
		}
	}
	BinStr new = create_BinStr(bits, str1->length);
	return new;
}

// see BinStr.h for details
char *toString(BinStr str) {
	assert(str != NULL);
	char *new = malloc(sizeof(char) * (str->length + 1));
	for(int i = 0; i < str->length; i++) {
		new[i] = str->bits[i];
	}
	new[str->length] = '\0';
	return new;
}

// see BinStr.h for details
int toDecimal(BinStr str) {
	assert(str != NULL);
	if(str->length > 31) {
		return -1;
	} else {
		int sum = 0;
		int power2 = 1;
		for(int i = str->length - 1; i >= 0; i--) {
			if(str->bits[i] == 1) {
				sum += power2;
			}
			power2 *= 2;
		}
		return sum;
	}
}

// see BinStr.h for details
BinStr append(BinStr str1, BinStr str2) {
	assert(str1 != NULL && str2 != NULL);
	BinStr new = empty_BinStr(str1->length + str2->length);
	for(int i = 0; i < str1->length; i++) {
		new->bits[i] = str1->bits[i];
	}
	for(int i = 0; i < str2->length; i++) {
		new->bits[i + str1->length] = str2->bits[i];
	}
	return new;
}

// see BinStr.h for details
void print(BinStr str) {
	for(int i = 0; i < str->length; i++) {
		printf("%d", str->bits[i]);
	}
}

// see BinStr.h for details
int msb(BinStr str) {
	assert(str != NULL);
	return str->bits[0];
}

// see BinStr.h for details
int lsb(BinStr str) {
	assert(str != NULL);
	return str->bits[str->length - 1];
}
