#include <stdio.h>

#include "relativity.h"
#include "relativity_tests.h"

void run_relativity_tests() {
    double earth_gravity = newton_general_gravity_equation(5.97219e24, 1, 6371000);
    printf("earth_gravity: %f\n\n", earth_gravity);

    double sun_gravity = newton_general_gravity_equation(1.989e30, 1, 6.96e8);
    printf("sun_gravity: %f\n\n", sun_gravity);

    double sagittariusa_gravity = newton_general_gravity_equation(8.55e36, 1, 1.27e10);
    printf("sagittariusa_gravity: %f\n\n", sagittariusa_gravity);
}
