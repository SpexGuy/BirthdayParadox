
#include "paradox.h"
#define MAX_NUM_SIZES 1000
#define NUM_TRIALS 1000
#define min(a, b) ((a)<(b))?(a):(b)

int main(int argc, char *argv[]) {
	char *inputFile = parseInputFile(argc, argv);
	char *outputFile = parseOutputFile(argc, argv);
	//TODO: open input file for reading
	FILE *in;
	//TODO: open output file for writing
	FILE *out = stdout;

	int numbers[MAX_NUM_SIZES];
	int numTrials = readNumberFile(in, numbers, MAX_NUM_SIZES);
	if (numTrials < 0) {
		fprintf(stderr, "Error: Cannot open file %s\n", inputFile);
		exit(-1);
	}
	int c = 0;
	for (; c < numTrials; c++) {
		double percentage = runManyBirthdayParadox(numbers[c], NUM_TRIALS);
		fprintf(out, "%1.2f\n", percentage);
	}
	fclose(out);
	exit(0);
}

char *parseInputFile(int argc, char *argv[]) {
	return "foo";
}

char *parseOutputFile(int argc, char *argv[]) {
	return "bar";
}

int readNumberFile(FILE *in, int *numbers, int maxLen) {
	int c = 0;
	for (; c < 20; c++) {
		numbers[c] = c;
	}
	return 20;
}

double runManyBirthdayParadox(int numPeople, int numTrials) {
	int birthdays[numPeople];
	int successes = 0;
	int c = 0;
	for (; c < numTrials; c++) {
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
	int c = 0;
	for (; c < length; c++) {
		array[c] = rand() % 365;
	}
}

bool containsDuplicates(int *array, int length) {
	int d, c = 0;
	for (; c < length-1; c++) {
		int target = array[c];
		for (d = c+1; d < length; d++) {
			if (target == array[d]) {
				return true;
			}
		}
	}
	return false;
}
