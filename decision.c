#include <stdio.h>
#include <stdlib.h> 
#include <errno.h>
#include <math.h>

double input_dub(void);

void discriminant(const double a, const double b, const double c, const double epsilon);

void zero_coefficients(const double a, const double b, const double c, const double epsilon);

int main(void)
{   
    printf("An equation of the form is given:ax^2 + bx + c = 0\n");
    printf("Please enter value confficietn a:\n");
    const double a = input_dub();
    printf("Please enter value confficient b:\n");
    const double b = input_dub();
    printf("Please enter value confficient c:\n");
    const double c = input_dub();
    const double epsilon = 1e-15;

    if (fabs(a) < epsilon || fabs(b) < epsilon || fabs(c) < epsilon)
    { 
        zero_coefficients(a, b, c, epsilon);
    } else { 
        discriminant(a, b, c, epsilon);
    }

    return 0;

}

double input_dub(void)
{ 
    double parametr = 0.0;
    int result = scanf("%lf", &parametr);
    if (result != 1)
    { 
        errno = EIO;
        exit(EXIT_FAILURE);
    }

    return parametr;
}

void discriminant(const double a, const double b, const double c, const double epsilon)
{  
    double x1 = 0.0;
    double x2 = 0.0;
    double discriminant = pow(b, 2) - (4 * a * c);
    if (discriminant > epsilon)
    { 
        x1 = (sqrt(discriminant) - b) / (2 * a);
        x2 = (sqrt(discriminant) + b) / (2 * a);
        printf("x1 = %lf, x2 = %lf\n", x1, x2); 
    }

    if (fabs(discriminant) < epsilon)
    { 
        x1 = -b / (2 * a);
        printf("Discriminant = 0 => x = %lf\n", x1);
    }

    if(discriminant < epsilon)
    { 
        printf("an empty set\n");
    }
}

void zero_coefficients(const double a, const double b, const double c, const double epsilon)
{ 
    double x1 = 0.0;
    double x2 = 0.0;
    if (fabs(a) < epsilon) {
        if (fabs(b) < epsilon) {
            if (fabs(c) < epsilon) {
                printf("0 = 0\n");
        }
        printf("no solution\n");
    }
    x1 = -c / b;
    printf("x = %lf\n", x1);
    }

    if (fabs(b) < epsilon)
    { 
        x1 = sqrt(-c / a);
        x2 = -x1;
        printf("x1 = %lf, x2 = %lf", x1, x2);
    }

    if (fabs(c) < epsilon)
    { 
        x1 = 0.0;
        x2 = sqrt(-c / a);
        printf("x1 = %lf, x2 = %lf", x1, x2);
    }
}