#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

int findMinElement(int matrix[10][10]) {
    int minElement = matrix[0][0];

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (matrix[i][j] < minElement) {
                minElement = matrix[i][j];
            }
        }
    }

    return minElement;
}

int countElementsWithinRange(int matrix[10][10], int minElement) {
    int count = 0;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (matrix[i][j] >= minElement && matrix[i][j] <= minElement * 1.1) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    srand(time(0));
    int array[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            array[i][j] = -10 + rand() % (10 + 10 + 1);
            printf("%3d ", array[i][j]);
        }
        printf("\n");
    }

    int minElement = findMinElement(array);
    int count = countElementsWithinRange(array, minElement);

    printf("Кількість елементів, що відрізняються від найменшого на не більше 10%%: %d\n", count);

    return 0;
}
