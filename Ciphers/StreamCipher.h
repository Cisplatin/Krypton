/* StreamCipher.h - Written by Xenonstory on April 27, 2015 *
 * An implementation of a Stream Cipher                     */      

#include "..\Structures\BinStr.h"

// StreamEncrypt(msg, key) encrypts the given message using the given key via the stream cipher
//   with the given PRNG.
// requires: msg and key are valid BinStr and msg->length = key->length
// time: O(n) + P, where n = msg->length and P is the runtime of PRG
BinStr StreamEncrypt(BinStr msg, BinStr key, BinStr (*PRG)(BinStr, int));

// StreamDecrypt(cip, key) decrypts the given cipher text using the given key via the stream cipher
//   with the given PRNG.
// requires: cip and key are valid BinStr and cip->length = key->length
// time: O(n) + P, where n = cip->length and P is the runtime of PRG
BinStr StreamDecrypt(BinStr cip, BinStr key, BinStr (*PRG)(BinStr, int));
