#include "gradeCalc.h"

float * allocateFloatArray(int n){

    float *array = malloc(n * sizeof(float));

    for(int i = 0; i < n; ++i){
        array[i] = 0;
    }

    return array;
}

int * allocateIntArray(int n){

    int *array = malloc(n * sizeof(int));

    for(int i = 0; i < n; ++i){
        array[i] = 0;
    }

    return array;
}

int labGradeCalc(int lab, float *floatArray, int *gradeArray, int *pointsArray, int n){
    float grade;
    int outOf;

    static int currIndex = 1;

    printf("Enter grade: ");
    scanf("%f", &grade);

    printf("Out of: ");
    scanf("%d", &outOf);

    float newGrade = grade / 11.0 * 100;

    if (currIndex < n) {
        floatArray[currIndex] = newGrade;
        gradeArray[currIndex] = grade;
        pointsArray[currIndex] = outOf;
        currIndex++;
        return 1;
    } else {
        printf("Array is full. Cannot insert more grades.\n");
        return 0; // Return 0 to indicate failure
    }


    return 0;
}

int calcTotalGrade(int lab, int *array, int n, int totalPoints){
    float pointsRecieved = 0.0;

    for (int i = 0; i < n; i++) {
        pointsRecieved += array[i];
    }

    float totalGrade = (pointsRecieved / totalPoints) * 100.0;

    printf("\nYour grade after lab %d will be %.2f%%\n", lab, totalGrade);

    return totalGrade;

}

void freeFloatArray(float *array){
    free(array);
    array = NULL;
}

void freeIntArray(int *array){
    free(array);
    array = NULL;
}




