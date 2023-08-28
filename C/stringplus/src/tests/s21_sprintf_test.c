#include "../header.h"
// ТЕСТЫ СО СПЕЦИФИКАТОРОМ D

START_TEST(test_sprintf1) {
    // Копируем обычный int
    int d = -12345;
    int res1 = 0;
    int res2 = 0;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "%d tr";
    res1 = s21_sprintf(dest1, src1, d);
    res2 = sprintf(dest2, src1, d);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf1_1) {
    // Копируем int со спецификатором h
    int d = -123456547;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "%hd tr";
    int res1 = s21_sprintf(dest1, src1, d);
    int res2 = sprintf(dest2, src1, d);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf1_2) {
    // Копируем int со спецификатором h, int и несколько % подряд
    int d = -123456547;
    int s = 98765;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "%hd center %%  %d end";
    int res1 = s21_sprintf(dest1, src1, d, s);
    int res2 = sprintf(dest2, src1, d, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf1_3) {
    // Копируем int со спецификатором l, int и несколько % подряд
    int d = -123456547;
    int s = 98765;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "%hd center %%  %ld end";
    int res1 = s21_sprintf(dest1, src1, d, s);
    int res2 = sprintf(dest2, src1, d, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf1_4) {
    // Тестирование флагов +, -, ' ' с несколькими ++
    int s = 98765;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "Without +: %d\nWith plus: %+++d end";
    int res1 = s21_sprintf(dest1, src1, s, s);
    int res2 = sprintf(dest2, src1, s, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf1_5) {
    // Тестирование флагов +, -, ' ' с несколькими ++
    int s = 123456789;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "With many signs: %-++d";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf1_6) {
    // Тестирование флагa ' '
    int s = -123456789;
    char dest1[1024] = "***********************************************";
    char dest2[1024] = "***********************************************";
    char src1[50] = "With space and accuracy: % .12d";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf1_7) {
    // Тестирование флагa ' '
    int s = 123456789;
    char dest1[1024] = "***********************************************";
    char dest2[1024] = "***********************************************";
    char src1[50] = "With space and accuracy: % .12d";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf1_8) {
    // Тестирование отступа пробелами справа
    int s = 123456789;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "With width int: %-22d";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf1_9) {
    // Тестирование отступа пробелами слева
    int s = 123456789;
    char dest1[1024] = "*********************************************";
    char dest2[1024] = "*********************************************";
    char src1[50] = "With width int: %22d";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf1_10) {
    // Тестирование точности для int
    int s = 123456789;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "Accuracy for int: %.12d";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf1_11) {
    // Тестирование точности для int
    int s = 123456789;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "Accuracy for int: %.3d";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf1_12) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%.2d|\n", -1);
    sprintf(data1, "02) standart PRINTF : |%.2d|\n", -1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(test_sprintf1_13) {
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "%10.5ld";
    int res1 = s21_sprintf(dest1, src1, LONG_MIN);
    int res2 = sprintf(dest2, src1, LONG_MIN);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

// Tests with flag zero
START_TEST(test_sprintf1_14) {
    int d = -1234556;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "Test with int and zero: %0d";
    int res1 = s21_sprintf(dest1, src1, d);
    int res2 = sprintf(dest2, src1, d);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf1_15) {
    int d = -1234556;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "Test with int and zero: % 007.3d";
    int res1 = s21_sprintf(dest1, src1, d);
    int res2 = sprintf(dest2, src1, d);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

// ТЕСТЫ СО СПЕЦИФИКАТОРОМ F

START_TEST(test_sprintf2) {
    // Копируем обычный float
    float d = -12345.128;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "%f";
    int res1 = s21_sprintf(dest1, src1, d);
    int res2 = sprintf(dest2, src1, d);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf2_1) {
    // Копируем обычный float c флагом нулевой точности
    float d = -12345.128;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "%.0f";
    int res1 = s21_sprintf(dest1, src1, d);
    int res2 = sprintf(dest2, src1, d);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST


START_TEST(test_sprintf2_2) {
    // Копируем float , int и несколько % подряд
    float d = -12345.128;
    float s = 24.785;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "%f center %%  %f end";
    int res1 = s21_sprintf(dest1, src1, d, s);
    int res2 = sprintf(dest2, src1, d, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf2_3) {
    // Тестирование флагов +, -, ' ' с несколькими ++
    float s = 124.785;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "Without +: %f\nWith plus: %+++f end";
    int res1 = s21_sprintf(dest1, src1, s, s);
    int res2 = sprintf(dest2, src1, s, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf2_4) {
    // Тестирование флагов +, -, ' ' с несколькими ++
    float s = 1234.582;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "With many signs and accuracy: %-++f";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf2_5) {
    // Тестирование отступа пробелами справа
    float s = 12345.6789;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "With width int: %-22f";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf2_6) {
    // Тестирование отступа пробелами слева
    float s = 12345.6789;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "With width int: %22f";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf2_7) {
    // Тестирование точности для float
    float s = 1234.432;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "Accuracy for int: %.12f";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf2_8) {
    // Тестирование точности для float
    float s = 1234.1299;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[150] = "Округление в большую сторону: %.2f";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf2_9) {
    // Тестирование точности для float
    float s = 1234.9999;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[150] = "Округление в большую сторону с заходом на целые: %.1f";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf2_10) {
    // Тестирование точности для float
    float s = 1234.432;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[150] = "Округление без увеличения: % +-10.2f";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf2_11) {
    // Тестирование точности для float
    float s = 1234.432;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[150] = "Округление без увеличения: %.f";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf2_12) {
    char data[100];
    char data1[100];
    double d = 324.343;
    int res1 = s21_sprintf(data, "|%1.15f|\n", d);
    int res2 = sprintf(data1, "|%1.15f|\n", d);
    ck_assert_str_eq(data, data1);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf2_13) {
    char data[100];
    char data1[100];
    double d = 0;
    int res1 = s21_sprintf(data, "|%.f|\n", d);
    int res2 = sprintf(data1, "|%.f|\n", d);
    ck_assert_str_eq(data, data1);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf2_14) {
    double d = 0.001;
    char dest1[100] = "*****************";
    char dest2[100] = "*****************";
    char src1[100] = "|% -5.1f|\n";
    int res1 = s21_sprintf(dest1, src1, d);
    int res2 = sprintf(dest2, src1, d);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST


START_TEST(test_sprintf2_15) {
    char dest1[100] = "*****************";
    char dest2[100] = "*****************";
    char src1[100] = "|% -5hd|\n";
    int res1 = s21_sprintf(dest1, src1, SHRT_MIN);
    int res2 = sprintf(dest2, src1, SHRT_MIN);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf2_16) {
    char data[100];
    char data1[100];
    double d = 24.9;
    int res1 = s21_sprintf(data, "|%.f|\n", d);
    int res2 = sprintf(data1, "|%.f|\n", d);
    ck_assert_str_eq(data, data1);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf2_17) {
    char data[100];
    char data1[100];
    double d = 24.999999;
    int res1 = s21_sprintf(data, "|%.2f|\n", d);
    int res2 = sprintf(data1, "|%.2f|\n", d);
    ck_assert_str_eq(data, data1);
    ck_assert_int_eq(res1, res2);
}
END_TEST

// ТЕСТИРОВАНИЕ С ФЛАГОМ U

START_TEST(test_sprintf3) {
    // Копируем обычный unsigned
    unsigned d = -12345;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "%u tr";
    int res1 = s21_sprintf(dest1, src1, d);
    int res2 = sprintf(dest2, src1, d);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf3_1) {
    // подаём 0
    unsigned d = 0;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "%u tr";
    int res1 = s21_sprintf(dest1, src1, d);
    int res2 = sprintf(dest2, src1, d);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf3_2) {
    // Копируем int со спецификатором h
    unsigned d = -123456547;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "%hu tr";
    int res1 = s21_sprintf(dest1, src1, d);
    int res2 = sprintf(dest2, src1, d);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf3_3) {
    // Копируем int со спецификатором l
    unsigned d = 123456547;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "%lu tr";
    int res1 = s21_sprintf(dest1, src1, d);
    int res2 = sprintf(dest2, src1, d);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf3_4) {
    // Копируем unsigned со спецификатором h, unsigned и несколько % подряд
    unsigned d = -123456547;
    unsigned s = 98765;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "%hu center %%  %u end";
    int res1 = s21_sprintf(dest1, src1, d, s);
    int res2 = sprintf(dest2, src1, d, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf3_5) {
    // Тестирование флагов +, -, ' ' с несколькими ++
    unsigned s = 987638235;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "Without +: %u\nWith plus: %+++u end";
    int res1 = s21_sprintf(dest1, src1, s, s);
    int res2 = sprintf(dest2, src1, s, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf3_6) {
    // Тестирование флагов +, -, ' ' с несколькими ++
    unsigned s = 123456789;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "With many signs: %-++u";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf3_7) {
    // Тестирование флагa ' '
    unsigned s = -123456789;
    char dest1[1024] = "***********************************************";
    char dest2[1024] = "***********************************************";
    char src1[50] = "With space and accuracy: % .12u";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf3_8) {
    // Тестирование флагa ' '
    unsigned s = 123456789;
    char dest1[1024] = "***********************************************";
    char dest2[1024] = "***********************************************";
    char src1[50] = "With space and accuracy: % .12u";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf3_9) {
    // Тестирование отступа пробелами справа
    unsigned s = 123456789;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "With width int: %-22u";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf3_10) {
    // Тестирование отступа пробелами слева
    unsigned s = 123456789;
    char dest1[1024] = "*********************************************";
    char dest2[1024] = "*********************************************";
    char src1[50] = "With width int: %22u";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf3_11) {
    // Тестирование точности для int
    int s = 123456789;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "Accuracy for int: %.12u";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf3_12) {
    char data[100];
    char data1[100];
    unsigned d = 0;
    int res1 = s21_sprintf(data, "02) standart PRINTF : |%.usd|\n", d);
    int res2 = sprintf(data1, "02) standart PRINTF : |%.usd|\n", d);
    ck_assert_str_eq(data, data1);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf3_13) {
  char* s21_test_str = (char*)malloc(sizeof(char) * 256);
  char* lib_test_str = (char*)malloc(sizeof(char) * 256);
  unsigned int u = 2147483647;
  unsigned int a = 0;
  unsigned int b = 102;
  unsigned int c = 12;
  unsigned int d = 120;
  unsigned int e = 1200;
  unsigned int f = 14895085;
  char *s = "|%u| |%u| |%u| |%-20u| |%u| |%5u| |%.20u| |%-20.15u| |%u|\n";
  int lib_res = sprintf(lib_test_str, s, u, a, b, c, f, c, c, c, d, e);
  int s21_res = s21_sprintf(s21_test_str, s, u, a, b, c, f, c, c, c, d, e);
  ck_assert_str_eq(s21_test_str, lib_test_str);
  ck_assert_int_eq(s21_res, lib_res);
  free(s21_test_str);
  free(lib_test_str);
}
END_TEST

START_TEST(test_sprintf3_14) {
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    int c = 12;
    char *s = "|%7d|\n";
  int s21_res = s21_sprintf(dest1, s, c);
  int lib_res = sprintf(dest2, s, c);
  ck_assert_str_eq(dest1, dest2);
  ck_assert_int_eq(s21_res, lib_res);
}
END_TEST

START_TEST(test_sprintf3_15) {
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    int res1 = 0;
    int res2 = 0;
    char *s = "%10.5lu";
    res1 = s21_sprintf(dest1, s, ULLONG_MAX);
    res2 = sprintf(dest2, s, ULLONG_MAX);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf3_16) {
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    int res1 = 0;
    int res2 = 0;
    char *s = "standart PRINTF : |%08u|\n";
    res1 = s21_sprintf(dest1, s, 64);
    res2 = sprintf(dest2, s, 64);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf3_17) {
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    int res1 = 0;
    int res2 = 0;
    char *s = "standart PRINTF : |%03.4u|\n";
    res1 = s21_sprintf(dest1, s, 10);
    res2 = sprintf(dest2, s, 10);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

// ТЕСТЫ СО СПЕЦИФИКАТОРОМ I
START_TEST(test_sprintf4) {
    // Копируем обычный int
    int d = -12345;
    int res1 = 0;
    int res2 = 0;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "%i tr";
    res1 = s21_sprintf(dest1, src1, d);
    res2 = sprintf(dest2, src1, d);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf4_1) {
    // Копируем int со спецификатором h
    int d = -123456547;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "%hi tr";
    int res1 = s21_sprintf(dest1, src1, d);
    int res2 = sprintf(dest2, src1, d);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf4_2) {
    // Копируем int со спецификатором h, int и несколько % подряi
    int d = -123456547;
    int s = 98765;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "%hi center %%  %i end";
    int res1 = s21_sprintf(dest1, src1, d, s);
    int res2 = sprintf(dest2, src1, d, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf4_3) {
    // Тестирование флагов +, -, ' ' с несколькими ++
    int s = 98765;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "Without +: %i\nWith plus: %+++i end";
    int res1 = s21_sprintf(dest1, src1, s, s);
    int res2 = sprintf(dest2, src1, s, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf4_4) {
    // Тестирование флагов +, -, ' ' с несколькими ++
    int s = 123456789;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "With many signs: %-++i";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf4_5) {
    // Тестирование флагa ' '
    int s = -123456789;
    char dest1[1024] = "***********************************************";
    char dest2[1024] = "***********************************************";
    char src1[50] = "With space and accuracy: % .12i";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf4_6) {
    // Тестирование флагa ' '
    int s = 123456789;
    char dest1[1024] = "***********************************************";
    char dest2[1024] = "***********************************************";
    char src1[50] = "With space and accuracy: % .12i";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf4_7) {
    // Тестирование отступа пробелами справа
    int s = 123456789;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "With width int: %-22i";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf4_8) {
    // Тестирование отступа пробелами слева
    int s = 123456789;
    char dest1[1024] = "*********************************************";
    char dest2[1024] = "*********************************************";
    char src1[50] = "With width int: %22i";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf4_9) {
    // Тестирование точности для int
    int s = 123456789;
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "Accuracy for int: %.12i";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf4_10) {
    // Тестирование точности для int
    // Точность меньше размера int
    int s = 123456789;
    char dest1[1024] = "************************";
    char dest2[1024] = "************************";
    char src1[50] = "Accuracy for int: %.2i";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf4_11) {
    // Тестирование точности для int с флагами отступа и знаком +
    int s = 123456789;
    char dest1[1024] = "************************";
    char dest2[1024] = "************************";
    char src1[50] = "Accuracy for int: %+-22.2hi";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf4_12) {
    // Тестирование точности для int с флагами отступа и знаком u
    int s = 0x5A3;
    char dest1[1024] = "************************";
    char dest2[1024] = "************************";
    char src1[50] = "16form for int: %i";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

// ТЕСТЫ СО СПЕЦИФИКАТОРОМ C

START_TEST(test_sprintf5) {
    char dest1[1024];
    char dest2[1024];
    char *src1 = "%c";
    char c = '{';
    int res1 = s21_sprintf(dest1, src1, c);
    int res2 = sprintf(dest2, src1, c);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf5_1) {
    char dest1[1024];
    char dest2[1024];
    char *src1 = "MESSAGE: %c :MESSAGE: %-30s";
    char *s = "little string";
    char c = '{';
    int res1 = s21_sprintf(dest1, src1, c, s);
    int res2 = sprintf(dest2, src1, c, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf5_2) {
    char dest1[1024];
    char dest2[1024];
    char *src1 = "MESSAGE: %-7c :MESSAGE: %7c";
    char c = '{';
    char d = '+';
    int res1 = s21_sprintf(dest1, src1, c, d);
    int res2 = sprintf(dest2, src1, c, d);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf5_3) {
    // пустой символ
    char c = '\0';
    char dest1[1024] = "************************";
    char dest2[1024] = "************************";
    char src1[50] = "%c";
    int res1 = s21_sprintf(dest1, src1, c);
    int res2 = sprintf(dest2, src1, c);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf5_4) {
    // символ \n
    char c = '\n';
    char dest1[1024] = "************************";
    char dest2[1024] = "************************";
    char src1[50] = "%c";
    int res1 = s21_sprintf(dest1, src1, c);
    int res2 = sprintf(dest2, src1, c);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf5_5) {
    // пустой символ с шириной 5
    char c = '\0';
    char dest1[100] = "************************";
    char dest2[100] = "************************";
    char src1[100] = "пустой символ с точностью 5: |%5c|\n";
    int res1 = s21_sprintf(dest1, src1, c);
    int res2 = sprintf(dest2, src1, c);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf5_6) {
    // пустой символ с точностью
    char c = '\0';
    int d = 12345;
    char dest1[150] = "************************";
    char dest2[150] = "************************";
    char src1[100] = "пустой символ с точностью 5 и число: |%5c| |%d|\n";
    int res1 = s21_sprintf(dest1, src1, c, d);
    int res2 = sprintf(dest2, src1, c, d);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf5_7) {
    // пустой символ с шириной 0
    char c = '\0';
    char dest1[100] = "************************";
    char dest2[100] = "************************";
    char src1[100] = "пустой символ с точностью 5: |%0c|\n";
    int res1 = s21_sprintf(dest1, src1, c);
    int res2 = sprintf(dest2, src1, c);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

// ТЕСТЫ СО СПЕЦИФИКАТОРОМ S

START_TEST(test_sprintf6) {
    char dest1[1024];
    char dest2[1024];
    char *src1 = "Just a little sentence";
    int res1 = s21_sprintf(dest1, "%s", src1);
    int res2 = sprintf(dest2, "%s", src1);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf6_1) {
    char dest1[1024];
    char dest2[1024];
    char *src1 = "MESSAGE: %s :MESSAGE";
    char *s = "little string";
    int res1 = s21_sprintf(dest1, src1, s);
    int res2 = sprintf(dest2, src1, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf6_2) {
    char dest1[1024];
    char dest2[1024];
    char *src1 = "MESSAGE: %s :MESSAGE: %s";
    char *s = "little string";
    int res1 = s21_sprintf(dest1, src1, s, s);
    int res2 = sprintf(dest2, src1, s, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf6_3) {
    char dest1[1024];
    char dest2[1024];
    char *src1 = "MESSAGE: %-30s :MESSAGE: %30s";
    char *s = "little string";
    int res1 = s21_sprintf(dest1, src1, s, s);
    int res2 = sprintf(dest2, src1, s, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf6_4) {
    // Тестирование отстутвия спецификаторов при наличии процента
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src1[50] = "Accuracy for int: %    ";
    int res1 = s21_sprintf(dest1, "%s", src1);
    int res2 = sprintf(dest2, "%s", src1);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf6_5) {
    // Тестирование отстутвия спецификаторов при наличии процента
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src[50] = "%8ыыы text";
    int res1 = s21_sprintf(dest1, "%s", src);
    int res2 = sprintf(dest2, "%s", src);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf6_6) {
    char dest1[100] = "*****************";
    char dest2[100] = "*****************";
    int res1 = s21_sprintf(dest1, "|%.3s|\n", "hello");
    int res2 = sprintf(dest2, "|%.3s|\n", "hello");
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf6_7) {
    char dest1[100] = "*****************";
    char dest2[100] = "*****************";
    char s1[20] = "MneEEEEEEEEE";
    char s[100] = "|%.3s| kushat nado |%20s|\n";
    int res1 = s21_sprintf(dest1, s, s1, "arbuz");
    int res2 = sprintf(dest2, s, s1, "arbuz");
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf6_8) {
    char dest1[100] = "*****************";
    char dest2[100] = "*****************";
    char s1[20] = "MneEEEEEEEEE";
    char s[100] = "|%.3s| kushat nado |%.20s|\n";
    int res1 = s21_sprintf(dest1, s, s1, "arbuz");
    int res2 = sprintf(dest2, s, s1, "arbuz");
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf6_9) {
    char dest1[100] = "*****************";
    char dest2[100] = "*****************";
    char s1[20] = "MneEEEEEEEEE";
    char s[100] = "|%.3s| kushat nado |%.0s|\n";
    int res1 = s21_sprintf(dest1, s, s1, "arbuz");
    int res2 = sprintf(dest2, s, s1, "arbuz");
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf6_10) {
    char dest1[100] = "*****************";
    char dest2[100] = "*****************";
    char s1[20] = "-MneEEEEEEEEE";
    char s[100] = "|%.3s| kushat nado |%.0s|\n";
    int res1 = s21_sprintf(dest1, s, s1, "arbuz");
    int res2 = sprintf(dest2, s, s1, "arbuz");
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf6_11) {
    char dest1[100] = "*****************";
    char dest2[100] = "*****************";
    char s1[20] = " -MneEEEEEEEEE";
    char s[100] = "|%.3s| kushat nado |%.0s|\n";
    int res1 = s21_sprintf(dest1, s, s1, " arbuz");
    int res2 = sprintf(dest2, s, s1, " arbuz");
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf6_12) {
    char data[100];
    char data1[100];
    char s[100] = "01)SPRINTF : |%.4s|\n";
    int res1 = s21_sprintf(data, s, "precision");
    int res2 = sprintf(data1, s, "precision");
    ck_assert_str_eq(data, data1);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf6_13) {
    char data[100];
    char data1[100];
    char s[100] = "01)SPRINTF : |%.0s|\n";
    int res1 = s21_sprintf(data, s, "precision");
    int res2 = sprintf(data1, s, "precision");
    ck_assert_str_eq(data, data1);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf6_14) {
    char data[100];
    char data1[100];
    char s[100] = "01)SPRINTF : |%-.2s|\n";
    int res1 = s21_sprintf(data, s, "precision");
    int res2 = sprintf(data1, s, "precision");
    ck_assert_str_eq(data, data1);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf6_15) {
    char dest1[100];
    char dest2[100];
    char s[100] = "01)SPRINTF : |%10.2s|\n";
    int res1 = s21_sprintf(dest1, s, "precision");
    int res2 = sprintf(dest2, s, "precision");
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf7_1) {
    // Пустой символ
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src[50] = "\0";
    int res1 = s21_sprintf(dest1, "%s", src);
    int res2 = sprintf(dest2, "%s", src);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf7_2) {
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    char src[50] = "Здесь будет %5 отступ %s";
    char s[10] = "end";
    int res1 = s21_sprintf(dest1, src, s);
    int res2 = sprintf(dest2, src, s);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST



START_TEST(test_sprintf7_3) {
    char dest1[1024] = "*****************";
    char dest2[1024] = "*****************";
    short i = 0;
    short a = 32767;
    char src[50] = "|%hi| |%hd|  |%hu|";
    int res1 = s21_sprintf(dest1, src, i, a, i);
    int res2 = sprintf(dest2, src, i, a, i);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf7_4) {
    char dest1[1024] = "**********************************";
    char dest2[1024] = "**********************************";
    char src[150] = "%%|% 5c|% 8.4d|% 9.2d|% 3.7i|% 3.8i|% 9.5f|%+d|% 10s|% 4.2u\n";
    int res1 = s21_sprintf(dest1, src, 'A', 0, -0, -0, 0, -0.0, -0, "STRING", 0);
    int res2 = sprintf(dest2, src, 'A', 0, -0, -0, 0, -0.0, -0, "STRING", 0);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf7_5) {
    char dest1[1024] = "**********************************";
    char dest2[1024] = "**********************************";
    char src[150] = "% 9.5f|\n";
    int res1 = s21_sprintf(dest1, src, -0.0);
    int res2 = sprintf(dest2, src, -0.0);
    ck_assert_str_eq(dest1, dest2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

// Тесты на широкие строки

START_TEST(test_sprintf8_1) {
    char data[1024];
    char data1[1024];
    wchar_t buf[100] = L"hello";
    int a = s21_sprintf(data, "%ls", buf);
    int b = sprintf(data1, "%ls", buf);
    ck_assert_str_eq(data, data1);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_sprintf8_2) {
    char str1[1024];
    char str2[1024];
    char *format = "This is a simple wide char %ls and more char";
    wchar_t w[] = L"TEST STRING";
    int a = s21_sprintf(str1, format, w);
    int b = sprintf(str2, format, w);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_sprintf8_3) {
    char str1[1024];
    char str2[1024];
    char *format = "This is a simple wide char %30ls and more char";
    wchar_t w[] = L"TEST STRING";
    int a = s21_sprintf(str1, format, w);
    int b = sprintf(str2, format, w);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_sprintf8_4) {
    char str1[1024];
    char str2[1024];
    char *format = "This is a simple wide char %30.3ls and more char";
    wchar_t w[] = L"TEST STRING";
    int a = s21_sprintf(str1, format, w);
    int b = sprintf(str2, format, w);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_sprintf8_5) {
    char str1[1024];
    char str2[1024];
    char *format = "This is a simple wide char %-30.3ls and more char";
    wchar_t w[] = L"TEST STRING";
    int a = s21_sprintf(str1, format, w);
    int b = sprintf(str2, format, w);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_sprintf8_6) {
    char str1[1024];
    char str2[1024];
    char *format = "This is a %ls simple wide char %-30.3ls and more char";
    wchar_t w[] = L"TEST STRING";
    int a = s21_sprintf(str1, format, w, w);
    int b = sprintf(str2, format, w, w);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(a, b);
}
END_TEST

// Тесты на широкие символы С

START_TEST(test_sprintf9_1) {
    char str1[1024];
    char str2[1024];
    wchar_t w = L'X';
    char *format = "This is a simple wide char %lc";
    int a = s21_sprintf(str1, format, w);
    int b = sprintf(str2, format, w);
#if defined __linux__
    ck_assert_str_eq(str1, str2);
#endif
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_sprintf9_2) {
    char str1[1024];
    char str2[1024];
    char *format = "This is a simple wide char %-5lc";
    wchar_t w = L'X';
    int a = s21_sprintf(str1, format, w);
    int b = sprintf(str2, format, w);
#if defined __linux__
    ck_assert_str_eq(str1, str2);
#endif
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_sprintf9_3) {
    char str1[1024];
    char str2[1024];
    char *format = "This is a simple %lc, %5lc, %-5lc and other char";
    wchar_t w = L'X';
    int a = s21_sprintf(str1, format, w, w, w);
    int b = sprintf(str2, format, w, w, w);
#if defined __linux__
    ck_assert_str_eq(str1, str2);
#endif
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_sprintf9_4) {
    char str1[1024];
    char str2[1024];
    char *format = "Wide char %lc, %5lc, %-5lc and wide string %ls, %30.5ls, %-30.5ls";
    wchar_t w = L'X';
    wchar_t y[] = L"TEST STRING";
    int a = s21_sprintf(str1, format, w, w, w, y, y, y);
    int b = sprintf(str2, format, w, w, w, y, y, y);
#if defined __linux__
    ck_assert_str_eq(str1, str2);
#endif
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_sprintf9_5) {
    char str1[1024];
    char str2[1024];
    wchar_t w = L'\0';
    char *format = "This is a simple wide char %lc";
    int a = s21_sprintf(str1, format, w);
    int b = sprintf(str2, format, w);
#if defined __linux__
    ck_assert_str_eq(str1, str2);
#endif
    ck_assert_int_eq(a, b);
}
END_TEST

Suite * sprintf_test(void) {
    Suite *s;
    TCase *tc_sprintf1, *tc_sprintf2, *tc_sprintf3, *tc_sprintf4,
          *tc_sprintf5, *tc_sprintf6, *tc_sprintf7, *tc_sprintf8,
          *tc_sprintf9;

    s = suite_create("s21_printf");

    tc_sprintf1 = tcase_create("Specificator 'd'");
    tcase_add_test(tc_sprintf1, test_sprintf1);
    tcase_add_test(tc_sprintf1, test_sprintf1_1);
    tcase_add_test(tc_sprintf1, test_sprintf1_2);
    tcase_add_test(tc_sprintf1, test_sprintf1_3);
    tcase_add_test(tc_sprintf1, test_sprintf1_4);
    tcase_add_test(tc_sprintf1, test_sprintf1_5);
    tcase_add_test(tc_sprintf1, test_sprintf1_6);
    tcase_add_test(tc_sprintf1, test_sprintf1_7);
    tcase_add_test(tc_sprintf1, test_sprintf1_8);
    tcase_add_test(tc_sprintf1, test_sprintf1_9);
    tcase_add_test(tc_sprintf1, test_sprintf1_10);
    tcase_add_test(tc_sprintf1, test_sprintf1_11);
    tcase_add_test(tc_sprintf1, test_sprintf1_12);
    tcase_add_test(tc_sprintf1, test_sprintf1_13);
    tcase_add_test(tc_sprintf1, test_sprintf1_14);
    tcase_add_test(tc_sprintf1, test_sprintf1_15);
    suite_add_tcase(s, tc_sprintf1);

    tc_sprintf2 = tcase_create("Specificator 'f'");
    tcase_add_test(tc_sprintf2, test_sprintf2);
    tcase_add_test(tc_sprintf2, test_sprintf2_1);
    tcase_add_test(tc_sprintf2, test_sprintf2_2);
    tcase_add_test(tc_sprintf2, test_sprintf2_3);
    tcase_add_test(tc_sprintf2, test_sprintf2_4);
    tcase_add_test(tc_sprintf2, test_sprintf2_5);
    tcase_add_test(tc_sprintf2, test_sprintf2_6);
    tcase_add_test(tc_sprintf2, test_sprintf2_7);
    tcase_add_test(tc_sprintf2, test_sprintf2_8);
    tcase_add_test(tc_sprintf2, test_sprintf2_9);
    tcase_add_test(tc_sprintf2, test_sprintf2_10);
    tcase_add_test(tc_sprintf2, test_sprintf2_11);
    tcase_add_test(tc_sprintf2, test_sprintf2_12);
    tcase_add_test(tc_sprintf2, test_sprintf2_13);
    tcase_add_test(tc_sprintf2, test_sprintf2_14);
    tcase_add_test(tc_sprintf2, test_sprintf2_15);
    tcase_add_test(tc_sprintf2, test_sprintf2_16);
    tcase_add_test(tc_sprintf2, test_sprintf2_17);
    suite_add_tcase(s, tc_sprintf2);

    tc_sprintf3 = tcase_create("Specificator 'u'");
    tcase_add_test(tc_sprintf3, test_sprintf3);
    tcase_add_test(tc_sprintf3, test_sprintf3_1);
    tcase_add_test(tc_sprintf3, test_sprintf3_2);
    tcase_add_test(tc_sprintf3, test_sprintf3_3);
    tcase_add_test(tc_sprintf3, test_sprintf3_4);
    tcase_add_test(tc_sprintf3, test_sprintf3_5);
    tcase_add_test(tc_sprintf3, test_sprintf3_6);
    tcase_add_test(tc_sprintf3, test_sprintf3_7);
    tcase_add_test(tc_sprintf3, test_sprintf3_8);
    tcase_add_test(tc_sprintf3, test_sprintf3_9);
    tcase_add_test(tc_sprintf3, test_sprintf3_10);
    tcase_add_test(tc_sprintf3, test_sprintf3_11);
    tcase_add_test(tc_sprintf3, test_sprintf3_12);
    tcase_add_test(tc_sprintf3, test_sprintf3_13);
    tcase_add_test(tc_sprintf3, test_sprintf3_14);
    tcase_add_test(tc_sprintf3, test_sprintf3_15);
    tcase_add_test(tc_sprintf3, test_sprintf3_16);
    tcase_add_test(tc_sprintf3, test_sprintf3_17);
    suite_add_tcase(s, tc_sprintf3);

    tc_sprintf4 = tcase_create("Specificator 'i'");
    tcase_add_test(tc_sprintf4, test_sprintf4);
    tcase_add_test(tc_sprintf4, test_sprintf4_1);
    tcase_add_test(tc_sprintf4, test_sprintf4_2);
    tcase_add_test(tc_sprintf4, test_sprintf4_3);
    tcase_add_test(tc_sprintf4, test_sprintf4_4);
    tcase_add_test(tc_sprintf4, test_sprintf4_5);
    tcase_add_test(tc_sprintf4, test_sprintf4_6);
    tcase_add_test(tc_sprintf4, test_sprintf4_7);
    tcase_add_test(tc_sprintf4, test_sprintf4_8);
    tcase_add_test(tc_sprintf4, test_sprintf4_9);
    tcase_add_test(tc_sprintf4, test_sprintf4_10);
    tcase_add_test(tc_sprintf4, test_sprintf4_11);
    tcase_add_test(tc_sprintf4, test_sprintf4_12);
    suite_add_tcase(s, tc_sprintf4);

    tc_sprintf5 = tcase_create("Specificator 'c'");
    tcase_add_test(tc_sprintf5, test_sprintf5);
    tcase_add_test(tc_sprintf5, test_sprintf5_1);
    tcase_add_test(tc_sprintf5, test_sprintf5_2);
    tcase_add_test(tc_sprintf5, test_sprintf5_3);
    tcase_add_test(tc_sprintf5, test_sprintf5_4);
    tcase_add_test(tc_sprintf5, test_sprintf5_5);
    tcase_add_test(tc_sprintf5, test_sprintf5_6);
    tcase_add_test(tc_sprintf5, test_sprintf5_7);
    suite_add_tcase(s, tc_sprintf5);

    tc_sprintf6 = tcase_create("Specificator 's'");
    tcase_add_test(tc_sprintf6, test_sprintf6);
    tcase_add_test(tc_sprintf6, test_sprintf6_1);
    tcase_add_test(tc_sprintf6, test_sprintf6_2);
    tcase_add_test(tc_sprintf6, test_sprintf6_3);
    tcase_add_test(tc_sprintf6, test_sprintf6_4);
    tcase_add_test(tc_sprintf6, test_sprintf6_5);
    tcase_add_test(tc_sprintf6, test_sprintf6_6);
    tcase_add_test(tc_sprintf6, test_sprintf6_7);
    tcase_add_test(tc_sprintf6, test_sprintf6_8);
    tcase_add_test(tc_sprintf6, test_sprintf6_9);
    tcase_add_test(tc_sprintf6, test_sprintf6_10);
    tcase_add_test(tc_sprintf6, test_sprintf6_11);
    tcase_add_test(tc_sprintf6, test_sprintf6_12);
    tcase_add_test(tc_sprintf6, test_sprintf6_13);
    tcase_add_test(tc_sprintf6, test_sprintf6_14);
    tcase_add_test(tc_sprintf6, test_sprintf6_15);
    suite_add_tcase(s, tc_sprintf6);

    tc_sprintf7 = tcase_create("Without specificator or mixed");
    tcase_add_test(tc_sprintf7, test_sprintf7_1);
    tcase_add_test(tc_sprintf7, test_sprintf7_2);
    tcase_add_test(tc_sprintf7, test_sprintf7_3);
    tcase_add_test(tc_sprintf7, test_sprintf7_4);
    tcase_add_test(tc_sprintf7, test_sprintf7_5);
    suite_add_tcase(s, tc_sprintf7);

    tc_sprintf8 = tcase_create("With wide string aka wchar_t");
    tcase_add_test(tc_sprintf8, test_sprintf8_1);
    tcase_add_test(tc_sprintf8, test_sprintf8_2);
    tcase_add_test(tc_sprintf8, test_sprintf8_3);
    tcase_add_test(tc_sprintf8, test_sprintf8_4);
    tcase_add_test(tc_sprintf8, test_sprintf8_5);
    tcase_add_test(tc_sprintf8, test_sprintf8_6);
    suite_add_tcase(s, tc_sprintf8);

    tc_sprintf9 = tcase_create("With wide char aka wchar_t");
    tcase_add_test(tc_sprintf9, test_sprintf9_1);
    tcase_add_test(tc_sprintf9, test_sprintf9_2);
    tcase_add_test(tc_sprintf9, test_sprintf9_3);
    tcase_add_test(tc_sprintf9, test_sprintf9_4);
    tcase_add_test(tc_sprintf9, test_sprintf9_5);
    suite_add_tcase(s, tc_sprintf9);

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
