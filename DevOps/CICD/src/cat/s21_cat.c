#include "s21_cat.h"

int main(int argc, char **argv) {
    config cfg;
    s21_initialization(&cfg);
    /* Проходим каждый аргумент, проверяем является ли он флагом
     * Если да то записываем данные в структуру в зависимости от самого флага
     * Ecли нет то просто пропускаем его
     */
    for (int i = 1; i < argc; i++) {
        int flag = 1;
        s21_proverka(argv[i], &flag);
        if (flag != 0) {
            s21_reconstruct(argv[i], &cfg);
        }
    }
    /* Прходим все аргументы и аргументы(не флаги) запускаем сверку со структурой
     * В зависимости от флагов в структуре запускаем функции флагов
     * Если количество аргументов(не флагов) меньше нуля запускаем функцию
     * по обработке текста с потока stdin
     */
    for (int j = 1; j < argc; j++) {
        s21_openfile(&cfg, argv[j]);
    }
    return 0;
}
