#ifndef POW_H
#define POW_H

#include <stdint.h>

#ifndef MAX_TAYLOR_ITERATIONS
#define MAX_TAYLOR_ITERATIONS 50
#endif

#ifndef INFINITY
#define INFINITY (1.0/0.0)
#endif

#ifndef NAN
#define NAN (0.0/0.0)
#endif

int64_t pow_int64(int64_t base, int64_t exp);
double pow_double(double base, double exp);
double exp_double_safe(double x);
double exp_double(double x);
double ln_double_safe(double x);
double ln_double(double x);

#endif
