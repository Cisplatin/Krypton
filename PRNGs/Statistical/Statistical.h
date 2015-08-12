/* Statistical.h - Created by Xenonstory on August 11
   An implementation of various statistical tests for PRNGs */

#ifndef STATISTICAL_H
#define STATISTICAL_H

#define NUMBER_OF_STATISTICAL_TESTS 1

#include "../../Structures/BinStr.h"

struct statistical_test {
    char *name;
    int degrees_of_freedom;
    float (*testFunc)(BinStr);
};

typedef struct statistical_test *StatisticalTest;

// get_statistical_test(name) returns an instance of the statistical test       
//   with the given name. Returns NULL if the given test does not exit          
// effects: allocates memory to a new StatisticalTest  
StatisticalTest get_statistical_test(char *name);

#endif
