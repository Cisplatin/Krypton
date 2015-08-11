/* Statistical.h - Created by Xenonstory on August 11
   An implementation of various statistical tests for PRNGs */

#ifndef STATISTICAL_H
#define STATISTICAL_H

#define NUMBER_OF_STATISTICAL_TESTS 1

#include "../../Structures/BinStr.h"
#include <stdbool.h>
#include <string.h>

struct statistical_test {
    char *name;
    int degrees_of_freedom;
    float (*testFunc)(BinStr);
};

// run_statistical_tests(str) runs a myriad of statistical tests on the given
//   BinStr to test for randomness
// requires: str is a valid BinStr
// effects: prints out information about the randomness of the string
void run_statistical_tests(BinStr str);

#endif
