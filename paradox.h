#ifndef _PARADOX_H
#define _PARADOX_H 1

#include <stdio.h>
#include <stdbool.h>

char *parseInputFile(int argc, char *argv[]);
char *parseOutputFile(int argc, char *argv[]);
int readNumberFile(FILE *file, int *location, int maxlen);
double runManyBirthdayParadox(int numPeople, int numTrials);
bool runBirthdayParadox(int *array, int numPeople);
void fillArrayWithRandom(int *array, int length);
bool containsDuplicates(int *array, int length);

#endif
