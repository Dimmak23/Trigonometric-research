#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

long factorial(int w) {
    if (w <= 1) return 1;
    return w * factorial(w-1);
}

double Maclaurin_seq(double x, int K, int func, int p) {
    int j; int i; double y; int n; long r; long k;
    k = pow(10, (p + 1)); r = 5;
    while (r >= 5) // keep do re-calculate if result not accurate enough
    {
    j = 1; i = 0; y = 0; n = 0; r = 0;
        for (i = 0; i <= K; i+=1) // program part for numeric calculation
            {
            n = 2*i + func - 1;
            y += j * pow(x, n) / factorial(n);
            j *= -1;
            }
    if (func == 1) r = llabs(k*y - k*cos(x)); // leftover for cos(x)
    if (func == 2) r = llabs(k*y - k*sin(x)); // leftover for sin(x)
    K++; // Maeby with another one Mac. member result will be accurate enough
    }
    // Output numeric calculation of result
    if (func == 1)
    printf("\nMaclaurin seq. with %d members for cos(x) = %.6lf", K-1, y);
    if (func == 2)
    // Output numeric calculation of result
    printf("\nMaclaurin seq. with %d members for sin(x) = %.6lf", K-1, y);
}

int main() {
    // Declaration of const Pi
    double const Pi = 3.14159265359;
    // Declaration of counting variable
    int i;
    // Declaration of sequence coefficient
    int j;
    // Declaraion input/output variables
    int K = 0;
    // Declaration of quantity members in series
    double x, y, z;
    // Declaration of func switch
    int func = 0;
    // Declaration of precision variable
    int precision;
    // Waiting for input of precision calculations
    printf("Enter precision of calculations: ");
    scanf("%d", &precision);
    // It should be at least 1 accurate dec. and 5 digit precision would be enough
    if ((precision <= 1) && (precision > 5)) precision = 5;
    // Waiting for argument value
    printf("Enter x in degree values: ");
    scanf("%lf", &x);
    // Prepare variables for calculation
    LOOP:    if (x > 360)
                {
                x -= 360;
                goto LOOP;
                }
    x = Pi * x / 180; // Change x to radian values
// COS(x) calulations part of program
    z = 0; // Set function result value to zero
    // Sum of first K members Maclaurin sequence for cox(x)
    func = 1;
    Maclaurin_seq(x, K, func, precision);
    // Calculation sin(x) with inner function
    z = cos(x);
    // Output straight calculation of result
    printf("\nInner function cos(x) = %.6lf", z);
// SIN(x) calculations part of program
    z = 0; // Reset function result value
    // Sum of first K members Maclaurin sequence for sin(x)
    func = 2;
    Maclaurin_seq(x, K, func, precision);
    // Calculation sin(x) with inner function
    z = sin(x);
    // Output straight calculation of result
    printf("\nInner function sin(x) = %.6lf", z);
}