/* BinStr.c - Written by Xenonstory on April 21, 2015 *
 * A structure used to store binary strings           */

#include "BinStr.h"
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

const int BITS_PER_BYTE = 8;
const int MAX_BYTE = 256;

char HEX_CONVERT[][16] = {"0000", "0001", "0010", "0011", "0100", "0101", 
                          "0110", "0111", "1000", "1001", "1010", "1011",
                          "1100", "1101", "1110", "1111"};

// see BinStr.h for details
BinStr str_to_BinStr(char *bits, unsigned int length) {
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
BinStr int_to_BinStr(int n) {
	assert(n >= 0);
    if(n == 0) {
        return empty_BinStr(1);
    } else {
	    int length = log(n) / log(2) + 1;
	    BinStr new = empty_BinStr(length);
	    unsigned int powerOfTwo = 1;
	    for(int i = 0; i < length - 1; i++) {
		    powerOfTwo *= 2;
	    }
	    for(int i = 0; i < length; i++) {
		    if(n >= powerOfTwo) {
			    n -= powerOfTwo;
			    new->bits[i] = 1;
		    }
	    	powerOfTwo /= 2;
	    }
	    return new;
    }
}

// see BinStr.h for details
BinStr hex_to_BinStr(char *str) {
    assert(str != NULL);
    int length = strlen(str);
    BinStr new = empty_BinStr(length * 4);
    for(int i = 0; i < length; i++) {
        char *hex;
        if('0' <= str[i] && str[i] <= '9') {
            hex = HEX_CONVERT[(str[i] - '0')];
        } else if('A' <= str[i] && str[i] <= 'F') {
            hex = HEX_CONVERT[(str[i] - 'A') + 10];
        } else if('a' <= str[i] && str[i] <= 'f') {
            hex = HEX_CONVERT[(str[i] - 'a') + 10];
        }
        for(int j = 0; j < 4; j++) {
            if(hex[j] == '1') {
                new->bits[i * 4 + j] = true;
            }
        }
    }
    return new;
}

// see BinStr.h for details
BinStr ASCII_to_BinStr(char *str) {
	assert(str != NULL);
	int length = strlen(str);
	BinStr new = empty_BinStr(0); 
	for(int i = 0; i < length; i++) {
		BinStr app = int_to_BinStr((int)str[i]);
		app = set(app, cut(app, BITS_PER_BYTE));
		new = set(new, append(new, app));
		destroy_BinStr(app);
	} 
	return new;
}

// see BinStr.h for details
BinStr empty_BinStr(int length) {
	assert(length >= 0);
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
BinStr copyStr(BinStr str) {
	assert(str != NULL);
	BinStr new = empty_BinStr(str->length);
	for(int i = 0; i < str->length; i++) {
		new->bits[i] = str->bits[i];
	}
	return new;
}

// see BinStr.h for details
BinStr set(BinStr str1, BinStr str2) {
	if(str1 != NULL) {
        destroy_BinStr(str1);
    }
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
		BinStr newStr = str_to_BinStr(new, str->length - leading);
		free(new);
		return newStr;
	}
}

// see BinStr.h for details
BinStr cut(BinStr str, int n) {
	assert(str != NULL && n > 0);
	BinStr new = empty_BinStr(n);
	for(int i = 1; i <= n && i <= str->length; i++) {
		new->bits[n - i] = str->bits[str->length - i];
	}
	return new;
}

// see BinStr.h for details
BinStr snip(BinStr str, int begin, int end) {
	assert(str != NULL && begin <= end && end <= str->length);
	BinStr new = empty_BinStr(end - begin + 1);
	for(int i = 0; i < new->length; i++) {
		new->bits[i] = str->bits[i + begin];
	}
	return new;
}

// see BinStr.h for details
int bytes(BinStr str) {
	assert(str != NULL);
	if(str->length % BITS_PER_BYTE == 0) {
		return str->length / BITS_PER_BYTE;
	} else {
		return 1 + (str->length / BITS_PER_BYTE);
	}
}

// see BinStr.h for details
BinStr getByte(BinStr str, int n) {
	assert(str != NULL && n <= str->length / BITS_PER_BYTE && n >= 0);
	BinStr new = empty_BinStr(BITS_PER_BYTE);
	int firstBit = (n * BITS_PER_BYTE) - (str->length % BITS_PER_BYTE);
	for(int i = firstBit; i <= firstBit + BITS_PER_BYTE; i++) {
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
	BinStr new = str_to_BinStr(bits, str1->length);
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
	BinStr new = str_to_BinStr(bits, str1->length);
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
	BinStr new = str_to_BinStr(bits, str1->length);
	return new;
}

// see BinStr.h for details
BinStr rotateL(BinStr str, int n) {
	assert(str != NULL && n >= 0);
	n %= str->length;
	BinStr new = snip(str, n, str->length - 1);
	BinStr back = snip(str, 0, n - 1);
	new = set(new, append(new, back));
	destroy_BinStr(back);
	return new;
}

// see BinStr.h for details
BinStr rotateR(BinStr str, int n) {
    assert(str != NULL && n >= 0);
    n %= str->length;
    BinStr new = snip(str, n, str->length - 1);
    BinStr back = snip(str, 0, n - 1);
    new = set(new, append(back, new));
    destroy_BinStr(back);
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
char *toASCII(BinStr str) {
	char *new = malloc(sizeof(char) * ((str->length / BITS_PER_BYTE) + 2));
	for(int i = 0; i < (str->length / BITS_PER_BYTE) + 1; i++) {
		new[i] = (char)toDecimal(getByte(str, i));
	}
	new[(str->length / 8) + 1] = '\0';
	return new;
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
void printStr(BinStr str) {
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
bool parity(BinStr str) {
	assert(str != NULL);
	bool result = 0;
	for(int i = 0; i < str->length; i++) {
		result = result ^ str->bits[i];
	}
	return result;
}

// See BinStr.h for details
int number_of_seq(BinStr str, BinStr seq) {
    assert(str != NULL && seq != NULL && str->length > seq->length);
    int count = 0;
    for(int i = 0; i < str->length; i++) {
        bool found = 1;
        for(int j = 0; j < seq->length && found; j++) {
            if(str->bits[i + j] != seq->bits[j]) {  
                found = 0;
            }
        }
        if(found) count++; 
    }
    return count;
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
	return set(new, flush(new));
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

// see BinStr.h for details
BinStr permutate(BinStr str, int *order, int len, int offset) {
	assert(str != NULL && order != NULL && len >= 0 && offset >= 0);
	BinStr new = empty_BinStr(len);
	for(int i = 0; i < len; i++) {
		assert(order[i] - offset < str->length);
		new->bits[i] = str->bits[order[i] - offset];
	}
	return new;
}

// see BinStr.h for details
BinStr reversePermutate(BinStr str, int *order, int len, int offset) {
	assert(str != NULL && order != NULL && len >= 0 && offset >= 0);
	BinStr new = empty_BinStr(len);
	for(int i = 0; i < len; i++) {
		assert(order[i] - offset < str->length);
		new->bits[order[i] - offset] = str->bits[i];
	}
	return new;
}

// See BinStr.h for details
void paddingMethod2(BinStr str, int block) {
    assert(str != NULL && block > 0);
    BinStr zero = str_to_BinStr('0', 1);
    BinStr one = str_to_BinStr('1', 1);
    str = set(str, append(str, zero));
    while(str->length % block != 0) {
        str = set(str, append(str, one));
    }
    return str;
}

// see BinStr.h for details
void paddingZero(BinStr str, int block) {
    assert(str != NULL && block > 0);
    BinStr zero = str_to_BinStr('0', 1);
    while(str->length % block != 0) {
        str = set(str, append(str, zero));
    }
    return str;
}
