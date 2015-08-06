/* MDC4.h - Created by Xenonstory on August 5
   An implementation of the MDC-4 cryptographic hash */

#ifndef MDC4_H
#define MDC4_H

#include "Generics/Hash.h"
#include "../Structures/BinStr.h"
#include "../Ciphers/DES.h"

// MDC4_initialize() returns a copy of an MDC-4 hash structure
// effects: allocates memory to a new hash structure
Hash MDC4_initialize();

// MDC4_destroy() destroys the given copy of the MDC-4 hash structure
// requires: MDC4 is a valid Hash
// effects: frees memory associated with MDC2
void MDC4_destroy(Hash MDC4);

#endif
