/* BinMat.h - Written by Xenonstory on July 30, 2015  *
 * A structure used to store binary matrices          */

#ifndef BINMAT_H
#define BINMAT_H

#include <stdbool.h>
#include "BinStr.h"

typedef struct binstr **BinMat;

// empty_BinMat(rows, cols) returns a binary matrix with the given number
//   of rows and columns, with each element being the 0 BinStr.
// requires: rows, cols > 0
// effects: allocates memory to a new BinMat
BinMat empty_BinMat(int rows, int cols);

#endif

