#ifndef SRC_S21_CALC_H_
#define SRC_S21_CALC_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHISLO 0
#define OPERATION_1 1
#define OPERATION_2 2

#define TRUE_CH 1
#define FALSE_CH 0

#define OK 0
#define BAD_EXPRESSION 1
#define X 2

// Cруктура одной лексемы
typedef struct lex {
  char value[50];
  // unarnost = 0 -> работаем с числом
  // unarnost = 1 -> нужен один операнд
  // unarnost = 2 -> нужно два операнда
  int unarnost;
} lexema;

// Cтруктура оператора
typedef struct operat {
  char operation[10];
  int unarnost;
  // prioritet = 3 все унарные операторы и "^"
  // prioritet = 1 у бинарных "+" "-"
  // prioritet = 2 у "*" "/" "mod"
  // prioritet = 0 у чисел
  int prioritet;
} operator;

// Cписок из операторов
typedef struct operators_node {
  operator unit;
  struct operators_node* next;
} operators_t;

// Список чисел
typedef struct number_node {
  double unit;
  struct number_node* next;
} number_t;

char* my_calc(char* expression);

// Распарсить структуры на лексемы
int parser_of_expression(char* expression, char* x_str, double* result);
int check_x(char* x_str, double* x);

// Функция раскидывания лексем по стэкам и расчет математического выражения
double parser_of_lexems(lexema* mass, int* front, int* rear, double x,
                        int* status);

// Фнкции для работы с лексемами

// Добавить в конец очереди
void push_lex(lexema lex, lexema* mass, int* front, int* rear);
// Распечатать лексемы
void print_lex(lexema* mass, int* front, int* rear);
// Проверить математическое выражение на корректность
int check_lexems(lexema* mass, int* front, int* rear);

// Функции для работы со стэком чисел

// Добавлние структуры на вершину стека
void push_num(number_t** head, double value);
// Функция для проведения операции над двумя элементами находящихся на вершине
// Удаляет верхний узел и записывает результат во второй
void do_oper(number_t** head, operator operation, int* status);
// Берет значение с вершины стэка удаляет этот узел и возвращает значение
// удаленного узла, является вспомогательной для do_oper
double pop_num(number_t** head);
// Выполняет унарную операцию
void do_oper_1(number_t* head, operator operation);
// Выполняет бинарную операцию
void do_oper_2(number_t* head, operator operation, double tmp, int* status);
// Вывести в консоль стек чисел
void print_num(number_t* head);

// Функции для работы со стеком операций
// Проверка стека на пустоту
int stack_is_empty(operators_t* head);
// Добавить на вершину стека
void push_operation(operators_t** head, operator operation);
// Взять значение с вершины стека и удаляет его из стека
operators_t* take_operation_del(operators_t** head);
// Взять значение без его удаления из стека
operators_t* take_operation(operators_t** head);
// Удалить стек
// void deleate_operations_t(operators_t** head);
void print_operations(operators_t* head);
void free_op(operators_t** head);

// Вспомогательные функции для работы с кредитом и депозитом
// Проверка строки на пустоту
int char_is_empty(char* tmp);
// Проверка является ли строка корректной для перевода ее в double, если
// корректно то перевод его в double иначе записать в него ноль
int double_is_true(char* tmp, double* result);
int double_is_true_for_x(char* tmp, double* result);
// Проверка является ли строка корректной для перевода ее в int, если
// корректно то перевод его в int иначе записать в него ноль
int int_is_true(char* tmp, int* result);
// Берет из строки периодичность выплат и записывает в count
// Только для периодичности выплат
void take_from_spisok_viplat(char* spisok, int* count);
// Берет из строки периодичность выплат и записывает в count
// Только для пополнений и снятий
void take_from_spisok(char* spisok, int* count);
// Функция для взятия числа и месяца из даты
int take_from_date(char* date, int* day, int* month, int* year);

// Функция для работы с кредитом
int credit(char* summ, char* srok, char* proc_stavka, int* type,
           char* result_platezh, double* result_proc, double* result_sum);

// Функция для работы с депозитом

int deposit(char* sum_dep, char* srok_dep, char* date_dep, char* proc_dep,
            char* nalog_dep, char* popol_mes_dep, char* sum_popol_dep,
            char* snyatiya_mes_dep, char* snyatiya_sum_dep,
            char* spisok_popol_dep, char* spisok_snyatiya_dep,
            char* spisok_period_dep, int* type, double* result_procent,
            double* result_nalog, double* result_deposit);

#endif  // SRC_S21_CALC_H_