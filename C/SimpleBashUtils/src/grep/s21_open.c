#include "s21_grep.h"

void s21_open(config *pointer, char *argument, int chet, int strok, char mass_patt[1030][1041]) {
    FILE *fp;
    regex_t str_pattern;
    fp = fopen(argument, "r");
    int do_c = 0;
    int nomer_stroki = 0;
    size_t n = 0;
    regmatch_t pmatch;
    if (pointer->o == 1) {
        n = 1;
    }
    int error;
    if (fp) {
        while (1) {
            char string[1024] = "";
            if (fgets(string, 1000, fp)) {   // считать символы из файла
                #if defined (__APPLE__)
                int num = 0;
                #endif
                int symbol_nachala = 0;
                nomer_stroki++;
                if (feof(fp) != 0 && strlen(string) > 0) {
                    string[strlen(string) - 1] = '\n';
                    string[strlen(string) + 1] = '\0';
                }
                /* проверяем есть ли при флаге -v строки которые компилируются если есть то их пропускаем*/
                int flag_v = 0;
                if (pointer->v == 1) {
                    for (int y = 0; y < strok; y++) {
                        if (do_pattern(&str_pattern, mass_patt[y], pointer) == 0) {
                            if (regexec(&str_pattern, string, (size_t) 0, NULL, 0) == 0) {
                                flag_v = 1;
                            }
                            regfree(&str_pattern);
                        }
                    }
                }
                #if defined (__APPLE__)
                if (pointer->v == 1 && pointer ->o == 1) {
                    pointer->o = 0;
                }
                #endif
                if (pointer->o == 1 && pointer->c == 0 && pointer->l == 0) {
                    int mass[1020];
                    char *ukaz1 = string;
                    for (int g = 0; g < strok; g++) {
                        if (do_pattern(&str_pattern, mass_patt[g], pointer) == 0) {
                            error = regexec(&str_pattern, string, n, &pmatch, 0);
                            while (error == 0) {
                                mass[symbol_nachala] = pmatch.rm_so;
                                symbol_nachala++;
                                ukaz1 += pmatch.rm_eo;
                                error = regexec(&str_pattern, ukaz1, n, &pmatch, 0);
                            }
                            regfree(&str_pattern);
                        }
                    }
                    if (symbol_nachala > 1) {
                        for (int y = 0; y < symbol_nachala - 1; y++) {
                            for (int j = 0 ; j < symbol_nachala - y - 1 ; j++) {
                                if (mass[j] > mass[j+1]) {
                                    int tmp = mass[j];
                                    mass[j] = mass[j+1];
                                    mass[j+1] = tmp;
                                }
                            }
                        }
                    }
                    for (int y = 0; y < symbol_nachala; y++) {
                        if (y > 0) {
                            if (mass[y] == mass[y-1]) {
                                continue;
                            }
                        }
                        for (int g = 0; g < strok; g++) {
                            if (do_pattern(&str_pattern, mass_patt[g], pointer) == 0) {
                                char *ukaz = string;
                                error = regexec(&str_pattern, string, n, &pmatch, 0);
                                if (pmatch.rm_so == mass[y] && error == 0) {
                                    while (error == 0) {
                                        if (error == pointer->v && flag_v == 0) {
                                            #if defined (__linux__)
                                            if (pointer->h == 0) {
                                                if (chet > 1 && pointer->c != 1 && pointer->l != 1) {
                                                    printf("%s:", argument);
                                                }
                                            }
                                            if (pointer->n == 1 && pointer->c == 0 && pointer->l == 0) {
                                                printf("%d:", nomer_stroki);
                                            }
                                            #endif
                                            #if defined (__APPLE__)
                                            if (pointer->h == 0 && num == 0) {
                                                if (chet > 1 && pointer->c != 1 && pointer->l != 1) {
                                                    printf("%s:", argument);
                                                }
                                            }
                                            if (pointer->n == 1 && pointer->c == 0 && pointer->l == 0 &&
                                                num == 0) {
                                                printf("%d:", nomer_stroki);
                                                num = 1;
                                            }
                                            #endif
                                            if (pointer->c != 1 && pointer->l != 1) {
                                                for (int q = pmatch.rm_so; q < pmatch.rm_eo; q++) {
                                                    printf("%c", ukaz[q]);
                                                }
                                            }
                                            printf("\n");
                                            ukaz += pmatch.rm_eo;
                                            error = regexec(&str_pattern, ukaz, n, &pmatch, 0);
                                        } else {
                                            error = 1;
                                        }
                                    }
                                    regfree(&str_pattern);
                                    break;
                                }
                                regfree(&str_pattern);
                            }
                        }
                    }
                } else {
                    for (int i = 0; i < strok; i++) {
                        if (do_pattern(&str_pattern, mass_patt[i], pointer) == 0) {
                            if (regexec(&str_pattern, string, (size_t) 0, NULL, 0) == pointer->v &&
                                flag_v == 0) {
                                if (pointer->h == 0) {
                                    if (chet > 1 && pointer->c != 1 && pointer->l != 1) {
                                        printf("%s:", argument);
                                    }
                                }
                                if (pointer->n == 1 && pointer->c == 0 && pointer->l == 0) {
                                    printf("%d:", nomer_stroki);
                                }
                                #if defined (__linux__)
                                do_c++;
                                #endif
                                #if defined (__APPLE__)
                                if (pointer->l == 1) {
                                    do_c = 1;
                                } else {
                                    do_c++;
                                }
                                #endif
                                if (pointer->c != 1 && pointer->l != 1) {
                                    printf("%s", string);
                                }
                                regfree(&str_pattern);
                                break;
                            }
                        }
                        regfree(&str_pattern);
                    }
                }
            }
            if (feof(fp) != 0) {
                break;
            }
        }
        #if defined (__APPLE__)
        if (pointer->c == 1) {
            if (chet > 1 && pointer->h == 0) {
                printf("%s:", argument);
            }
            printf("%d\n", do_c);
        }
        #endif
        #if defined (__linux__)
        if (pointer->c == 1 && pointer->l == 0) {
            if (chet > 1 && pointer->h == 0) {
                printf("%s:", argument);
            }
            printf("%d\n", do_c);
        }
        #endif
        if (pointer->l == 1 && do_c > 0) {
            printf("%s\n", argument);
        }
    } else {
        if (pointer->s == 0) {
            fprintf(stderr, "grep: %s: Нет такого файла или каталога\n", argument);
        }
    }
    if (fp) {
        fclose(fp);
    }
}
