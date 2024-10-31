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
 * @brief функция проверяет double = 0
 * @param digit переменная digit
 * @return 1 = в случае если = 0. 0 - в случае если != 0 
 */
int check_equallu_one_value(double digit);

