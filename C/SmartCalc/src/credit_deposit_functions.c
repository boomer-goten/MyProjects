#include "s21_calc.h"

int char_is_empty(char* tmp) {
  int status = OK;
  if (tmp[0] == '\0') {
    status = BAD_EXPRESSION;
  }
  return status;
}

int double_is_true(char* tmp, double* result) {
  int status = OK;
  int count_tochka = 0, i = 0;
  while ((tmp[i] >= '0' && tmp[i] <= '9') || tmp[i] == '.') {
    if (tmp[i] == '.') count_tochka++;
    i++;
    if (count_tochka > 1) {
      status = BAD_EXPRESSION;
      break;
    }
  }
  int size = strlen(tmp);
  if (size != i) {
    status = BAD_EXPRESSION;
  } else {
    if (strchr(tmp, '.') != NULL) {
      int cnt = 0;
      while (tmp[cnt] != '\0') {
        if (tmp[cnt] == '.') {
          tmp[cnt] = ',';
          break;
        }
        cnt++;
      }
    }
    *result = atof(tmp);
  }
  return status;
}

int int_is_true(char* tmp, int* result) {
  int status = OK;
  int i = 0;
  while (tmp[i] >= '0' && tmp[i] <= '9') {
    i++;
  }
  int size = strlen(tmp);
  if (size != i) {
    status = BAD_EXPRESSION;
  } else {
    *result = atoi(tmp);
  }
  return status;
}

void take_from_spisok_viplat(char* spisok, int* count) {
  if (strcmp(spisok, "раз в месяц") == 0) {
    *count = 1;
  } else if (strcmp(spisok, "раз в квартал") == 0) {
    *count = 3;
  } else if (strcmp(spisok, "раз в полгода") == 0) {
    *count = 6;
  } else if (strcmp(spisok, "раз в год") == 0) {
    *count = 12;
  } else if (strcmp(spisok, "в конце срока") == 0) {
    *count = 13;
  }
}

void take_from_spisok(char* spisok, int* count) {
  if (strcmp(spisok, "Разовое") == 0) {
    *count = -1;
  } else if (strcmp(spisok, "Раз в месяц") == 0) {
    *count = 1;
  } else if (strcmp(spisok, "Раз в 2 месяца") == 0) {
    *count = 2;
  } else if (strcmp(spisok, "Раз в квартал") == 0) {
    *count = 3;
  } else if (strcmp(spisok, "Раз в полгода") == 0) {
    *count = 6;
  } else if (strcmp(spisok, "Раз в год") == 0) {
    *count = 12;
  } else if (strcmp(spisok, "Нет") == 0) {
    *count = 13;
  }
}

int take_from_date(char* date, int* day, int* month, int* year) {
  int status = OK;
  int i = 0, j = 0;
  char mass_day[10] = "\0";
  char mass_month[10] = "\0";
  char mass_year[10] = "\0";
  int count_tochka = 0;
  memset(mass_day, '\0', 10);
  memset(mass_month, '\0', 10);
  memset(mass_year, '\0', 10);
  while (date[i] != '\0') {
    if (date[i] >= '0' && date[i] <= '9') {
      if (count_tochka == 0) {
        mass_day[j] = date[i];
      } else if (count_tochka == 1) {
        mass_month[j] = date[i];
      } else if (count_tochka == 2) {
        mass_year[j] = date[i];
      } else {
        status = BAD_EXPRESSION;
        break;
      }
      j++;
      i++;
    } else if (date[i] == '.') {
      j = 0;
      i++;
      count_tochka++;
    } else {
      status = BAD_EXPRESSION;
      break;
    }
  }
  if (status == OK) {
    *day = atoi(mass_day);
    *month = atoi(mass_month);
    *year = atoi(mass_year);
  }
  switch (*month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      if (*day > 31) {
        status = BAD_EXPRESSION;
      }
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      if (*day > 30) {
        status = BAD_EXPRESSION;
      }
      break;
    case 2:
      if (*day > 28) {
        status = BAD_EXPRESSION;
      }
      break;
    default:
      status = BAD_EXPRESSION;
      break;
  }
  if (*year > 99 || *year < 0) {
    status = BAD_EXPRESSION;
  }
  return status;
}

int double_is_true_for_x(char* tmp, double* result) {
  int status = OK;
  int count_tochka = 0, i = 0;
  while ((tmp[i] >= '0' && tmp[i] <= '9') || tmp[i] == '.' || tmp[i] == '-' ||
         tmp[i] == '+') {
    if (i == 0 && (tmp[i] == '-' || tmp[i] == '+')) {
      i++;
    } else if (i == 1 && (tmp[i] == '-' || tmp[i] == '+')) {
      status = BAD_EXPRESSION;
    }
    if (tmp[i] == '.') count_tochka++;
    i++;
    if (count_tochka > 1) {
      status = BAD_EXPRESSION;
      break;
    }
  }
  int size = strlen(tmp);
  if (size != i) {
    status = BAD_EXPRESSION;
  } else {
    if (strchr(tmp, '.') != NULL) {
      int cnt = 0;
      while (tmp[cnt] != '\0') {
        if (tmp[cnt] == '.') {
          tmp[cnt] = ',';
          break;
        }
        cnt++;
      }
    }
    *result = atof(tmp);
  }
  return status;
}