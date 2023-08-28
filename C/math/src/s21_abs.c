#include "./s21_math.h"

// вычисляет абсолютное значение целого числа

int s21_abs(int x) {
    int z = x;
    if (z < 0)
        z = -1 * z;
    return z;
}
