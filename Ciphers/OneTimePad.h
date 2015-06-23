/* OneTimePad.h - Written by Xenonstory on April 21, 2015 *
 * An implementation of the One Time Pad cipher           */      

#ifndef ONETIMEPAD_H
#define ONETIMEPAD_H

#include "../Structures/BinStr.h"

// OTPencrypt(msg, key) encrypts the given message using the given key via the OTP.
// requires: msg and key are valid BinStr and msg->length = key->length
BinStr OTPencrypt(BinStr msg, BinStr key);

// OTPdecrypt(cip, key) decrypts the given cipher text using the given key via the OTP.
// requires: cip and key are valid BinStr and cip->length = key->length
BinStr OTPdecrypt(BinStr cip, BinStr key);

#endif
