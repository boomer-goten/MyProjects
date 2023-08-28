#include "s21_grep.h"

int main(int argc, char** argv) {
    config cfg;
    s21_init(&cfg);
    char mass_patt[1040][1041] = {};
    /* Количество строк */
    int kol_vo = 0;
    /* Проходим все аргументы, проверяем является ли он флагом
     * Если да то записываем данные в структуру в зависимости от самого флага
     * Ecли нет то воспринимаем первый аргумент не флаг, как паттерн.
     * Если мы встречаем флаг -e то следущий аргумент является паттерном
     * Если мы встретим флаг -f то следущий аргумент является файлом с паттерном
     */
    /* pat нужен для того чтобы понять прочитали ли мы паттерн */
    int pat = 0;
    /* chet счетчик аргументов, которые мы будем воспринимать как название файла который нужно открыть */
    int chet = 0;
    for (int i = 1; i < argc; i++) {
        int flag = 1;
        s21_prov(argv[i], &flag);
        if (flag != 0) {
            s21_pars(argv[i], &cfg);
        }
    }
    for (int i = 1; i < argc; i++) {
        /* flag нужен для понимания встретили ли мы флаг или нет */
        int flag = 1;
        s21_prov(argv[i], &flag);
        if (cfg.e == 1 && strchr(argv[i], 'e') != NULL && flag != 0) {
            i++;
            for (size_t h = 0; h < strlen(argv[i]); h++) {
                mass_patt[kol_vo][h] = argv[i][h];
            }
            kol_vo++;
            continue;
        }
        if (cfg.f == 1 && strchr(argv[i], 'f') != NULL && flag != 0) {
            i++;
            FILE *file;
            file = fopen(argv[i], "r");
            int symbol = 0;
            char ch;
            if (file) {
                while (!feof(file)) {
                    ch = fgetc(file);
                    if (ch == EOF) {
                        mass_patt[kol_vo][symbol] = '\0';
                        break;
                    }
                    if (ch == '\n') {
                        mass_patt[kol_vo][symbol] = '\0';
                        kol_vo++;
                        symbol = 0;
                        continue;
                    }
                    mass_patt[kol_vo][symbol] = ch;
                    symbol++;
                }
            }
            if (file) {
                fclose(file);
            }
            continue;
        }
        if (flag != 0) {
            continue;
        }
        if (cfg.e == 0 && flag == 0 && pat == 0 && cfg.f == 0) {
            pat = 1;
            for (size_t h = 0; h < strlen(argv[i]); h++) {
                mass_patt[kol_vo][h] = argv[i][h];
            }
            kol_vo++;
            continue;
        } else {
            chet++;
        }
    }
    /* Прходим все аргументы и аргументы(не флаги) запускаем сверку со структурой
     * В зависимости от флагов в структуре запускаем функции флагов
     */
    pat = 0;
    for (int j = 1; j < argc; j++) {
        int flag = 1;
        s21_prov(argv[j], &flag);
        if (cfg.e == 1 && strchr(argv[j], 'e') != NULL && flag != 0) {
            j++;
            continue;
        }
        if (cfg.f == 1 && strchr(argv[j], 'f') != NULL && flag != 0) {
            j++;
            continue;
        }
        if (flag != 0) {
            continue;
        }
        if (cfg.e == 0 && flag == 0 && pat == 0 && cfg.f == 0) {
            pat = 1;
            continue;
        }
            s21_open(&cfg, argv[j], chet, kol_vo, mass_patt);
    }
    return 0;
}
