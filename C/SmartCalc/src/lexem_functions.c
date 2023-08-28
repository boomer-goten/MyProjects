#include "s21_calc.h"

void push_lex(lexema lex, lexema* mass, int* front, int* rear) {
  if (*front == -1) *front = 0;
  (*rear)++;
  mass[*rear] = lex;
}

void print_lex(lexema* mass, int* front, int* rear) {
  for (int i = *front; i <= *rear; i++)
    printf("%s   %d\n", mass[i].value, mass[i].unarnost);
}

int check_lexems(lexema* mass, int* front, int* rear) {
  int status = OK;
  int count_skob = 0;
  for (int i = *front; i <= *rear; i++) {
    if (mass[i].unarnost == 1) {
      if (i == *rear) {
        status = BAD_EXPRESSION;
      } else {
        if (mass[i + 1].unarnost == 0 || !strcmp(mass[i + 1].value, "(")) {
        } else if (!strcmp(mass[i].value, "+") || !strcmp(mass[i].value, "-")) {
          if (!strcmp(mass[i + 1].value, "+") ||
              !strcmp(mass[i + 1].value, "-")) {
            status = BAD_EXPRESSION;
          }
        } else if ((strcmp(mass[i].value, "+") && strcmp(mass[i].value, "-"))) {
          if ((strcmp(mass[i + 1].value, "+") && mass[i].unarnost == 2) ||
              (strcmp(mass[i + 1].value, "-") && mass[i].unarnost == 2)) {
            status = BAD_EXPRESSION;
          }
        } else {
          status = BAD_EXPRESSION;
        }
      }
    } else if (mass[i].unarnost == 2) {
      if (!strcmp(mass[i].value, "(") || !strcmp(mass[i].value, ")")) {
        if (!strcmp(mass[i].value, "(")) {
          if (i == *rear) {
            status = BAD_EXPRESSION;
          } else if (i == *front) {
            if (mass[i + 1].unarnost == 2 && strcmp(mass[i + 1].value, "(")) {
              status = BAD_EXPRESSION;
            }
          } else {
            if ((mass[i + 1].unarnost == 2 && strcmp(mass[i + 1].value, "(")) ||
                mass[i - 1].unarnost == 0) {
              status = BAD_EXPRESSION;
            }
          }
          count_skob++;
        } else {
          if (i == *rear) {
            if (mass[i - 1].unarnost == 0 ||
                (mass[i - 1].unarnost == 2 &&
                 !strcmp(mass[i - 1].value, ")"))) {
            } else {
              status = BAD_EXPRESSION;
            }
          } else if (i == *front) {
            if (mass[i + 1].unarnost == 2) {
              if (!strcmp(mass[i + 1].value, "(")) {
                status = BAD_EXPRESSION;
              }
            } else {
              status = BAD_EXPRESSION;
            }
          } else {
            if (mass[i + 1].unarnost == 2) {
              if (!strcmp(mass[i + 1].value, "(")) {
                status = BAD_EXPRESSION;
              }
            } else {
              status = BAD_EXPRESSION;
            }
            if (mass[i - 1].unarnost == 0 ||
                (mass[i - 1].unarnost == 2 &&
                 !strcmp(mass[i - 1].value, ")"))) {
            } else {
              status = BAD_EXPRESSION;
            }
          }
          count_skob--;
        }
      } else {
        if (i == *rear || i == *front) {
          status = BAD_EXPRESSION;
        } else {
          if (mass[i - 1].unarnost == 0 ||
              (mass[i - 1].unarnost == 2 && !strcmp(mass[i - 1].value, ")"))) {
          } else {
            status = BAD_EXPRESSION;
          }
          if (mass[i + 1].unarnost == 2 && strcmp(mass[i + 1].value, "(")) {
            status = BAD_EXPRESSION;
          }
        }
      }
    } else if (mass[i].unarnost == 0) {
      if (i == *rear) {
        if (!strcmp(mass[i - 1].value, ")")) {
          status = BAD_EXPRESSION;
        }
      } else if (i == *front) {
        if (!strcmp(mass[i + 1].value, "(") || mass[i + 1].unarnost == 1) {
          status = BAD_EXPRESSION;
        }
      } else {
        if (!strcmp(mass[i + 1].value, "(") || mass[i + 1].unarnost == 1 ||
            !strcmp(mass[i - 1].value, ")")) {
          status = BAD_EXPRESSION;
        }
      }
    }
    if (count_skob < 0) {
      status = BAD_EXPRESSION;
    }
    // printf("status=%d   i=%i    %s\n", status, i, mass[i].value);
  }
  if (count_skob != 0) {
    status = BAD_EXPRESSION;
  }
  return status;
}
