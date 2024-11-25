#include "function_for_equation.h"
#include "debug_functions.h"

void debug_function() {
    FILE *testfile = fopen("test.txt", "r");
    if (!testfile) { 
        fprintf(stderr, "ya xz de file, Brat, i dont can open file\n");
        exit(EXIT_FAILURE);
    }

    int kol_vo_line = 0;
    int result = fscanf(testfile, "%d", &kol_vo_line);
    if (result != 1) { 
        fprintf(stderr, "it's a good file, but it's empty or invalid\n");
        exit(EXIT_FAILURE);
    }

    double a = NAN, b = NAN, c = NAN, x1_file = NAN, x2_file = NAN; 
    int roots_file = 0;
    int kol_vo_roots = 0;
    double now_x1 = NAN, now_x2 = NAN;
    
    for (int i = 0; i < kol_vo_line; i++) { 
        int prikol = fscanf(testfile, "%lf %lf %lf %d", &a, &b, &c, &roots_file);
        if (prikol < 4) { 
            perror("Brat, go read the instructions\n");
            exit(EXIT_FAILURE);
        }

        if (roots_file > 0) {
            if (fscanf(testfile, "%lf", &x1_file) != 1) {
                fprintf(stderr, "Error: missing root x1 in line %d\n", i + 2);
                fclose(testfile);
                exit(EXIT_FAILURE);
            }
            if (roots_file == 2 && fscanf(testfile, "%lf", &x2_file) != 1) {
                fprintf(stderr, "Error: missing root x2 in line %d\n", i + 2);
                fclose(testfile);
                exit(EXIT_FAILURE);
            }
        }

        if (check_equally(a, 0.0)) { 
            kol_vo_roots = lin_equation(b, c, &now_x1);
        } 
        else { 
            kol_vo_roots = discriminant(a, b, c, &now_x1, &now_x2);
        }

        print_debug_nafik(a, b, c, kol_vo_roots, roots_file, x1_file, x2_file, kol_vo_line, now_x1, now_x2);
    }
    fclose(testfile);
    printf("Goodbay, brat, listen bolshie kurtki\n");
}

int debug(int kol_vo_roots, int roots_file)
{ 
    if (kol_vo_roots != roots_file)
        return OSHIBKA;

    if (kol_vo_roots == 1)
        return ROOTS_1;

    if (kol_vo_roots== 2)
        return ROOTS_2;

    if (kol_vo_roots == 0)
        return KORNEI_NEMA;

    if (kol_vo_roots == -1)
        return OCHEN_MNOGA_RESHENII;

}

void print_debug_nafik(double a, double b, double c, int kol_vo_roots, int roots_file, double x1_file, double x2_file, int kol_vo_line, double now_x1, double now_x2) { 
    
    int debug_result = debug(kol_vo_roots, roots_file);
    switch (debug_result) { 
        case OSHIBKA:
            fprintf(stderr, "We have konkretnay oshibka, brat\n");
            break;
        case ROOTS_1:
            printf("Have 1 roots\n in file: %lf\n calculated: %lf\n", x1_file, now_x1);
            break;
        case ROOTS_2:
            printf("Have 2 roots\n v in file: %lf and %lf\n calculated: %lf and %lf\n", x1_file, x2_file, now_x1, now_x2);
            break;
        case KORNEI_NEMA: 
            printf("Not a single root\n in file %lf\n calculated %lf\n", roots_file, kol_vo_roots);
            break;
        case OCHEN_MNOGA_RESHENII: 
            printf("Infinitely many solutions\n");
            break;
        default:
            LOL;
            break;
    }
}