/* MDC2.h - Created by Xenonstory on August 3
   An implementation of the MDC-2 cryptographic hash */

#ifndef MDC2_H
#define MDC2_H

#include "Generics/Hash.h"
#include "../Structures/BinStr.h"
#include "../Ciphers/DES.h"

// MDC2_initialize() returns a copy of an MDC-2 hash structure
// effects: allocates memory to a new hash structure
Hash MDC2_initialize();

// MDC2_destroy() destroys the given copy of the MDC-2 hash structure
// requires: MDC2 is a valid Hash
// effects: frees memory associated with MDC2
void MDC2_destroy(Hash MDC2);

#endif
