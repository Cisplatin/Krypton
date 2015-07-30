/* BinMat.c - Written by Xenonstory on July 30, 2015 *
 * A structure used to store binary matrcies         */

#include "BinMat.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// see BinMat.h for details
BinMat empty_BinMat(int rows, int cols) {
    assert(rows >= 0 && cols >= 0);
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
void destroy_BinMat(BinMat mat) {
    assert(mat != NULL);
    for(int i = 0; i < mat->rows; i++) {
        for(int j = 0; j < mat->cols; j++) {
            destroy_BinStr(mat->matrix[i][j]);
        }
        free(mat->matrix[i]);
    }
    free(mat->matrix);
    free(mat);
}

// see BinMat.h for details
void setMat(BinMat mat, int row, int col, BinStr str) {
    assert(mat != NULL && 0 <= row && 0 <= col && 
           row < mat->rows && col < mat->cols);
    BinStr str_copy = copy(str);
    mat->matrix[row][col] = set(mat->matrix[row][col], str_copy);
    return;
}

// see BinMat.h for details
void printMat(BinMat mat) {
    assert(mat != NULL);
    for(int i = 0; i < mat->rows; i++) {
        for(int j = 0; j < mat->cols; j++) {
            printStr(mat->matrix[i][j]);
            printf("\t");
        }
        printf("\n");
    }
    return;
}
