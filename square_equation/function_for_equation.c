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

    if (fabs(disc) > EPS) 
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

void conclusion_depends_on_the_solution(int depented, double x1, double x2)
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
            printf("x = %lf", x1);
            break;
        case TWO_SOL:
            printf("x1 = %lf\tx2 = %lf\n", x1, x2);
            break;
        default:
            printf("xz cho tut napisat\n");
            exit;
    }
}

void print_instruction(void)
{ 
    printf("Hello, brat, here are the instructions\n");
    printf("This program solves equations of the form: ax^2 + bx + c = 0\n");
    printf("It has two types of solutions.\n");
    printf("Software solution or debug mod.\n");
    printf("options:\n");
    printf("\n//gcc -DDEBUG_MOD\tDebug mod - here all the roots and coefficients are read from the file\n\t\t\t\t(you can see an example of the data in the file test.txt ).\n\t\t\t\t The first 3 values are coefficients, followed by the number of roots, then their values.\n\t\t\t\t I think you've got it all figured out. Naturally, you can change these tests to your own.\n");
    printf("\n-h\t\tYou've figured out how to run the instructions yourself \n");
    printf(".exe\t\tto run it in normal mode\n");
    printf("Athour: @Atiltt");
}
void print_proga(void){
        printf("Bez debaga workaet\n");
        printf("Please enter value a:\n");
        const double a = input_dub();
        printf("Please enter value b:\n");
        const double b = input_dub();
        printf("Please enter value c:\n");
        const double c = input_dub();

        double x1 = NAN, x2 = NAN;
        int dependet = 0;

        if (check_equally(a, 0.0)) { 
            dependet = lin_equation(b, c, &x1);
            conclusion_depends_on_the_solution(dependet, x1, NAN);
        } else { 
            dependet = discriminant(a, b, c, &x1, &x2);
            conclusion_depends_on_the_solution(dependet, x1, x2);
        }
}