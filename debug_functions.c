#include "function_for_equation.h"

void open_file() {
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
    int kol_vo_roots = 0;
    int roots_file = 0;
    double now_x1 = NAN, now_x2 = NAN;
    
    printf("Poexalo brat\n");
    for (int i = 0; i < kol_vo_line; i++) { 
        int prikol = fscanf(testfile, "%lf %lf %lf %d", &a, &b, &c, &kol_vo_roots);
        if (prikol < 4) { 
            fprintf(stderr, "Brat, idi read instruction\n");
            exit(EXIT_FAILURE);
        }

        if (kol_vo_roots > 0) {
            prikol = fscanf(testfile, "%lf", &x1_file);
            if (kol_vo_roots == 2) {
                prikol = fscanf(testfile, "%lf", &x2_file);
            }
        }

        if (check_equally(a, 0.0)) { 
            roots_file = lin_equation(b, c, &now_x1);
        } 
        else { 
            roots_file = discriminant(a, b, c, &now_x1, &now_x2);
        }

        print_debug_nafik(a, b, c, kol_vo_roots, roots_file, x1_file, x2_file, kol_vo_line, now_x1, now_x2);
    }
    fclose(testfile);
    printf("pokeda brat, listen bolshie kurtki\n");
}

int debug(int kol_vo_roots, int roots_file)
{ 
    if (kol_vo_roots != roots_file)
        return OSHIBKA;

    if (roots_file == 1)
        return ROOTS_1;

    if (roots_file == 2)
        return ROOTS_2;

    if (roots_file == 0)
        return KORNEI_NEMA;

    if (roots_file == -1)
        return OCHEN_MNOGA_RESHENII;

}

void print_debug_nafik(double a, double b, double c, int kol_vo_roots, int roots_file, double x1_file, double x2_file, int kol_vo_line, double now_x1, double now_x2) { 
    
    int debug_result = debug(kol_vo_roots, roots_file);
    switch (debug_result) { 
        case OSHIBKA:
            fprintf(stderr, "Proizohla konkretnay oshibka, brat(podscazy v raschetax)\n");
            break;
        case ROOTS_1:
            printf("Imeem 1 roots\n v faile bil: %lf\n rasschitanni: %lf\n", x1_file, now_x1);
            break;
        case ROOTS_2:
            printf("Imeem 2 roots\n v faile bili: %lf and %lf\n rasschitannie: %lf and %lf\n", x1_file, x2_file, now_x1, now_x2);
            break;
        case KORNEI_NEMA: 
            printf("Imee to, cgto kornei u nas nema\n bilo f file %lf\n rasschitano %lf\n", kol_vo_roots, roots_file);
            break;
        case OCHEN_MNOGA_RESHENII: 
            printf("Imeem chto resheni u nas doxya:) BOLHIE KURTKI\n");
            break;
        default:
            LOL;
            break;
    }
}