/* HMAC.h - Created by Xenonstory on August 15, 2015
   An implementation of the HMAC algorithm          */

#ifndef HMAC_H
#define HMAC_H

#include "../Structures/BinStr.h"
#include "../Hashes/Generics/Hash.h"

// HMAC(str, key, hash_alg) returns the value of HMAC for the given BinStr 
//   using the given hashing algorithm
// requires: str and key are valid BinStrs, hash_alg is a valid hash
// effects: allocates memory to a new tag
BinStr HMAC(BinStr str, BinStr key, Hash hash_alg);

#endif
