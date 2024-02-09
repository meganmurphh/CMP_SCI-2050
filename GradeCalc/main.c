#include "gradeCalc.h"

int main(){

    int size = 14;
    float *grades = allocateFloatArray(size);
    int *pointsEarned = allocateIntArray(size);
    int *availablePoints = allocateIntArray(size);


    int totalPoints = 0;

    for(int i = 1; i < size; i++){

        printf("\n----------LAB %d----------\n", i);

       labGradeCalc(i, grades, pointsEarned, availablePoints, size);
       totalPoints += availablePoints[i];

       printf("\nScore for Lab %d: %.2f%%\n", i, grades[i]);

       calcTotalGrade(i, pointsEarned, size, totalPoints);
    }

    freeFloatArray(grades);
    freeIntArray(pointsEarned);

    return 0;

}