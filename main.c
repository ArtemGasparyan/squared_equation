#include "function_for_equation.h"

int main(int argc, char* argv[]) {
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        print_instruction();
        return 0;
    }

    #ifdef DEBUG_MOD
        printf("Debug mode activated.\n");
        open_file(); 
    #else
        printf("This is a program for solving squared equations by attilt\n");
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
            conclusion_depends_on_the_solution(dependet, &x1, NULL);
        } else { 
            dependet = discriminant(a, b, c, &x1, &x2);
            conclusion_depends_on_the_solution(dependet, &x1, &x2);
        }
    #endif

    return 0;
}