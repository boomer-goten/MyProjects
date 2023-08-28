// -0.02048
#include "../header.h"

// Максимальное возможное число
START_TEST(dec_to_str_1) {
  char *etalon = "79228162514264337593543950335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  number1.bits[3] = 0;
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_2) {
  char *etalon = "7922816251426433759354395033.5";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_3) {
  char *etalon = "792281625142643375935439503.35";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(2, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_4) {
  char *etalon = "79228162514264337593543950.335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(3, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_5) {
  char *etalon = "7922816251426433759354395.0335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(4, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_6) {
  char *etalon = "792281625142643375935439.50335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(5, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_7) {
  char *etalon = "79228162514264337593543.950335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(6, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_8) {
  char *etalon = "7922816251426433759354.3950335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(7, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_9) {
  char *etalon = "792281625142643375935.43950335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(8, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_10) {
  char *etalon = "79228162514264337593.543950335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(9, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_11) {
  char *etalon = "7922816251426433759.3543950335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(10, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_12) {
  char *etalon = "792281625142643375.93543950335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(11, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_13) {
  char *etalon = "79228162514264337.593543950335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(12, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_14) {
  char *etalon = "7922816251426433.7593543950335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(13, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_15) {
  char *etalon = "792281625142643.37593543950335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(14, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_16) {
  char *etalon = "79228162514264.337593543950335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(15, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_17) {
  char *etalon = "7922816251426.4337593543950335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(16, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_18) {
  char *etalon = "792281625142.64337593543950335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(17, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_19) {
  char *etalon = "79228162514.264337593543950335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(18, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_20) {
  char *etalon = "7922816251.4264337593543950335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(19, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_21) {
  char *etalon = "792281625.14264337593543950335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(20, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_22) {
  char *etalon = "79228162.514264337593543950335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(21, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_23) {
  char *etalon = "7922816.2514264337593543950335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(22, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_24) {
  char *etalon = "792281.62514264337593543950335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(23, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_25) {
  char *etalon = "79228.162514264337593543950335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(24, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_26) {
  char *etalon = "7922.8162514264337593543950335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(25, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_27) {
  char *etalon = "792.28162514264337593543950335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(26, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_28) {
  char *etalon = "79.228162514264337593543950335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(27, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_29) {
  char *etalon = "7.9228162514264337593543950335";
  s21_decimal number1 = {0};
  number1.bits[0] = UINT_MAX;
  number1.bits[1] = UINT_MAX;
  number1.bits[2] = UINT_MAX;
  zapis_stepeni_v_decimal(28, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_30) {
  char *etalon = "0.0000000000000000004294967295";
  s21_decimal number1 = {0};
  number1.bits[0] = 4294967295;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  zapis_stepeni_v_decimal(28, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_31) {
  char *etalon = "-0.02048";
  s21_decimal number1 = {0};
  number1.bits[0] = 2048;
  number1.bits[1] = 0;
  number1.bits[2] = 0;
  number1.bits[3] = 2147811328;
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(etalon, result);
}
END_TEST

START_TEST(dec_to_str_32) {
  char *a = "79228162514264337593543950335";
  char *b = "-79228162514264337593543950335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_33) {
  char *a = "79228162514264337593543950334";
  char *b = "-79228162514264337593543950334";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_34) {
  char *a = "792281625142643375935439534";
  char *b = "-792281625142643375935439534";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_35) {
  char *a = "79228426433759354394";
  char *b = "-79228426433759354334";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_36) {
  char *a = "4337593543950334";
  char *b = "-4337593543950334";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_37) {
  char *a = "9251426433750334";
  char *b = "-9251426433750334";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_38) {
  char *a = "9426433750334";
  char *b = "-9426433750334";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_39) {
  char *a = "2124350334";
  char *b = "-2124350334";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_40) {
  char *a = "9251334";
  char *b = "-9251334";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_41) {
  char *a = "1334";
  char *b = "-1334";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_42) {
  char *a = "1334";
  char *b = "-1334";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_43) {
  char *a = "334";
  char *b = "-334";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_44) {
  char *a = "34";
  char *b = "-34";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_45) {
  char *a = "1";
  char *b = "-1";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_46) {
  char *a = "0";
  char *b = "0";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_47) {
  char *a = "7.7922816251426433759354395033";
  char *b = "-7.7922816251426433759354395033";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_48) {
  char *a = "7.9228162514264337593543950335";
  char *b = "-7.9228162514264337593543950335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_49) {
  char *a = "7922816251426433.7593543950335";
  char *b = "-7922816251426433.7593543950335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_50) {
  char *a = "792281625142643375935.43950335";
  char *b = "-792281625142643375935.43950335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_51) {
  char *a = "7922816251426433759354395.0335";
  char *b = "-7922816251426433759354395.0335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_52) {
  char *a = "7922816251426433759354395033.5";
  char *b = "-7922816251426433759354395033.5";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_53) {
  char *a = "0.0028162514264337593543950335";
  char *b = "-0.0028162514264337593543950335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_54) {
  char *a = "0.0000000514264337593543950335";
  char *b = "-0.0000000514264337593543950335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_55) {
  char *a = "0.0000000000264337593543950335";
  char *b = "-0.0000000000264337593543950335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_56) {
  char *a = "0.0000000000004337593543950335";
  char *b = "-0.0000000000004337593543950335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_57) {
  char *a = "0.0000000000000000000000950335";
  char *b = "-0.0000000000000000000000950335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_58) {
  char *a = "0.0000000000000000000000000005";
  char *b = "-0.0000000000000000000000000005";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_59) {
  char *a = "0.0000000000000000000000000001";
  char *b = "-0.0000000000000000000000000001";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str_60) {
  char *a = "0.0000000000000001";
  char *b = "-0.0000000000000001";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq(a, result);
  memset(result, '\0', BUF);
  dec_to_string(&number2, result);
  ck_assert_str_eq(b, result);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_add;

  s = suite_create("Decimal to string");

  tc_add = tcase_create("Decimal to string");
  tcase_add_test(tc_add, dec_to_str_1);
  tcase_add_test(tc_add, dec_to_str_2);
  tcase_add_test(tc_add, dec_to_str_3);
  tcase_add_test(tc_add, dec_to_str_4);
  tcase_add_test(tc_add, dec_to_str_5);
  tcase_add_test(tc_add, dec_to_str_6);
  tcase_add_test(tc_add, dec_to_str_7);
  tcase_add_test(tc_add, dec_to_str_8);
  tcase_add_test(tc_add, dec_to_str_9);
  tcase_add_test(tc_add, dec_to_str_10);
  tcase_add_test(tc_add, dec_to_str_11);
  tcase_add_test(tc_add, dec_to_str_12);
  tcase_add_test(tc_add, dec_to_str_13);
  tcase_add_test(tc_add, dec_to_str_14);
  tcase_add_test(tc_add, dec_to_str_15);
  tcase_add_test(tc_add, dec_to_str_16);
  tcase_add_test(tc_add, dec_to_str_17);
  tcase_add_test(tc_add, dec_to_str_18);
  tcase_add_test(tc_add, dec_to_str_19);
  tcase_add_test(tc_add, dec_to_str_20);
  tcase_add_test(tc_add, dec_to_str_21);
  tcase_add_test(tc_add, dec_to_str_22);
  tcase_add_test(tc_add, dec_to_str_23);
  tcase_add_test(tc_add, dec_to_str_24);
  tcase_add_test(tc_add, dec_to_str_25);
  tcase_add_test(tc_add, dec_to_str_26);
  tcase_add_test(tc_add, dec_to_str_27);
  tcase_add_test(tc_add, dec_to_str_28);
  tcase_add_test(tc_add, dec_to_str_29);
  tcase_add_test(tc_add, dec_to_str_30);
  tcase_add_test(tc_add, dec_to_str_31);
  tcase_add_test(tc_add, dec_to_str_32);
  tcase_add_test(tc_add, dec_to_str_33);
  tcase_add_test(tc_add, dec_to_str_34);
  tcase_add_test(tc_add, dec_to_str_35);
  tcase_add_test(tc_add, dec_to_str_36);
  tcase_add_test(tc_add, dec_to_str_37);
  tcase_add_test(tc_add, dec_to_str_38);
  tcase_add_test(tc_add, dec_to_str_39);
  tcase_add_test(tc_add, dec_to_str_40);
  tcase_add_test(tc_add, dec_to_str_41);
  tcase_add_test(tc_add, dec_to_str_42);
  tcase_add_test(tc_add, dec_to_str_43);
  tcase_add_test(tc_add, dec_to_str_44);
  tcase_add_test(tc_add, dec_to_str_45);
  tcase_add_test(tc_add, dec_to_str_46);
  tcase_add_test(tc_add, dec_to_str_47);
  tcase_add_test(tc_add, dec_to_str_48);
  tcase_add_test(tc_add, dec_to_str_49);
  tcase_add_test(tc_add, dec_to_str_50);
  tcase_add_test(tc_add, dec_to_str_51);
  tcase_add_test(tc_add, dec_to_str_52);
  tcase_add_test(tc_add, dec_to_str_53);
  tcase_add_test(tc_add, dec_to_str_54);
  tcase_add_test(tc_add, dec_to_str_55);
  tcase_add_test(tc_add, dec_to_str_56);
  tcase_add_test(tc_add, dec_to_str_57);
  tcase_add_test(tc_add, dec_to_str_58);
  tcase_add_test(tc_add, dec_to_str_59);
  tcase_add_test(tc_add, dec_to_str_60);
  suite_add_tcase(s, tc_add);

  return s;
}

int main() {
  int number_failed;
  Suite *s;
  SRunner *sr;
  s = sprintf_test();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
