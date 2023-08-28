#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#include <regex.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct spec {
    int e;
    int i;
    int v;
    int c;
    int l;
    int n;
    int h;
    int s;
    int f;
    int o;
} config;

void s21_init(config *pointer);
void s21_pars(char *argument, config *pointer);
void s21_prov(char *argument, int *flag);
void s21_open(config *pointer, char *argument, int chet, int strok, char mass_patt[1030][1041]);
int do_pattern(regex_t *str_pattern, char *argument, config *pointer);

#endif