#include "function_for_equation.h"

double input_dub(void)
{ 
    double parametr = NAN;
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
    assert(x1 != NULL);
    if (check_equally(b, 0.0) && check_equally(c, 0.0))
    { 
        return INF; //это бесконечное кол-во решений, а не no solution :)//
    }
    else if (check_equally(b, 0.0))
    {
        return NO_SOLUTION; //нет решений с = 0, с - число
    }
    else
    { 
        *x1 = -c / b;
        return ONE_SOL; 
    }
}

int discriminant(const double a, const double b, const double c, double *x1, double *x2)
{   
    assert(x1 != NULL);
    assert(x2 != NULL);
    double discriminant = b * b - (4 * a * c);
    double disc = sqrt(discriminant);

    if (disc > EPS) 
    { 
        *x1 = (-b + disc) / (2 * a);
        *x2 = (-b - disc) / (2 * a);
        return TWO_SOL;
    }
    else if (check_equally(disc, 0.0))
    { 
        *x1 = -b / (2 * a);
        return ONE_SOL;
    }
    else
    {
        return NO_SOLUTION; 
    }
}

void conclusion_depends_on_the_solution(int depented, double *x1, double *x2)
{ 
    switch(depented)
    { 
        case INF:
            printf("an infinite number of solutions\n");
            break;
        case NO_SOLUTION:
            printf("no solution\n");
            break;
        case ONE_SOL:
            printf("x1 = %lf\t x2 = %lf", *x1, *x2);
            break;
        case TWO_SOL:
            printf("x = %lf\n", *x1);
            break;
        default:
            printf("xz cho tut napisat\n");
            exit;
    }
}

void print_instruction(void)
{ 
    printf("Hello, brat, here are the instructions\n");
    printf("this program solves equations of the form: ax^2 + bx + c = 0");
    printf("it has two types of solutions.");
    printf("software solution or debug mod\n");
    printf("options:\n");
    printf("//#define DEBUG_MOD(file function_for_equatio.h)                 the debug mod, the file launched, data is read from it, checked and a response is issued\n");
    printf("-h                                                               instructions epti\n");
    printf("                                                                 to run it in normal mode, write task.exe\n");
}
