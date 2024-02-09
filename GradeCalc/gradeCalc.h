#include <stdio.h>
#include <stdlib.h>

int labGradeCalc(int lab, float *floatArray, int *gradeArray, int *pointsArray, int n);

float * allocateFloatArray(int n);

int * allocateIntArray(int n);

int calcTotalGrade(int lab, int *array, int n, int totalPoints);

void freeFloatArray(float *array);

void freeIntArray(int *array);