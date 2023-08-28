#include "../header.h"

// Максимальное возможное число
START_TEST(negate_1) {
  char *etalon = "79228162514264337593543950335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-79228162514264337593543950335", result);
}
END_TEST

START_TEST(negate_2) {
  char *etalon = "7922816251426433759354395033.5";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-7922816251426433759354395033.5", result);
}
END_TEST

START_TEST(negate_3) {
  char *etalon = "792281625142643375935439503.35";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-792281625142643375935439503.35", result);
}
END_TEST

START_TEST(negate_4) {
  char *etalon = "79228162514264337593543950.335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-79228162514264337593543950.335", result);
}
END_TEST

START_TEST(negate_5) {
  char *etalon = "7922816251426433759354395.0335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-7922816251426433759354395.0335", result);
}
END_TEST

START_TEST(negate_6) {
  char *etalon = "792281625142643375935439.50335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-792281625142643375935439.50335", result);
}
END_TEST

START_TEST(negate_7) {
  char *etalon = "79228162514264337593543.950335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-79228162514264337593543.950335", result);
}
END_TEST

START_TEST(negate_8) {
  char *etalon = "7922816251426433759354.3950335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-7922816251426433759354.3950335", result);
}
END_TEST

START_TEST(negate_9) {
  char *etalon = "792281625142643375935.43950335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-792281625142643375935.43950335", result);
}
END_TEST

START_TEST(negate_10) {
  char *etalon = "79228162514264337593.543950335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-79228162514264337593.543950335", result);
}
END_TEST

START_TEST(negate_11) {
  char *etalon = "7922816251426433759.3543950335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-7922816251426433759.3543950335", result);
}
END_TEST

START_TEST(negate_12) {
  char *etalon = "792281625142643375.93543950335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-792281625142643375.93543950335", result);
}
END_TEST

START_TEST(negate_13) {
  char *etalon = "79228162514264337.593543950335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-79228162514264337.593543950335", result);
}
END_TEST

START_TEST(negate_14) {
  char *etalon = "7922816251426433.7593543950335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-7922816251426433.7593543950335", result);
}
END_TEST

START_TEST(negate_15) {
  char *etalon = "792281625142643.37593543950335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-792281625142643.37593543950335", result);
}
END_TEST

START_TEST(negate_16) {
  char *etalon = "79228162514264.337593543950335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-79228162514264.337593543950335", result);
}
END_TEST

START_TEST(negate_17) {
  char *etalon = "7922816251426.4337593543950335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-7922816251426.4337593543950335", result);
}
END_TEST

START_TEST(negate_18) {
  char *etalon = "792281625142.64337593543950335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-792281625142.64337593543950335", result);
}
END_TEST

START_TEST(negate_19) {
  char *etalon = "79228162514.264337593543950335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-79228162514.264337593543950335", result);
}
END_TEST

START_TEST(negate_20) {
  char *etalon = "7922816251.4264337593543950335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-7922816251.4264337593543950335", result);
}
END_TEST

START_TEST(negate_21) {
  char *etalon = "792281625.14264337593543950335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-792281625.14264337593543950335", result);
}
END_TEST

START_TEST(negate_22) {
  char *etalon = "79228162.514264337593543950335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-79228162.514264337593543950335", result);
}
END_TEST

START_TEST(negate_23) {
  char *etalon = "7922816.2514264337593543950335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-7922816.2514264337593543950335", result);
}
END_TEST

START_TEST(negate_24) {
  char *etalon = "792281.62514264337593543950335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-792281.62514264337593543950335", result);
}
END_TEST

START_TEST(negate_25) {
  char *etalon = "79228.162514264337593543950335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-79228.162514264337593543950335", result);
}
END_TEST

START_TEST(negate_26) {
  char *etalon = "7922.8162514264337593543950335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-7922.8162514264337593543950335", result);
}
END_TEST

START_TEST(negate_27) {
  char *etalon = "792.28162514264337593543950335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-792.28162514264337593543950335", result);
}
END_TEST

START_TEST(negate_28) {
  char *etalon = "79.228162514264337593543950335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-79.228162514264337593543950335", result);
}
END_TEST

START_TEST(negate_29) {
  char *etalon = "7.9228162514264337593543950335";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-7.9228162514264337593543950335", result);
}
END_TEST

START_TEST(negate_30) {
  char *etalon = "0.0000000000000000004294967295";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-0.0000000000000000004294967295", result);
}
END_TEST

START_TEST(negate_31) {
  char *etalon = "-0.02048";
  s21_decimal number1 = {0};
  number1 = char_to_decimal(etalon);
  s21_negate(number1, &number1);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("0.02048", result);
}
END_TEST

START_TEST(negate_32) {
  char *etalon = "79228162514264337593543950335";
  char *etalon_b = "-79228162514264337593543950335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-79228162514264337593543950335", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("79228162514264337593543950335", result2);
}
END_TEST

// HEREHEREHERE
START_TEST(negate_33) {
  char *etalon = "79228162514264337593543950334";
  char *etalon_b = "-79228162514264337593543950334";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-79228162514264337593543950334", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("79228162514264337593543950334", result2);
}
END_TEST

START_TEST(negate_34) {
  char *etalon = "792281625142643375935439534";
  char *etalon_b = "-792281625142643375935439534";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-792281625142643375935439534", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("792281625142643375935439534", result2);
}
END_TEST

START_TEST(negate_35) {
  char *etalon = "79228426433759354394";
  char *etalon_b = "-79228426433759354394";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-79228426433759354394", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("79228426433759354394", result2);
}
END_TEST

START_TEST(negate_36) {
  char *etalon = "4337593543950334";
  char *etalon_b = "-4337593543950334";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-4337593543950334", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("4337593543950334", result2);
}
END_TEST

START_TEST(negate_37) {
  char *etalon = "9251426433750334";
  char *etalon_b = "-9251426433750334";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-9251426433750334", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("9251426433750334", result2);
}
END_TEST

START_TEST(negate_38) {
  char *etalon = "9426433750334";
  char *etalon_b = "-9426433750334";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-9426433750334", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("9426433750334", result2);
}
END_TEST

START_TEST(negate_39) {
  char *etalon = "2124350334";
  char *etalon_b = "-2124350334";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-2124350334", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("2124350334", result2);
}
END_TEST

START_TEST(negate_40) {
  char *etalon = "9251334";
  char *etalon_b = "-9251334";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-9251334", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("9251334", result2);
}
END_TEST

START_TEST(negate_41) {
  char *etalon = "1334";
  char *etalon_b = "-1334";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-1334", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("1334", result2);
}
END_TEST

START_TEST(negate_42) {
  char *etalon = "1314";
  char *etalon_b = "-1314";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-1314", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("1314", result2);
}
END_TEST

START_TEST(negate_43) {
  char *etalon = "334";
  char *etalon_b = "-334";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-334", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("334", result2);
}
END_TEST

START_TEST(negate_44) {
  char *etalon = "34";
  char *etalon_b = "-34";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-34", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("34", result2);
}
END_TEST

START_TEST(negate_45) {
  char *etalon = "1";
  char *etalon_b = "-1";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-1", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("1", result2);
}
END_TEST

START_TEST(negate_46) {
  char *etalon = "0.000001";
  char *etalon_b = "-0.000001";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-0.000001", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("0.000001", result2);
}
END_TEST

START_TEST(negate_47) {
  char *etalon = "7.7922816251426433759354395033";
  char *etalon_b = "-7.7922816251426433759354395033";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-7.7922816251426433759354395033", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("7.7922816251426433759354395033", result2);
}
END_TEST

START_TEST(negate_48) {
  char *etalon = "7.9228162514264337593543950335";
  char *etalon_b = "-7.9228162514264337593543950335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-7.9228162514264337593543950335", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("7.9228162514264337593543950335", result2);
}
END_TEST

START_TEST(negate_49) {
  char *etalon = "7922816251426433.7593543950335";
  char *etalon_b = "-7922816251426433.7593543950335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-7922816251426433.7593543950335", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("7922816251426433.7593543950335", result2);
}
END_TEST

START_TEST(negate_50) {
  char *etalon = "792281625142643375935.43950335";
  char *etalon_b = "-792281625142643375935.43950335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-792281625142643375935.43950335", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("792281625142643375935.43950335", result2);
}
END_TEST

START_TEST(negate_51) {
  char *etalon = "7922816251426433759354395.0335";
  char *etalon_b = "-7922816251426433759354395.0335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-7922816251426433759354395.0335", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("7922816251426433759354395.0335", result2);
}
END_TEST

START_TEST(negate_52) {
  char *etalon = "7922816251426433759354395033.5";
  char *etalon_b = "-7922816251426433759354395033.5";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-7922816251426433759354395033.5", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("7922816251426433759354395033.5", result2);
}
END_TEST

START_TEST(negate_53) {
  char *etalon = "0.0028162514264337593543950335";
  char *etalon_b = "-0.0028162514264337593543950335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-0.0028162514264337593543950335", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("0.0028162514264337593543950335", result2);
}
END_TEST

START_TEST(negate_54) {
  char *etalon = "0.0000000514264337593543950335";
  char *etalon_b = "-0.0000000514264337593543950335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-0.0000000514264337593543950335", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("0.0000000514264337593543950335", result2);
}
END_TEST

START_TEST(negate_55) {
  char *etalon = "0.0000000000264337593543950335";
  char *etalon_b = "-0.0000000000264337593543950335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-0.0000000000264337593543950335", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("0.0000000000264337593543950335", result2);
}
END_TEST

START_TEST(negate_56) {
  char *etalon = "0.0000000000004337593543950335";
  char *etalon_b = "-0.0000000000004337593543950335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-0.0000000000004337593543950335", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("0.0000000000004337593543950335", result2);
}
END_TEST

START_TEST(negate_57) {
  char *etalon = "0.0000000000000000000000950335";
  char *etalon_b = "-0.0000000000000000000000950335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-0.0000000000000000000000950335", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("0.0000000000000000000000950335", result2);
}
END_TEST

START_TEST(negate_58) {
  char *etalon = "0.0000000000000000000000000005";
  char *etalon_b = "-0.0000000000000000000000000005";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-0.0000000000000000000000000005", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("0.0000000000000000000000000005", result2);
}
END_TEST

START_TEST(negate_59) {
  char *etalon = "0.0000000000000000000000000001";
  char *etalon_b = "-0.0000000000000000000000000001";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-0.0000000000000000000000000001", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("0.0000000000000000000000000001", result2);
}
END_TEST

START_TEST(negate_60) {
  char *etalon = "0.0000000000000001";
  char *etalon_b = "-0.0000000000000001";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(etalon);
  number2 = char_to_decimal(etalon_b);
  s21_negate(number1, &number1);
  s21_negate(number2, &number2);
  char result[BUF] = {'\0'};
  dec_to_string(&number1, result);
  ck_assert_str_eq("-0.0000000000000001", result);
  char result2[BUF] = {'\0'};
  dec_to_string(&number2, result2);
  ck_assert_str_eq("0.0000000000000001", result2);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_add;

  s = suite_create("Negate");

  tc_add = tcase_create("Negate");
  tcase_add_test(tc_add, negate_1);
  tcase_add_test(tc_add, negate_2);
  tcase_add_test(tc_add, negate_3);
  tcase_add_test(tc_add, negate_4);
  tcase_add_test(tc_add, negate_5);
  tcase_add_test(tc_add, negate_6);
  tcase_add_test(tc_add, negate_7);
  tcase_add_test(tc_add, negate_8);
  tcase_add_test(tc_add, negate_9);
  tcase_add_test(tc_add, negate_10);
  tcase_add_test(tc_add, negate_11);
  tcase_add_test(tc_add, negate_12);
  tcase_add_test(tc_add, negate_13);
  tcase_add_test(tc_add, negate_14);
  tcase_add_test(tc_add, negate_15);
  tcase_add_test(tc_add, negate_16);
  tcase_add_test(tc_add, negate_17);
  tcase_add_test(tc_add, negate_18);
  tcase_add_test(tc_add, negate_19);
  tcase_add_test(tc_add, negate_20);
  tcase_add_test(tc_add, negate_21);
  tcase_add_test(tc_add, negate_22);
  tcase_add_test(tc_add, negate_23);
  tcase_add_test(tc_add, negate_24);
  tcase_add_test(tc_add, negate_25);
  tcase_add_test(tc_add, negate_26);
  tcase_add_test(tc_add, negate_27);
  tcase_add_test(tc_add, negate_28);
  tcase_add_test(tc_add, negate_29);
  tcase_add_test(tc_add, negate_30);
  tcase_add_test(tc_add, negate_31);
  tcase_add_test(tc_add, negate_32);
  tcase_add_test(tc_add, negate_33);
  tcase_add_test(tc_add, negate_34);
  tcase_add_test(tc_add, negate_35);
  tcase_add_test(tc_add, negate_36);
  tcase_add_test(tc_add, negate_37);
  tcase_add_test(tc_add, negate_38);
  tcase_add_test(tc_add, negate_39);
  tcase_add_test(tc_add, negate_40);
  tcase_add_test(tc_add, negate_41);
  tcase_add_test(tc_add, negate_42);
  tcase_add_test(tc_add, negate_43);
  tcase_add_test(tc_add, negate_44);
  tcase_add_test(tc_add, negate_45);
  tcase_add_test(tc_add, negate_46);
  tcase_add_test(tc_add, negate_47);
  tcase_add_test(tc_add, negate_48);
  tcase_add_test(tc_add, negate_49);
  tcase_add_test(tc_add, negate_50);
  tcase_add_test(tc_add, negate_51);
  tcase_add_test(tc_add, negate_52);
  tcase_add_test(tc_add, negate_53);
  tcase_add_test(tc_add, negate_54);
  tcase_add_test(tc_add, negate_55);
  tcase_add_test(tc_add, negate_56);
  tcase_add_test(tc_add, negate_57);
  tcase_add_test(tc_add, negate_58);
  tcase_add_test(tc_add, negate_59);
  tcase_add_test(tc_add, negate_60);
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
