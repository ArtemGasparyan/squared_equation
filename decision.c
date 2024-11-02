#include "decision.h"

int main(void)
{   
    printf("An equation of the form is given:ax^2 + bx + c = 0\n");
    printf("Please enter value coеfficietn a:\n");
    const double a = input_dub();
    printf("Please enter value coеfficient b:\n");
    const double b = input_dub();
    printf("Please enter value coеfficient c:\n");
    const double c = input_dub();
    
    double x1 = NAN;
    double x2 = NAN;
    int depented = 0;

    if (check_equally(a, 0.0))
    { 
        depented = lin_equation(b, c, &x1);
        conclusion_depends_on_the_solution(depented, &x1, NULL);
    }
    else 
    { 
        depented = discriminant(a, b, c, &x1, &x2);
        conclusion_depends_on_the_solution(depented, &x1, &x2);
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
    while (getchar() != '\n')
    { 
        printf("only one value should be entered.\n");
        exit(EXIT_FAILURE);
    }
    return parametr;
}

int check_equally(double num1, double num2)
{   
    return fabs(num1 - num2) < EPS;
}

int lin_equation(const double b, const double c, double *x1)
{ 
    if (check_equally(b, 0.0) && check_equally(c, 0.0))
    { 
        return -1; //это бесконечное кол-во решений, а не no solution :)//
    }
    else if (check_equally(b, 0.0))
    {
        return 0; //нет решений с = 0, с - число
    }
    else
    { 
        *x1 = -c / b;
        return 1; 
    }
}

int discriminant(const double a, const double b, const double c, double *x1, double *x2)
{ 
    double disc = b * b - (4 * a * c);

    if (disc > EPS) 
    { 
        *x1 = (-b + sqrt(disc)) / (2 * a);
        *x2 = (-b - sqrt(disc)) / (2 * a);
        return 1;
    }
    else if (check_equally(disc, 0.0))
    { 
        *x1 = -b / (2 * a);
        return 2;
    }
    else
    {
        return 0; //нет корней//
    }
}

void conclusion_depends_on_the_solution(int depented, double *x1, double *x2)
{ 
    switch(depented)
    { 
        case -1:
            printf("an infinite number of solutions\n");
            break;
        case 0:
            printf("no solution\n");
            break;
        case 1:
            printf("x1 = %lf\t x2 = %lf", *x1, *x2);
            break;
        case 2:
            printf("x = %lf\n", *x1);
            break;
        default:
            exit(EXIT_FAILURE);
    }
}