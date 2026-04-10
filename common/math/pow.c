#include "../include/pow.h"

int64_t pow_int64(int64_t base, int64_t exp) {
    if (exp < 0) {
        return 0;
    }

    int64_t result = 1;

    while (exp > 0) {
        if (exp % 2 == 1)
            result *= base;

        base *= base;
        exp /= 2;
    }

    return result;
}

double pow_double(double base, double exp) {
    if (base != base || exp != exp) {
        return NAN;
    }

    if (exp == 0.0) {
        return 1.0;
    }

    if (base == 0.0) {
        return (exp > 0.0) ? 0.0 : INFINITY;
    }

    if (base < 0.0) {
        if (exp != (int64_t)exp) {
            return NAN;
        }

        int64_t e = (int64_t)exp;
        double x = exp * ln_double_safe(-base);

        double result = exp_double_safe(x);

        return (e % 2 != 0) ? -result : result;
    }

    if (exp < 0.0) {
        double x = -exp * ln_double_safe(base);

        return 1.0 / exp_double_safe(x);
    }

    double x = exp * ln_double_safe(base);

    return exp_double_safe(x);
}

double exp_double_safe(double x) {
    if (x > 709.0) {
        return INFINITY;
    }

    if (x < -745.0) {
        return 0.0;
    }

    return exp_double(x);
}

double exp_double(double x) {
    double term = 1.0;
    double sum = 1.0;

    for (int i = 1; i < MAX_TAYLOR_ITERATIONS; i++) {
        term *= x / i;
        sum += term;
    }

    return sum;
}

double ln_double_safe(double x) {
    if (x <= 0.0) {
        return (x == 0.0) ? -INFINITY : NAN;
    }

    if (x == 1.0) {
        return 0.0;
    }

    return ln_double(x);
}

double ln_double(double x) {
    double y = x - 1.0;

    for (int i = 0; i < MAX_TAYLOR_ITERATIONS; i++) {
        double ey = exp_double(y);

        if (ey == 0.0) {
            return -INFINITY;
        }

        double delta = (ey - x) / ey;
        y -= delta;
    }

    return y;
}
