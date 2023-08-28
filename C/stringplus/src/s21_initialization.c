#include "./s21_string.h"

// Инициализация пустой структуры

void s21_initialization(config *cfg) {
    cfg->minus = 0;
    cfg->plus = 0;
    cfg->space = 0;
    cfg->width = 0;
    cfg->accuracy = 0;
    cfg->length_h = 0;
    cfg->length_l = 0;
    cfg->tochka = 0;
    cfg->zero = 0;
    cfg->type = '\0';
}
