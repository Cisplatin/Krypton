/* Statistical.h - Created by Xenonstory on August 11
   An implementation of various statistical tests for PRNGs */

#ifndef STATISTICAL_H
#define STATISTICAL_H

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

// run_statistical_test(str, test) returns the statistic value of the given
//   string using the given test.
float run_statistical_test(BinStr str, StatisticalTest test);

// destroy_statistical_test(test) destroys the given instance of a stat test
// effects: frees memory associated with the given test
void destroy_statistical_test(StatisticalTest test);

#endif
