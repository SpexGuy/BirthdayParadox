
#include "paradox.h"
#define MAX_NUM_SIZES 1000
#define NUM_TRIALS 1000

int main(int argc, char *argv[]) {
	char *inputFile = parseInputFile(argc, argv);
	char *outputFile = parseOutputFile(argc, argv);
	//TODO: open input file for reading
	FILE *in;
	//TODO: open output file for writing
	FILE *out;

	int numbers[MAX_NUM_SIZES];
	int numTrials = readNumberFile(in, numbers, MAX_NUM_SIZES);
	if (len < 0)
		fprintf(stderr, "Error: Cannot open file %s\n", inputFile);
	for (int c = 0; c < len; c++) {
		double percentage = runManyBirthdayParadox(numbers[c], NUM_TRIALS);
		fprintf(out, "%1.2f", percentage);
	}
	fclose(out);
	exit(0);
}

double runManyBirthdayParadox(int numPeople, int numTrials) {
	int birthdays[numPeople];
	int successes = 0;
	for (int c = 0; c < numTrials; c++) {
		if (runBirthdayParadox(birthdays, numPeople)) {
			successes++;
		}
	}
	return (double)successes / numTrials;
}

bool runBirthdayParadox(int *array, int numPeople) {
	fillArrayWithRandom(array, numPeople);
	return containsDuplicates(array, numPeople);
}

void fillArrayWithRandom(int *array, int length) {
	for (int c = 0; c < length; c++) {
		array[c] = rand() % 365;
	}
}

bool containsDuplicates(int *array, int length) {
	for (int c = 0; c < length-1; c++) {
		int target = array[c];
		for (int d = c+1; d < length; d++) {
			if (target == array[d]) {
				return true;
			}
		}
	}
	return false;
}
