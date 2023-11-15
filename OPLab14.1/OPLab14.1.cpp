#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows = 5;
    int cols = 3;
    int array[5][3];

    srand(time(0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = rand() % 21 - 10;
        }
    }

    printf("Двовимірний масив:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }

    int positiveCount = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (array[i][j] > 0) {
                positiveCount++;
            }
        }
    }

    printf("\nКількість додатних елементів: %d\n", positiveCount);

    return 0;
}