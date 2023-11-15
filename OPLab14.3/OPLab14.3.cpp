#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define M 10

int getArraySize(char dimension) {
    int size;
    do {
        printf("Введіть розмір %c (менше за %d): ", dimension, dimension == 'n' ? N : M);
        scanf_s("%d", &size);

        if (size >= (dimension == 'n' ? N : M)) {
            printf("Помилка: розмір %c повинен бути менше за %d.\n", dimension, dimension == 'n' ? N : M);
        }
        else if (size <= 0) {
            printf("Помилка: розмір %c повинен бути більше 0.\n", dimension);
        }

    } while (size <= 0 || size >= (dimension == 'n' ? N : M));

    return size;
}

int generateRandomNumber(int a, int b) {
    return rand() % (b - a + 1) + a;
}

void fillArray(int arr[N][M], int n, int m, int a, int b) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = generateRandomNumber(a, b);
        }
    }
}

void printArray(int arr[N][M], int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

void multiplyArrays(int arr1[N][M], int arr2[N][M], int result[N][M], int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            result[i][j] = arr1[i][j] * arr2[i][j];
        }
    }
}

int main() {
    srand(time(0));

    int n, m;
    int a, b;

    n = getArraySize('n');
    m = getArraySize('m');

    printf("Введіть інтервал [a, b] для генерації псевдовипадкових чисел (a < b): ");
    scanf_s("%d %d", &a, &b);

    int array1[N][M], array2[N][M], result[N][M];

    fillArray(array1, n, m, a, b);
    printf("\nПерший масив:\n");
    printArray(array1, n, m);

    fillArray(array2, n, m, a, b);
    printf("\nДругий масив:\n");
    printArray(array2, n, m);

    multiplyArrays(array1, array2, result, n, m);
    printf("\nРезультат множення:\n");
    printArray(result, n, m);

    return 0;
}
