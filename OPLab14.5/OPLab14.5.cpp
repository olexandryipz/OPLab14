#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

#define K 6
#define N 5

int main() {
    srand(time(0));

    int results[K][N];

    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < N; ++j) {
            results[i][j] = rand() % 10 * 12 + 50;
        }
    }

    printf("Результати голосування:\n\n");
    printf("  |");
    for (int j = 0; j < N; ++j) {
        printf("   Кандидат %d |", j + 1);
    }
    printf("\n");

    printf("----------------------------------------\n");

    for (int i = 0; i < K; ++i) {
        printf("Пункт %d |", i + 1);
        for (int j = 0; j < N; ++j) {
            printf("    %4d    |", results[i][j]);
        }
        printf("\n");
    }

    printf("----------------------------------------\n");

    int maxRating = 0;
    for (int i = 0; i < K; ++i) {
        maxRating += results[i][1] + results[i][3] + results[i][4];
    }

    printf("\nНайвищий рейтинг серед другого, четвертого і п'ятого кандидатів: %d\n", maxRating);

    return 0;
}
