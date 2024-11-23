#ifndef FUNCTION_FOR_EQUATION_H

#define FUNCTION_FOR_EQUATION_H

#define DEBUG_MOD

#define LOL printf("BOLSHIE KURTKI\n")

#define EPS 1e-15

#include <stdio.h>
#include <stdlib.h> 
#include <errno.h>
#include <math.h>
#include <assert.h>
#include <string.h>

enum decisions {
    INF = -1,
    NO_SOLUTION = 0,
    TWO_SOL = 2,
    ONE_SOL = 1
}; 

enum debuginnggggg{
    OSHIBKA = -1,
    ROOTS_1 = 0, 
    ROOTS_2 = 1,
    KORNEI_NEMA = 2,
    OCHEN_MNOGA_RESHENII = 3
};

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
 * @brief функция, которая выводит ответ в зависимости от решения
 * @param depented отвечает за количество корней, которые удалось найти в уравнении.
 * @param x1 указатель на x1
 * @param x2 указатель на x2 
 */
void conclusion_depends_on_the_solution(int depented, double *x1, double *x2);

/**
 * @brief функция, рассчитывающая линейное уравнение => а = 0
 * @param b - коэффициент b
 * @param c - коэффициент с
 * @param x1 - указатель на x1
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
 * @param x1 указатель на x1
 * @param x2 указатель на x2
 * @return 1 имеет 2 корня
 * @return 2 имеет 1 корень
 * @return 0 не имеет корней
 */
int discriminant(const double a, const double b, const double c, double *x1, double *x2);

/**
 * @brief функция открывает файл и считывает из него данные
 */
void open_file();

/**
 * @brief функция проверяет корректность решений квадратного уравнения
 * @param kol_vo_roots перемнная, отвечающая за кол-во корней в исходном файле
 * @param roots_file переменная, отвечающая за кол-во корней решенных прогой
 */
int debug(int kol_vo_roots, int roots_file);

/**
 * @brief вывод дебага нафик
 * @param a - коээффициент а, считанный из файла
 * @param b - коэффициент b, считанный из файла
 * @param c - коэффициент с, считанный из файла
 * @param kol_vo_roots - кол-во корней в исходном файле
 * @param roots_file - кол-во корней рассчитынных программой
 * @param x1_file - переменная x1, считанная из файла 
 * @param x2_file - переменная x2, считанная из файла
 * @param kol_vo_line - кол-во строк в исходном файле
 * @param now_x1 - рассчитанная программой переменная x1
 * @param now_x2 - рассчитанная программой переменная x2
 */
void print_debug_nafik(double a, double b, double c, int kol_vo_roots, int roots_file, double x1_file, double x2_file, int kol_vo_line, double now_x1, double now_x2);

void print_instruction(void);

#endif //FUNCTION_FOR_EQUATION_H