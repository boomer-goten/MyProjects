#include "../header.h"

START_TEST(char_to_decimal_01) {
  char str[] = "1925571";
  s21_decimal value = {0}, test_value = {0};
  value = char_to_decimal(str);
  test_value.bits[0] = 1925571;
  for (size_t i = 0; i < 4; i++) {
    ck_assert_int_eq(value.bits[i], test_value.bits[i]);
  }
}
END_TEST

START_TEST(char_to_decimal_02) {
  char str[] = "1925571.6203672";
  s21_decimal value = {0}, test_value = {0};
  value = char_to_decimal(str);
  test_value.bits[0] = 1377815704;
  test_value.bits[1] = 4483;
  zapis_stepeni_v_decimal(7, &test_value);
  for (size_t i = 0; i < 4; i++) {
    ck_assert_int_eq(value.bits[i], test_value.bits[i]);
  }
}
END_TEST

START_TEST(char_to_decimal_1) {
  char etalon[] = "79228162514264337593543950335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  test_value.bits[3] = 0;
  value = char_to_decimal(etalon);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_2) {
  char etalon[] = "7922816251426433759354395033.5";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(1, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_3) {
  char etalon[] = "792281625142643375935439503.35";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(2, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_4) {
  char etalon[] = "79228162514264337593543950.335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(3, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_5) {
  char etalon[] = "7922816251426433759354395.0335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(4, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_6) {
  char etalon[] = "792281625142643375935439.50335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(5, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_7) {
  char etalon[] = "79228162514264337593543.950335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(6, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_8) {
  char etalon[] = "7922816251426433759354.3950335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(7, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_9) {
  char etalon[] = "792281625142643375935.43950335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(8, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_10) {
  char etalon[] = "79228162514264337593.543950335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(9, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_11) {
  char etalon[] = "7922816251426433759.3543950335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(10, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_12) {
  char etalon[] = "792281625142643375.93543950335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(11, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_13) {
  char etalon[] = "79228162514264337.593543950335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(12, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_14) {
  char etalon[] = "7922816251426433.7593543950335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(13, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_15) {
  char etalon[] = "792281625142643.37593543950335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(14, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_16) {
  char etalon[] = "79228162514264.337593543950335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(15, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_17) {
  char etalon[] = "7922816251426.4337593543950335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(16, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_18) {
  char etalon[] = "792281625142.64337593543950335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(17, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_19) {
  char etalon[] = "79228162514.264337593543950335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(18, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_20) {
  char etalon[] = "7922816251.4264337593543950335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(19, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_21) {
  char etalon[] = "792281625.14264337593543950335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(20, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_22) {
  char etalon[] = "79228162.514264337593543950335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(21, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_23) {
  char etalon[] = "7922816.2514264337593543950335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(22, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_24) {
  char etalon[] = "792281.62514264337593543950335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(23, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_25) {
  char etalon[] = "79228.162514264337593543950335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(24, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_26) {
  char etalon[] = "7922.8162514264337593543950335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(25, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_27) {
  char etalon[] = "792.28162514264337593543950335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(26, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_28) {
  char etalon[] = "79.228162514264337593543950335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(27, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_29) {
  char etalon[] = "7.9228162514264337593543950335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(28, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_30) {
  char etalon[] = "0.0000000000000000000000000001";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = 1;
  test_value.bits[1] = 0;
  test_value.bits[2] = 0;
  zapis_stepeni_v_decimal(28, &test_value);
  value = char_to_decimal(etalon);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_31) {
  char etalon[] = "-0.0000000000000000000000000001";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = 1;
  test_value.bits[1] = 0;
  test_value.bits[2] = 0;
  test_value.bits[3] = 0;
  zapis_stepeni_v_decimal(28, &test_value);
  s21_negate(test_value, &test_value);

  value = char_to_decimal(etalon);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

START_TEST(char_to_decimal_32) {
  char etalon[] = "-7.9228162514264337593543950335";
  s21_decimal value = {0}, test_value = {0};
  test_value.bits[0] = UINT_MAX;
  test_value.bits[1] = UINT_MAX;
  test_value.bits[2] = UINT_MAX;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(28, &test_value);
  s21_negate(test_value, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

// отрицательное минимальное значение
START_TEST(char_to_decimal_33) {
  char etalon[] = "-429496729.5";
  s21_decimal value = {0}, test_value = {0};
  // for (i = 0; i <= 16)
  test_value.bits[0] = 4294967295;
  value = char_to_decimal(etalon);
  zapis_stepeni_v_decimal(1, &test_value);
  s21_negate(test_value, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

// отрицательный ноль
START_TEST(char_to_decimal_35) {
  char etalon[] = "-0";
  s21_decimal value = {0}, test_value = {0};
  value = char_to_decimal(etalon);
  s21_negate(test_value, &test_value);
  ck_assert_int_eq(value.bits[0], test_value.bits[0]);
  ck_assert_int_eq(value.bits[1], test_value.bits[1]);
  ck_assert_int_eq(value.bits[2], test_value.bits[2]);
  ck_assert_int_eq(value.bits[3], test_value.bits[3]);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_is_char_to_decimal;

  s = suite_create("char_to_decimal");

  tc_is_char_to_decimal = tcase_create("char_to_decimal");
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_01);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_02);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_1);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_2);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_3);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_4);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_5);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_6);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_7);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_8);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_9);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_10);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_11);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_12);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_13);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_14);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_15);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_16);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_17);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_18);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_19);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_20);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_21);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_22);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_23);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_24);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_25);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_26);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_27);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_28);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_29);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_30);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_31);

  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_32);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_33);
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_35);
  suite_add_tcase(s, tc_is_char_to_decimal);

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
