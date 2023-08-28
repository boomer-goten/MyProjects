#include "./s21_decimal.h"

short s21_dec_exp_to_short(s21_decimal* in) {
  short ret = 0;
  for (int i = 16; i <= 23; i++) {
    ret |= ((in->bits[3] >> i) & 1) << (i - 16);
  }
  return ret;
}

void s21_dec_to_bit_str(s21_decimal* in, char* out) {
  int razr = 0;
  int ost = 0;
  for (int i = 0; i < 96; i++) {
    razr = i / 32;
    ost = i % 32;
    out[i] = (in->bits[razr] >> ost & 1) + '0';
  }
  out[96] = '\0';
}

int s21_dec_to_str_dec(s21_decimal in, str_decimal* out) {
  str_decimal_to_zero(out);
  if (in.bits[3] >> 31 & 1) out->sign = 1;
  char temp[340] = {0};
  out->exp = s21_dec_exp_to_short(&in);
  s21_dec_to_bit_str(&in, &temp[0]);
  bit_str_to_str_dec(&temp[0], &temp[0]);
  reverse_str(temp);
  num_str_delete_all_right_zeros(temp);
  reverse_str(temp);
  snprintf(out->dec, sizeof(out->dec), "%s", &temp[0]);
  return 0;
}

void bit_str_to_str_dec(char* in, char* out) {
  int len = strlen(in);
  char res[340], exp2[340];
  snprintf(exp2, sizeof(exp2), "1");
  snprintf(res, sizeof(res), "0");
  for (int i = 0; i < len; i++) {
    if (in[i] == '1') {
      num_str_add(&res[0], &exp2[0], &res[0], 10);
    }
    num_str_mul(&exp2[0], "2", &exp2[0], 10);
  }
  snprintf(out, sizeof(res), "%s", &res[0]);
}

int num_str_add(char* value_1, char* value_2, char* result, int num_system) {
  char val1[340];
  char val2[340];
  snprintf(val1, sizeof(val1), "%s", value_1);
  snprintf(val2, sizeof(val2), "%s", value_2);
  num_str_prepare(val1, val2);
  unsigned i = 0;
  int temp_res = 0;
  int add_razr = 0;
  for (; i < strlen(val1); i++) {
    temp_res = val1[i] + val2[i] - 2 * '0' + add_razr;
    result[i] = temp_res % num_system + '0';
    result[i + 1] = '\0';
    add_razr = (int)(temp_res / num_system);
  }
  num_str_delete_right_zeros(result);
  reverse_str(result);
  return 0;
}

void num_str_prepare(char* value_1, char* value_2) {
  reverse_str(value_1);
  num_str_delete_right_zeros(value_1);
  reverse_str(value_2);
  num_str_delete_right_zeros(value_2);
  unsigned len_val1 = strlen(value_1);
  unsigned len_val2 = strlen(value_2);
  unsigned len_more = len_val1 < len_val2 ? len_val2 : len_val1;
  unsigned i = len_val1;
  for (; i < len_more + 1; i++) {
    value_1[i] = '0';
  }
  value_1[i] = '\0';
  i = len_val2;
  for (; i < len_more + 1; i++) {
    value_2[i] = '0';
    value_2[i + 1] = '\0';
  }
}

void reverse_str(char* str) {
  int len = strlen(str);
  char temp_str[340];
  for (int j = 0; str[j]; j++) {
    temp_str[j] = str[len - j - 1];
  }
  temp_str[len] = '\0';
  snprintf(str, sizeof(temp_str), "%s", temp_str);
}

void num_str_delete_right_zeros(char* num_str) {
  if (strcmp("0", num_str)) {
    int i = strlen(num_str) - 1;
    while (num_str[i--] == '0' && i > 0) {
      num_str[i + 1] = '\0';
    }
  }
}

int num_str_mul(char* value_1, char* value_2, char* result, int num_system) {
  char temp_res[350];
  int temp_num = 0, add_razr = 0;
  char val1[340] = {'\0'};
  char val2[340] = {'\0'};
  snprintf(val1, sizeof(val1), "%s", value_1);
  snprintf(val2, sizeof(val2), "%s", value_2);
  reverse_str(val1);
  reverse_str(val2);
  snprintf(result, sizeof(val1), "0");
  int i1, i2, pl;
  for (i2 = 0; val2[i2]; i2++) {
    if (val2[i2] != '0') {
      add_razr = 0;
      for (pl = 0; pl < i2; pl++) {
        temp_res[pl] = '0';
      }
      for (i1 = 0; val1[i1]; i1++) {
        temp_num = (val1[i1] - '0') * (val2[i2] - '0') + add_razr;
        temp_res[pl++] = temp_num % num_system + '0';
        add_razr = temp_num / num_system;
      }
      if (add_razr) temp_res[pl++] = add_razr + '0';
      temp_res[pl] = '\0';
      reverse_str(temp_res);
      num_str_add(temp_res, result, result, num_system);
    }
  }
  return 0;
}

int dec_str_universal_add_sub(str_decimal value_1, str_decimal value_2,
                              str_decimal* result) {
  char t1[340], t2[340];
  result->exp = value_1.exp > value_2.exp ? value_1.exp : value_2.exp;
  dec_str_zero_exp(&value_1, &value_2);
  if ((value_1.sign + value_2.sign) % 2 == 1) {
    if (num_str_is_greater(value_1.dec, value_2.dec)) {
      snprintf(t1, sizeof(t1), "%s", value_1.dec);
      snprintf(t2, sizeof(t2), "%s", value_2.dec);
      result->sign = value_1.sign;
    } else {
      snprintf(t1, sizeof(t1), "%s", value_2.dec);
      snprintf(t2, sizeof(t2), "%s", value_1.dec);
      result->sign = value_2.sign;
    }
    num_str_sub_simple(&t1[0], &t2[0], result->dec, 10);
  } else {
    snprintf(t1, sizeof(t1), "%s", value_1.dec);
    snprintf(t2, sizeof(t2), "%s", value_2.dec);
    result->sign = value_1.sign;
    num_str_add(&t1[0], &t2[0], result->dec, 10);
  }
  int err = dec_str_pack_result(result);
  return err;
}

void dec_str_zero_exp(str_decimal* value_1, str_decimal* value_2) {
  int big_exp = value_1->exp >= value_2->exp ? value_1->exp : value_2->exp;
  int len1 = strlen(value_1->dec);
  int len2 = strlen(value_2->dec);
  for (int i = 0; i < big_exp; i++) {
    value_1->exp--;
    value_2->exp--;
    if (value_1->exp < 0) {
      value_1->dec[len1++] = '0';
      value_1->dec[len1] = '\0';
      value_1->exp++;
    }
    if (value_2->exp < 0) {
      value_2->dec[len2++] = '0';
      value_2->dec[len2] = '\0';
      value_2->exp++;
    }
  }
}

int num_str_is_greater(char* str1, char* str2) {
  int ret = 0;
  char str1_temp[340];
  char str2_temp[340];
  snprintf(str1_temp, sizeof(str1_temp), "%s", str1);
  snprintf(str2_temp, sizeof(str2_temp), "%s", str2);
  num_str_prepare(str1_temp, str2_temp);
  int len = strlen(str1_temp);
  for (int i = len - 1; i >= 0; i--) {
    if (str1_temp[i] > str2_temp[i]) {
      ret = 1;
      break;
    } else if (str1_temp[i] < str2_temp[i]) {
      break;
    }
  }
  return ret;
}

int num_str_sub_simple(char* value_1, char* value_2, char* result,
                       int num_system) {
  char val1[340];
  char val2[340];
  snprintf(val1, sizeof(val1), "%s", value_1);
  snprintf(val2, sizeof(val2), "%s", value_2);
  num_str_prepare(val1, val2);
  unsigned len = strlen(value_1);
  unsigned i = 0;
  int temp_res = 0;
  int add_razr = 0;
  for (; i < len; i++) {
    temp_res = val1[i] - val2[i] - add_razr;

    if (temp_res < 0) {
      temp_res = num_system + temp_res;
      add_razr = 1;
    } else {
      add_razr = 0;
    }
    result[i] = temp_res % num_system + '0';
    result[i + 1] = '\0';
  }
  num_str_delete_right_zeros(result);
  reverse_str(result);
  return 0;
}

int dec_str_pack_result(str_decimal* result) {
  int err = 0;
  if (num_str_is_equal(result->dec, "0")) {
    result->exp = 0;
  } else {
    int len = strlen(result->dec);
    char temp[340];
    while (result->exp < 0) {
      result->dec[len++] = '0';
      result->dec[len] = '\0';
      result->exp++;
    }
    int round = -1;
    snprintf(temp, sizeof(temp), "%s", result->dec);
    while (num_str_is_greater(temp, "79228162514264337593543950335") &&
           result->exp > 0) {
      snprintf(temp, sizeof(temp), "%s", result->dec);
      num_str_bank_round(temp, round--);
      result->exp--;
    }
    snprintf(result->dec, sizeof(result->dec), "%s", temp);
    round = -1;
    while (!num_str_is_equal(temp, "0") && result->exp > 28) {
      snprintf(temp, sizeof(temp), "%s", result->dec);
      num_str_bank_round(temp, round--);
      result->exp--;
    }
    snprintf(result->dec, sizeof(result->dec), "%s", temp);
    if (num_str_is_greater(temp, "79228162514264337593543950335")) {
      str_decimal_to_zero(result);
      err = 1;
    }
    if (result->exp > 28) {
      str_decimal_to_zero(result);
      err = 2;
    }
  }
  return err;
}

void num_str_bank_round(char* num_str, int position) {
  // даем строку-число и позицию цифры с конца строки (-1 - последняя цифра,
  // -2 - вторая с конца), по которой будет округление и обрезка строки
  size_t len = strlen(num_str);
  position = len + position;
  if (num_str[position] - '0' > 5 || (num_str[position] - '0' == 5 &&
                                      (num_str[position - 1] - '0') % 2 == 1)) {
    for (int i = position - 1; i > 0; i--) {
      if (num_str[i] == '9') {
        num_str[i] = '0';
      } else {
        num_str[i] += 1;
        break;
      }
    }
  }
  num_str[position] = '\0';
}

int num_str_is_equal(char* str1, char* str2) {
  int ret = 0;
  char str1_temp[340];
  char str2_temp[340];
  snprintf(str1_temp, sizeof(str1_temp), "%s", str1);
  snprintf(str2_temp, sizeof(str2_temp), "%s", str2);
  num_str_prepare(str1_temp, str2_temp);
  int len = strlen(str1_temp);
  for (int i = len - 1; i >= 0; i--) {
    if (str1_temp[i] > str2_temp[i] || str1_temp[i] < str2_temp[i]) {
      ret = 0;
      break;
    } else {
      ret = 1;
    }
  }
  return ret;
}

void str_decimal_to_zero(str_decimal* str_dec) {
  str_dec->dec[0] = '\0';
  str_dec->sign = 0;
  str_dec->exp = 0;
}

int dec_str_mul(str_decimal* value_1, str_decimal* value_2,
                str_decimal* result) {
  str_decimal_to_zero(result);
  result->sign = (value_1->sign + value_2->sign) % 2;
  result->exp = value_1->exp + value_2->exp;
  num_str_mul(value_1->dec, value_2->dec, result->dec, 10);
  int err = dec_str_pack_result(result);
  return err;
}

int dec_str_div(str_decimal* value_1, str_decimal* value_2,
                str_decimal* result) {
  int err = 0;
  str_decimal_to_zero(result);
  if (num_str_is_equal(value_2->dec, "0")) err = 3;
  if (!err) {
    result->sign = (value_1->sign + value_2->sign) % 2;
    result->exp = value_1->exp - value_2->exp;
    result->exp += num_str_div(value_1->dec, value_2->dec, result->dec);
    err = dec_str_pack_result(result);
  }
  return err;
}

int num_str_div(char* value_1, char* value_2, char* result) {
  char temp_delimoe[340] = {'\0'};
  int num_to_result = 0, delimoe_pos = 0;
  size_t i = 0;
  // деление целой части
  for (; i < strlen(value_1); i++) {
    temp_delimoe[delimoe_pos] = value_1[i];
    temp_delimoe[delimoe_pos + 1] = '\0';
    num_to_result = 0;
    for (; num_str_is_greater_or_equal(temp_delimoe, value_2);
         num_to_result++) {
      num_str_sub_simple(temp_delimoe, value_2, temp_delimoe, 10);
    }
    delimoe_pos = strlen(temp_delimoe);
    result[i] = num_to_result + '0';
    result[i + 1] = '\0';
    // printf("%d", num_to_result);
  }
  result[i] = '\0';
  num_str_delete_left_zeros(result);
  i = strlen(result);
  // printf(".");

  // if (num_str_is_greater(temp_delimoe, zero)) result[i++] = '.';

  // деление дробной части
  int exp = 0;
  for (; i < 30 && !num_str_is_equal(temp_delimoe, "0"); i++) {
    delimoe_pos = strlen(temp_delimoe);
    temp_delimoe[delimoe_pos] = '0';
    temp_delimoe[delimoe_pos + 1] = '\0';
    num_to_result = 0;
    for (; num_str_is_greater_or_equal(temp_delimoe, value_2);
         num_to_result++) {
      num_str_sub_simple(temp_delimoe, value_2, temp_delimoe, 10);
    }
    delimoe_pos = strlen(temp_delimoe);
    result[i] = num_to_result + '0';
    exp++;
    // printf("%d", num_to_result);
  }
  result[i] = '\0';
  // printf("\n");
  return exp;
}

int num_str_is_greater_or_equal(char* str1, char* str2) {
  int ret = 1;
  char str1_temp[340];
  char str2_temp[340];
  snprintf(str1_temp, sizeof(str1_temp), "%s", str1);
  snprintf(str2_temp, sizeof(str2_temp), "%s", str2);
  num_str_prepare(str1_temp, str2_temp);
  int len = strlen(str1_temp);
  for (int i = len - 1; i >= 0; i--) {
    if (str1_temp[i] > str2_temp[i]) {
      break;
    } else if (str1_temp[i] < str2_temp[i]) {
      ret = 0;
      break;
    }
  }
  return ret;
}

void num_str_delete_left_zeros(char* num_str) {
  reverse_str(num_str);
  num_str_delete_right_zeros(num_str);
  reverse_str(num_str);
}

int dec_str_mod(str_decimal* value_1, str_decimal* value_2,
                str_decimal* result) {
  int err = 0;
  str_decimal_to_zero(result);
  if (num_str_is_equal(value_2->dec, "0")) err = 3;
  if (!err) {
    result->sign = value_1->sign;
    result->exp = value_1->exp > value_2->exp ? value_1->exp - value_2->exp
                                              : value_2->exp - value_1->exp;
    dec_str_zero_exp(value_1, value_2);
    num_str_mod(value_1->dec, value_2->dec, result->dec);
    err = dec_str_pack_result(result);
  }
  return err;
}

int num_str_mod(char* value_1, char* value_2, char* result) {
  int delimoe_pos = 0;
  char temp_delimoe[340];
  snprintf(temp_delimoe, sizeof(temp_delimoe), "0");
  size_t i = 0;
  for (; i < strlen(value_1); i++) {
    temp_delimoe[delimoe_pos] = value_1[i];
    temp_delimoe[delimoe_pos + 1] = '\0';
    while (num_str_is_greater_or_equal(temp_delimoe, value_2)) {
      num_str_sub_simple(temp_delimoe, value_2, temp_delimoe, 10);
    }
    delimoe_pos = strlen(temp_delimoe);
  }
  snprintf(result, sizeof(temp_delimoe), "%s", temp_delimoe);
  return 0;
}

void num_str_delete_all_right_zeros(char* num_str) {
  if (strcmp("0", num_str)) {
    int i = strlen(num_str) - 1;
    while (num_str[i] == '0' && i > 0) {
      num_str[i] = '\0';
      i--;
    }
  }
}

int str_dec_to_s21_dec(str_decimal in, s21_decimal* out) {
  for (int i = 0; i < 4; i++) out->bits[i] = 0;
  char temp_str[340];
  from_str_to_binary(in.dec, temp_str, 10);
  int razr = 0;
  int ost = 0;
  for (int i = 0; temp_str[i]; i++) {
    razr = i / 32;
    ost = i % 32;
    out->bits[razr] |= (temp_str[i] - '0') << ost;
  }
  for (int i = 0; i < 8; i++) {
    out->bits[3] |= (in.exp >> i & 1) << (i + 16);
  }
  if (in.sign) {
    out->bits[3] |= 1 << 31;
  }
  return 0;
}

void from_str_to_binary(char* in, char* out, int in_num_system) {
  char temp_str[340] = {'\0'};
  out[0] = '0';
  out[1] = '\0';
  int ostatok = 0;
  snprintf(temp_str, sizeof(temp_str), "%s", in);
  int i = 0;
  while (num_str_is_greater(temp_str, "0")) {
    ostatok = div_by_int_ret_ost(temp_str, 2, in_num_system, temp_str);
    out[i++] = ostatok + '0';
    out[i] = '\0';
  }
}

unsigned div_by_int_ret_ost(char* delimoe, int devisor, int num_system,
                            char* result) {
  unsigned temp_del = 0;
  unsigned pos_res = 0;
  for (int i = 0; delimoe[i]; i++) {
    temp_del = temp_del * num_system + delimoe[i] - '0';
    result[pos_res++] = (unsigned)(temp_del / devisor) + '0';

    temp_del -= devisor * (unsigned)(temp_del / devisor);
  }
  result[pos_res] = '\0';
  num_str_delete_left_zeros(result);
  return temp_del;
}