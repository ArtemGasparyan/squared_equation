#ifndef DEBUG_FUNCTIONS

#define DEBUG_FUNCTIONS

/**
 * @brief функция открывает файл и считывает из него данные
 */
void debug_function();

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
 * @param kol_vo_roots - кол-во корней рассчитанных программой
 * @param roots_file - кол-во корней в исходном файле
 * @param x1_file - переменная x1, считанная из файла 
 * @param x2_file - переменная x2, считанная из файла
 * @param kol_vo_line - кол-во строк в исходном файле
 * @param now_x1 - рассчитанная программой переменная x1
 * @param now_x2 - рассчитанная программой переменная x2
 */
void print_debug_nafik(double a, double b, double c, int kol_vo_roots, int roots_file, double x1_file, double x2_file, int kol_vo_line, double now_x1, double now_x2);

void print_instruction(void);


#endif // DEBUG_FUNCTIONS