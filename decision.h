#include <stdio.h>
#include <stdlib.h> 
#include <errno.h>
#include <math.h>
#define EPS 1e-15

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
 * @brief функция, рассчитывающая линейное уравнение => а = 0
 * @param b - коэффициент b
 * @param c - коэффициент с
 * @param x1 - переменная x1
 * @return -1 бесконечное кол-во решений
 * @return 0 не имеет решений
 * @return 1 x1 = -c / b
 */
int lin_equation(const double b, const double c, double *x1);

/** 
 * @brief функция, рассчитывающая квадратное уравнение через дискриминант
 * @param a коэффициент а
 * @param b коэффициент б
 * @param c коэффициент с
 * @param x1 переменная x1
 * @param x2 переменная x2
 * @return 1 имеет 2 корня
 * @return 2 имеет 1 корень
 * @return 0 не имеет корней
 */
int discriminant(const double a, const double b, const double c, double *x1, double *x2);

/**
 * @brief функция, которая выводит ответ в зависимости от решения
 * @param depented отвечает за количество корней, которые удалось найти в уравнении.
 * @param x1 переменная x1
 * @param x2 переменная x2 
 */
void conclusion_depends_on_the_solution(int depented, double *x1, double *x2);