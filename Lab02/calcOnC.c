#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    double alpha, z1, z2;

    printf("Enter the value of alpha (in degrees): ");
    scanf("%lf", &alpha);

    double alpha_rad = alpha * PI / 180.0;

    z1 = cos(alpha_rad) + cos(2 * alpha_rad) + cos(6 * alpha_rad) + cos(7 * alpha_rad);

    z2 = 4 * cos(alpha_rad / 2) * cos(5 * alpha_rad / 2) * cos(4 * alpha_rad);

    printf("z1 = %.6f\n", z1);
    printf("z2 = %.6f\n", z2);

    return 0;
}
