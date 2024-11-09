#include "function_for_equation.h"
#include "main.h"

int main(void)
{ 
    printf("This is a programm for solving sqared equation by attilt\n");
#ifndef DEBUG_MOD
    
#else
    printf("Please enter value a\n");
    const double a = input_dub();
    printf("Please enter value b\n");
    const double b = input_dub();
    printf("Please enter value c\n");
    const double c = input_dub();
    double x1 = NAN, x2 = NAN;
    int dependet = 0;
    if (check_equally(a, 0.0))
    { 
        dependet = lin_equation(b, c, &x1);
        conclusion_depends_on_the_solution(dependet, &x1, NULL);
    }
    else 
    { 
        dependet = discriminant(a, b, c, &x1, &x2);
        conclusion_depends_on_the_solution(dependet, &x1, &x2);
    }
#endif
}

#ifndef DEBUG_MOD
int TEST_INPUT()
{   

    double x1 = NAN, x2 = NAN, a = NAN, b = NAN, c = NAN;
    int line = 0, answer = 0;
    FILE *myfile = fopen("test.txt", "r");
    if (!myfile)
    { 
        perror("ya xz de file\n");
        return ERROR_FILA_NEMA;
    }
    if (fscaf(myfile, "%d", &line) != 1)
    { 
        perror("invalid file\n");
        return ERROR_FILE_INVALID;
    }

    if (fscanf(myfile, "%lf%lf"))
}
#endif