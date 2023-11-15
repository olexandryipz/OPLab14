#include <stdio.h>
#include <math.h>
#include <Windows.h>

int main() {
    int n = 5;
    int m = 5;
    double b[5][5] = {
        {1.1, 2.2, 3.3, 4.4, 5.5},
        {6.6, 7.7, 8.8, 9.9, 10.1},
        {11.2, 12.3, 13.4, 14.5, 15.6},
        {16.7, 17.8, 18.9, 19.1, 20.2},
        {21.3, 22.4, 23.5, 24.6, 25.7}
    };

    printf("Масив b:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%.2f\t", b[i][j]);
        }
        printf("\n");
    }

    double maxElement = b[0][0];
    int maxRow = 0, maxCol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (b[i][j] > maxElement) {
                maxElement = b[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }
    printf("\nМаксимальний елемент: %.2f\n", maxElement);
    printf("Його індекси: рядок %d, стовпець %d\n", maxRow, maxCol);

    double minElement = b[0][0];
    int minRow = 0, minCol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (b[i][j] < minElement) {
                minElement = b[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }
    printf("\nМінімальний елемент: %.2f\n", minElement);
    printf("Його індекси: рядок %d, стовпець %d\n", minRow, minCol);

    printf("\nСередньоарифметичні значення елементів кожного рядка:\n");
    for (int i = 0; i < n; ++i) {
        double sum = 0.0;
        for (int j = 0; j < m; ++j) {
            sum += b[i][j];
        }
        double average = sum / m;
        printf("Рядок %d: %.2f\n", i, average);
    }

    double diagonalProduct = 1.0;
    for (int i = 0; i < n; ++i) {
        diagonalProduct *= b[i][i];
    }
    printf("\nДобуток елементів головної діагоналі: %.2f\n", diagonalProduct);

    double diagonalSum = 0.0;
    for (int i = 0; i < n; ++i) {
        diagonalSum += b[i][i];
    }
    printf("Сума елементів головної діагоналі: %.2f\n", diagonalSum);

    double belowDiagonalSum = 0.0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            belowDiagonalSum += b[i][j];
        }
    }
    printf("Сума елементів під головною діагоналлю: %.2f\n", belowDiagonalSum);

    return 0;
}