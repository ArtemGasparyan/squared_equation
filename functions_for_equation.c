#include "decision.c"

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
