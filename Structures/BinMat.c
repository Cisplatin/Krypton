/* BinMat.c - Written by Xenonstory on July 30, 2015 *
 * A structure used to store binary matrcies         */

#include "BinMat.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// see BinMat.h for details
BinMat empty_BinMat(int rows, int cols) {
    BinMat new = malloc(sizeof(struct binmat));
    new->rows = rows;
    new->cols = cols;
    new->matrix = malloc(sizeof(BinStr) * cols);
    for(int i = 0; i < rows; i++) {
        new->matrix[i] = malloc(sizeof(BinStr) * cols);
        for(int j = 0; j < cols; j++) {
            new->matrix[i][j] = empty_BinStr(0);
        }
    }
    return new;
}

// see BinMat.h for details
void printMat(BinMat mat) {
    assert(mat != NULL);
    for(int i = 0; i < mat->rows; i++) {
        for(int j = 0; j < mat->cols; j++) {
            printStr(mat->matrix[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    return;
}
