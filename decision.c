#include "decision.h"

/**
 * @brief получает на вход число из потока ввода
 * @return возвращает полученное число, в ином случае возвращает ошибку и делает exit
 */
double input_dub(void);

/**
 * @brief функция проверяет double на =
 * @param num1 переменная num1
 * @param num2 переменная num2
 * @return 1 - в случае если =. 0 - в случае  !=
 */
int check_equally(double num1, double num2);

/**
 * @brief функция проверяет double = 0
 * @param digit переменная digit
 * @return 1 = в случае если = 0. 0 - в случае если != 0 
 */
int check_equallu_one_value(double digit);


int main(void)
{   
    printf("An equation of the form is given:ax^2 + bx + c = 0\n");
    printf("Please enter value coеfficietn a:\n");
    const double a = input_dub();
    printf("Please enter value coеfficient b:\n");
    const double b = input_dub();
    printf("Please enter value coеfficient c:\n");
    const double c = input_dub();
    
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

    if (result != 2)
    {
        printf("enter one value\n");
        exit(EXIT_FAILURE);
    }

    return parametr;
}

int check_equally(double num1, double num2)
{   
    return fabs(num1 - num2) < EPS;
}

int check_equallu_one_value(double digit)
{ 
    return fabs(digit) < EPS;
}