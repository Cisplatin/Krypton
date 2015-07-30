/* BinMat.h - Written by Xenonstory on July 30, 2015  *
 * A structure used to store binary matrices          */

#ifndef BINMAT_H
#define BINMAT_H

#include <stdbool.h>
#include "BinStr.h"

struct binmat {
    BinStr **matrix;
    unsigned int rows;
    unsigned int cols;
};

typedef struct binmat *BinMat;

// empty_BinMat(rows, cols) returns a binary matrix with the given number
//   of rows and columns, with each element being the 0 BinStr.
// requires: rows, cols > 0
// effects: allocates memory to a new BinMat
BinMat empty_BinMat(int rows, int cols);

// destroy_BinMat(mat) frees all memory associated with the given BinMat
// requires: mat is a valid BinMat
// effects: frees memory associated with the given BinMat
void destroy_BinMat(BinMat mat);

// printMat(mat) prints out the given binary matrix
// requires: mat is a valid BinMat
// effects: prints out the given BinMat
void printMat(BinMat mat);

#endif

