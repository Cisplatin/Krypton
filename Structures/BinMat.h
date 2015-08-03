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

// BinStr_to_BinMat(str, rows, cols) returns a binary matrix, where the
//   elements correspond to the given string split into the appropriate
//   amount of cells evenly.
// requires: str is a valid BinStr, 0 < rows, cols, and str can be evenly
//           split into the given number of rows and cols
BinMat BinStr_to_BinMat(BinStr str, int rows, int cols);

// BinMat_to_BinStr(mat) returns a binstr that is the concatenation of
//   all binary strings in the given matrix
// requires: mat is a valid BinMat
BinStr BinMat_to_BinStr(BinMat mat);

// destroy_BinMat(mat) frees all memory associated with the given BinMat
// requires: mat is a valid BinMat
// effects: frees memory associated with the given BinMat
void destroy_BinMat(BinMat mat);

// copyMat(mat) returns a copy of the given binary matrix
// requires: mat is a valid BinMat
// effects: allocates memory to a new binary matrix
BinMat copyMat(BinMat mat);

// apply(mat, func) applies the given function to all elements in the given
//   matrix
// requires: mat is a valid BinMat
void apply(BinMat mat, BinStr (*func)(BinStr));

// strwise(func, a, b) returns a binary matrix which is the result of a and 
//   be being binstr-wise func'd
// requires: a and b are valid BinMats, a->rows == b->rows, a->cols == b->cols
// effects: allocates memory to a new binary matrix
BinMat strwise(BinStr (*func)(BinStr, BinStr), BinMat a, BinMat b);

// setMat(mat, row, col, str) sets the matrix at the given row and column
//   to the given BinStr
// requires: mat is a valid BinMat, 0 <= row, col <= mat->rows, mat->cols
// effects: frees the BinStr at row/col, replaces it with str
void setMat(BinMat mat, int row, int col, BinStr str);

// getMat(mat, row, col) returns the BinStr at the given row and column
// requires: mat is a valid BinMat, 0 <= row, col <= mat->rows, math->cols
BinStr getMat(BinMat mat, int row, int col);

// swapRows(mat, i, j) swaps the rows i and j in the matrix
// requires: mat is a valid BinMat, 0 <= i, j <= mat->rows
void swapRows(BinMat mat, int i, int j);

// swapCols(mat, i, j) swaps the columns i and j in the matrix
// requires: mat is a valid BinMat, 0 <= i, j <= mat->cols
void swapCols(BinMat mat, int i, int j);

// rotateRowR(mat, row) rotates the row'th row in mat by one
// requires: mat is a valid BinMat, 0 <= row < mat->rows
void rotateRowR(BinMat mat, int row);

// rotateRowL(mat, row) rotates the row'th row in mat by one
// requires: mat is a valid BinMat, 0 <= row < mat->rows
void rotateRowL(BinMat mat, int row);

// printMat(mat) prints out the given binary matrix
// requires: mat is a valid BinMat
// effects: prints out the given BinMat
void printMat(BinMat mat);

#endif

