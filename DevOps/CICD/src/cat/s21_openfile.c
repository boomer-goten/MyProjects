#include "s21_cat.h"

void s21_openfile(config *pointer, char *argument) {
    FILE *fp;
    fp = fopen(argument, "r");
    if (fp) {
#if defined(__linux__)
        static int i = 1;
        static int j = 1;
        int ch;
#endif
#if defined(__APPLE__)
        int i = 1;
        int j = 1;
        char ch;
#endif
        char temp = '\n';
        char temp1 = '\t';
        int flag_n = 0;
        int flag_b = 0;
        while (!feof(fp)) {
            ch = fgetc(fp);
            if (pointer->s == 1) {
                if ((char)ch == '\n' && temp == '\n' && temp1 == '\n') {
                    continue;
                }
            }
            if ((char)ch == EOF) {
                break;
            }
            if (pointer->b == 1) {
                pointer->n = 0;
                if (((temp == '\n' && (char)ch != '\n') || (flag_b == 0 && (char)ch != '\n'))) {
                    printf("%6d\t", i);
                    i++;
                }
            }
            if (pointer->n == 1 && (temp == '\n' || flag_n == 0)) {
                printf("%6d\t", j);
                j++;
            }
            if (pointer->e == 1 && (char)ch != EOF) {
                if ((char)ch == '\n') {
                    printf("$");
                }
            }
            temp1 = temp;
            temp = (char)ch;
            if (pointer->t == 1) {
                if ((char)ch == '\t') {
                    printf("^I");
                    continue;
                }
            }
            if (pointer->v == 1) {
                if ((ch < 32 || ch >= 126) && ch != 10 && ch != -1 && ch != '\t' && ch >= 0) {
                    s21_do_v(ch);
                    continue;
                }
            }
            printf("%c", ch);
            flag_n = 1;
            flag_b = 1;
        }
    }
    if (fp) {
        fclose(fp);
    }
}
