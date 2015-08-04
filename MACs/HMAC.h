/* HMAC.h - Created by Xenonstory on August 4th, 2015
   HMAC is an implementation of the HMAC authentication code */

#include "../Structures/BinStr.h"

// HMAC(msg, key, hash) returns the HMAC tag for the given msg using the given
//   key, using the hash function supplied.
// requires: msg and key are valid BinStrs, hash is a cryptographic hash function
BinStr HMAC(BinStr msg, BinStr key, BinStr (*hash)(BinStr)); 
