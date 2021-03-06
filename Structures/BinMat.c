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
BinMat BinStr_to_BinMat(BinStr str, int rows, int cols) {
    assert(str != NULL && rows > 0 && cols > 0);
    int bits = str->length / (rows * cols);
    assert(bits * rows * cols == str->length);
    BinMat new = malloc(sizeof(struct binmat));
    new->rows = rows;
    new->cols = cols;
    new->matrix = malloc(sizeof(BinStr) * cols);
    for(int i = 0; i < rows; i++) {
        new->matrix[i] = malloc(sizeof(BinStr) * cols);
        for(int j = 0; j < cols; j++) {
            new->matrix[i][j] = snip(str, bits * (i * cols + j), 
                                          bits * (i * cols + j + 1) - 1);
        }
    }
    return new;

}

// see BinMat.h for details
BinStr BinMat_to_BinStr(BinMat mat) {
    assert(mat != NULL);
    BinStr new = empty_BinStr(0);
    for(int row = 0; row < mat->rows; row++) {
        for(int col = 0; col < mat->cols; col++) {
            new = set(new, append(new, mat->matrix[row][col]));
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
BinMat copyMat(BinMat mat) {
    assert(mat != NULL);
    BinMat new = malloc(sizeof(struct binmat));
    new->rows = mat->rows;
    new->cols = mat->cols;
    new->matrix = malloc(sizeof(BinStr) * mat->cols);
    for(int i = 0; i < mat->rows; i++) {
        new->matrix[i] = malloc(sizeof(BinStr) * mat->cols);
        for(int j = 0; j < mat->cols; j++) {
            new->matrix[i][j] = copyStr(mat->matrix[i][j]);
        }
    }
    return new;
}

// see BinMat.h for details
void apply(BinMat mat, BinStr (*func)(BinStr)) {
    assert(mat != NULL);
    for(int i = 0; i < mat->rows; i++) {
        for(int j = 0; j < mat->cols; j++) {
            mat->matrix[i][j] = set(mat->matrix[i][j], func(mat->matrix[i][j]));
        }   
    }
}

// see BinMat.h for details
BinMat strwise(BinStr (*func)(BinStr, BinStr), BinMat a, BinMat b) {
    assert(a != NULL && b != NULL && a->rows == b->rows && a->cols == b->cols);
    BinMat new = malloc(sizeof(struct binmat));
    new->rows = a->rows;
    new->cols = a->cols;
    new->matrix = malloc(sizeof(BinStr) * a->cols);
    for(int i = 0; i < a->rows; i++) {
        new->matrix[i] = malloc(sizeof(BinStr) * a->cols);
        for(int j = 0; j < a->cols; j++) {
            new->matrix[i][j] = func(a->matrix[i][j], b->matrix[i][j]);
        }
    }
    return new;
}

// see BinMat.h for details
void setMat(BinMat mat, int row, int col, BinStr str) {
    assert(mat != NULL && 0 <= row && 0 <= col && 
           row < mat->rows && col < mat->cols);
    BinStr str_copy = copyStr(str);
    mat->matrix[row][col] = set(mat->matrix[row][col], str_copy);
    return;
}

// see BinMat.h for details
BinStr getMat(BinMat mat, int row, int col) {
    assert(mat != NULL && 0 <= row && 0 <= col &&
           row < mat->rows && col < mat->cols);
    return mat->matrix[row][col];
}

// see BinMat.h for details
void swapRows(BinMat mat, int i, int j) {
    assert(mat != NULL && 0 <= i && 0 <= j &&
           i < mat->rows && j < mat->rows);
    BinStr *buffer = mat->matrix[i];
    mat->matrix[i] = mat->matrix[j];
    mat->matrix[j] = buffer;
}

// see BinMat.h for details
void swapCols(BinMat mat, int i, int j) {
    assert(mat != NULL && 0 <= i && 0 <= j &&
           i < mat->cols && j < mat->cols);
    for(int row = 0; row < mat->rows; row++) {
        BinStr buffer = getMat(mat, row, i);
        setMat(mat, row, i, getMat(mat, row, j));
        setMat(mat, row, j, buffer);
    }
}

// see BinMat.h for details
void rotateRowR(BinMat mat, int row) {
    assert(mat != NULL && 0 <= row && row < mat->rows);
    BinStr last = mat->matrix[row][mat->cols - 1];
    for(int i = mat->cols - 1; i > 0; i--) {
        mat->matrix[row][i] = mat->matrix[row][i - 1];
    }
    mat->matrix[row][0] = last;
}

// see BinMat.h for details
void rotateRowL(BinMat mat, int row) {
    assert(mat != NULL && 0 <= row && row < mat->rows);
    BinStr first = mat->matrix[row][0];
    for(int i = 0; i < mat->cols - 1; i++) {
        mat->matrix[row][i] = mat->matrix[row][i + 1];
    }
    mat->matrix[row][mat->cols - 1] = first;
}

// see BinMat.h for details
void printMat(BinMat mat) {
    assert(mat != NULL);
    for(int i = 0; i < mat->rows; i++) {
        for(int j = 0; j < mat->cols; j++) {
            if(mat->matrix[i][j]->length != 0) {
                printStr(mat->matrix[i][j]);
            } else {
                printf("/");
            }
            printf("\t");
        }
        printf("\n");
    }
    return;
}
