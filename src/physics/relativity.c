#include "relativity.h"

double newton_general_gravity_equation(double m1, double m2, double r) {
    double division = (m1 * m2)/(r * r);
    double result = G_UNIVERSAL * division;

    return result;
}
