/* TDES.h - Written by Xenonstory on July 29, 2015          *
 * An implementation of the Triple Data Encryption Standard */      

#ifndef TDES_H
#define TDES_H

#include "../Structures/BinStr.h"
#include "../Generics/BlockCipher.h"

// TDES_initialize(key, mode) returns an instance of a block cipher ready for
//   decryption and encryption using the given key and mode
// requires: key != NULL, mode is a valid mode (ECB, etc.)
// effects: allocates memory to a new TDES cipher
BlockCipher TDES_initialize(BinStr key, char* mode);

// TDES_destroy(cipher) destroys the given instance of the TDES block cipher
// requires: cipher != NULL and cipher is a TDES block cipher
// effects: frees memory used by the cipher
void TDES_destroy(BlockCipher TDES);

#endif
