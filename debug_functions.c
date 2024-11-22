#include "function_for_equation.h"

void open_file()
{
    FILE *testfile = fopen("test.txt", "r");
    if (!testfile)
    { 
        perror("ya xz de file, Brat, i dont can open file\n");
        exit(EXIT_FAILURE);
    }

    int kol_vo_line = 0;
    int result = fscanf(testfile, "%d", &kol_vo_line);
    if (result != 1)
    { 
        perror("it's a good file, but it's empty\n");
        exit(EXIT_FAILURE);
    }

    double a = NAN, b = NAN, c = NAN, x1_file = NAN, x2_file = NAN; 
    int kol_vo_roots = 0;
    int roots_file = 0;
    double now_x1 = NAN, now_x2 = NAN;


    for (int i = 0; i < kol_vo_line; i++)
    { 
        int prikol = fscanf(testfile, "%lf %lf %lf %d %lf %lf", &a, &b, &c, &kol_vo_roots, &x1_file, &x2_file);
        if (prikol < 4)
        { 
            perror("Brat, idi read instruction\n");
            exit(EXIT_FAILURE);
        }
        if (check_equally(a, 0.0))
        { 
            roots_file = lin_equation(b, c, &now_x1);
        }
        else { 
            roots_file = discriminant(a, b, c, &now_x1, &now_x2);
        }

    }
}


void debug_result(a, b, c, kol_vo_roots, roots_file, x1_file, x2_file, kol_vo_line, now_x1, now_x2, i)
{
    printf("Your file have %d tests\n", kol_vo_line - 1);
    printf("coefficients in your file:\n a = %lf\n, b = %lf\n, c = %lf\n", a, b, c);
    
}