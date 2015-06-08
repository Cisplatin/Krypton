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
	BinStr new = malloc(sizeof(struct binstr));
	new->bits = malloc(sizeof(bool) * length);
	for(int i = 0; i < length; i++) {
		if(bits[i] == '1') {
			new->bits[i] = 1;
		} else {
			new->bits[i] = 0;
		}
	}
	new->length = length;
	return new;
}

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
BinStr copy(BinStr str) {
	assert(str != NULL);
	BinStr new = empty_BinStr(str->length);
	for(int i = 0; i < str->length; i++) {
		new->bits[i] = str->bits[i];
	}
	return new;
}

// see BinStr.h for details
BinStr replace(BinStr str1, BinStr str2) {
	assert(str1 != NULL && str2 != NULL);
	destroy_BinStr(str1);
	return str2;
}

// see BinStr.h for details
BinStr flush(BinStr str) {
	assert(str != NULL);
	int leading = 0;
	while(!str->bits[leading]) {
		leading++;
	}	
	if(leading == 0) {
		return str;
	} else if(leading == str->length) {
		return empty_BinStr(1);
	} else {
		char *new = malloc(sizeof(char) * (str->length - leading));
		for(int i = leading; i < str->length; i++) {
			if(str->bits[i]) {
				new[i - leading] = '1';
			} else {
				new[i - leading] = '0';
			}
		}
		BinStr newStr = create_BinStr(new, str->length - leading);
		free(new);
		return newStr;
	}
}

// see BinStr.h for details
BinStr cut(BinStr str, int n) {
	assert(str != NULL && n > 0);
	BinStr new = empty_BinStr(n);
	for(int i = 1; i <= n && i < str->length; i++) {
		new->bits[n - i] = str->bits[str->length - i];
	}
	return new;
}

// see BinStr.h for details
int bytes(BinStr str) {
	assert(str != NULL);
	if(str->length % 8 == 0) {
		return str->length / 8;
	} else {
		return 1 + (str->length / 8);
	}
}

// see BinStr.h for details
BinStr getByte(BinStr str, int n) {
	assert(str != NULL && n <= str->length / 8 && n >= 0);
	BinStr new = empty_BinStr(8);
	int firstBit = (n * 8) - (str->length % 8);
	for(int i = firstBit; i <= firstBit + 8; i++) {
		if(i >= 0 && i < str->length) {
			new->bits[i - firstBit] = str->bits[i];
		}
	}
	return new;
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
BinStr OR(BinStr str1, BinStr str2) {
	assert(str1 != NULL && str2 != NULL && str1->length == str2->length);
	char bits[str1->length];
	for(int i = 0; i < str1->length; i++) {
		if(str1->bits[i] | str2->bits[i] == 0) {
			bits[i] = '0';
		} else {
			bits[i] = '1';
		}
	}
	BinStr new = create_BinStr(bits, str1->length);
	return new;
}

// see BinStr.h for details
BinStr AND(BinStr str1, BinStr str2) {
	assert(str1 != NULL && str2 != NULL && str1->length == str2->length);
	char bits[str1->length];
	for(int i = 0; i < str1->length; i++) {
		if(str1->bits[i] & str2->bits[i] == 0) {
			bits[i] = '0';
		} else {
			bits[i] = '1';
		}
	}
	BinStr new = create_BinStr(bits, str1->length);
	return new;
}

// see BinStr.h for details
BinStr shiftL(BinStr str) {
	assert(str != NULL);
	BinStr new = empty_BinStr(str->length + 1);
	for(int i = 0; i < str->length; i++) {
		new->bits[i] = str->bits[i];
	}
	return new;
}

// see BinStr.h for details
BinStr shiftR(BinStr str) {
	assert(str != NULL);
	BinStr new = empty_BinStr(str->length - 1);
	for(int i = 0; i < str->length - 1; i++) {
		new->bits[i] = str->bits[i];
	}
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

// see BinStr.h for details
BinStr modpwr(BinStr str, int n) {
	assert(str != NULL && n > 0);
	BinStr new = empty_BinStr(n);
	for(int i = 0; i < n; i++) {
		new->bits[i] = str->bits[i + (str->length - n)];
	}
	return new;
}

// see BinStr.h for details
int compare(BinStr str1, BinStr str2) {
	BinStr str3 = flush(str1), str4 = flush(str2);
	if(str3->length > str4->length) {
		return 1;
	} else if(str3->length < str4->length) {
		return -1;
	} else {
		for(int i = 1; i < str3->length; i++) {
			if(str3->bits[i] > str4->bits[i]) {
				return 1;
			} else if(str3->bits[i] < str4->bits[i]) {
				return -1;
			}
		}
	}
	return 0;
}

// see BinStr.h for details
BinStr add(BinStr str1, BinStr str2) {
	BinStr new = empty_BinStr(str1->length + str2->length);
	int offset = 0;
	for(int i = 1; i <= new->length; i++) {
		if(str1->length >= i && str1->bits[str1->length - i]) offset++;
		if(str2->length >= i && str2->bits[str2->length - i]) offset++;
		if((offset % 2 != 0 || offset == 1) && offset != 0) {
			new->bits[new->length - i] = true;
			offset--;
		}
		offset = offset / 2;
	}
	return replace(new, flush(new));
}

// see BinStr.h for details
BinStr modAdd(BinStr str1, BinStr str2, int n) {
	BinStr new = empty_BinStr(n);
	int offset = 0;
	for(int i = 1; i <= new->length; i++) {
		if(str1->length >= i && str1->bits[str1->length - i]) offset++;
		if(str2->length >= i && str2->bits[str2->length - i]) offset++;
		if((offset % 2 != 0 || offset == 1) && offset != 0) {
			new->bits[new->length - i] = true;
			offset--;
		}
		offset = offset / 2;
	}
	return new;
}
