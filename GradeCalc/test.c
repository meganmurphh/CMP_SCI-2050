#ifndef GRADE_CALC_H
#define GRADE_CALC_H

#include <stdio.h>
#include <stdlib.h>

float *allocateArray(int n);
int labGradeCalc(int lab, float *array, int n, int *currIndex);
int calcTotalGrade(int lab, float *array, int n);
void freeArray(float *array);

#endif /* GRADE_CALC_H */


float *allocateArray(int n) {
    float *array = malloc(n * sizeof(float));
    for (int i = 0; i < n; ++i) {
        array[i] = 0;
    }
    return array;
}

int labGradeCalc(int lab, float *array, int n, int *currIndex) {
    float grade;

    printf("Enter grade for lab %d: ", lab);
    scanf("%f", &grade);

    float newGrade = grade / 11.0 * 100;

    if (*currIndex < n) {
        array[*currIndex] = newGrade;
        (*currIndex)++;
        return 1;
    }

    return 0;
}

int calcTotalGrade(int lab, float *array, int n) {
    float pointsReceived = 0.0;

    for (int i = 0; i < n; i++) {
        pointsReceived += array[i];
    }

    int totalPoints = 14 * 11 * 2.0;

    float totalGrade = (pointsReceived / totalPoints) * 100.0;

    printf("Your grade after lab %d will be %.2f%%\n", lab, totalGrade);

    return totalGrade;
}

void freeArray(float *array) {
    free(array);
}



#include "gradeCalc.h"

int main() {
    int size = 3;
    float *testArray = allocateArray(size);
    int currIndex = 0;

    for (int i = 1; i <= size; i++) {
        if (!labGradeCalc(i, testArray, size, &currIndex)) {
            break; // Stop loop if labGradeCalc fails
        }
        calcTotalGrade(i, testArray, size);
    }

    for (int i = 0; i < currIndex; ++i) {
        printf("Score for Lab %d: %.2f%%\n", i + 1, testArray[i]);
    }

    freeArray(testArray);

    return 0;
}


