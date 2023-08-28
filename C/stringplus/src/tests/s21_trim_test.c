#include "../header.h"
/* Подается строка в которой нужно стереть звездочку с 2 сторон*/
START_TEST(test_trim1) {
    const char src[20] = "****test****";
    const char trim_chars[20] = "*";
    char example[20] = "test";
    char *d = s21_trim(src, trim_chars);
    ck_assert_str_eq(d, example);
    if (d)
        free(d);
}
END_TEST

/* Подается строка в которой нужно стереть звездочку с 2 сторон*/
START_TEST(test_trim2) {
    const char src[] = "*2*2*2*test*2*2*2*";
    const char trim_chars[] = "2*";
    char example[20] = "test";
    char *d = s21_trim(src, trim_chars);
    ck_assert_str_eq(d, example);
    if (d)
        free(d);
}
END_TEST

/* Подается строка в которой нужно стереть звездочку с правой стороны */
START_TEST(test_trim3) {
    const char src[20] = "2****test****";
    const char trim_chars[20] = "*";
    char example[20] = "2****test";
    char *d = s21_trim(src, trim_chars);
    ck_assert_str_eq(d, example);
    if (d)
        free(d);
}
END_TEST

/* Подается строка в которой нужно стереть звездочку с левой стороны */
START_TEST(test_trim4) {
    const char src[20] = "****test****2";
    const char trim_chars[20] = "*";
    char example[20] = "test****2";
    char *d = s21_trim(src, trim_chars);
    ck_assert_str_eq(d, example);
    if (d)
        free(d);
}
END_TEST

/* Подается строка в которой ничего не сотрется*/
START_TEST(test_trim5) {
    const char src[20] = "2****test****2";
    const char trim_chars[20] = "*";
    char example[20] = "2****test****2";
    char *d = s21_trim(src, trim_chars);
    ck_assert_str_eq(d, example);
    if (d)
        free(d);
}
END_TEST

/* Должны стереться пробелы*/
START_TEST(test_trim6) {
    const char src[20] = " 2****test****2 ";
    const char trim_chars[20] = "";
    char example[20] = "2****test****2";
    char *d = s21_trim(src, trim_chars);
    ck_assert_str_eq(d, example);
    if (d)
        free(d);
}
END_TEST

/* Должны стереться пробелы*/
START_TEST(test_trim7) {
    const char src[20] = " 2****test****2 ";
    const char *trim_chars = s21_NULL;
    char example[20] = "2****test****2";
    char *d = s21_trim(src, trim_chars);
    ck_assert_str_eq(d, example);
    if (d)
        free(d);
}
END_TEST

/* Должны стереться пробелы*/
START_TEST(test_trim8) {
    const char *src = s21_NULL;
    const char *trim_chars = "24";
    char *d = s21_trim(src, trim_chars);
    ck_assert_ptr_eq(d, s21_NULL);
    if (d)
        free(d);
}
END_TEST


// delete in empty string
START_TEST(test_trim9) {
    const char *src = "\0";
    const char *trim_chars = "\0";
    char *d = s21_trim(src, trim_chars);
    ck_assert_str_eq(d, "\0");
    if (d)
        free(d);
}
END_TEST

// delete in empty string
START_TEST(test_trim10) {
    const char *src = "\0";
    const char *trim_chars = "*";
    char *d = s21_trim(src, trim_chars);
    ck_assert_str_eq(d, "\0");
    if (d)
        free(d);
}
END_TEST

// delete in empty string
START_TEST(test_trim11) {
    const char *src = "";
    const char *trim_chars = "\0";
    char *d = s21_trim(src, trim_chars);
    ck_assert_str_eq(d, "\0");
    if (d)
        free(d);
}
END_TEST

/* Должны стереться пробелы*/
START_TEST(test_trim12) {
    const char *src = s21_NULL;
    const char *trim_chars = s21_NULL;
    char *d = s21_trim(src, trim_chars);
    ck_assert_ptr_eq(d, s21_NULL);
    if (d)
        free(d);
}
END_TEST


START_TEST(test_trim14) {
    char str[] = "";
    char trim_ch[] = "";
    char expected[] = "";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(test_trim15) {
    char str[] = "";
    char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
    char expected[] = "";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(test_trim16) {
    char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
    char trim_ch[] = "";
    char expected[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(test_trim17) {
    char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
    char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
    char expected[] = "";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(test_trim18) {
    char str[] = "+!!++Abo+ba++00";
    char trim_ch[] = "+!0-";
    char expected[] = "Abo+ba";
    char *got = (char *)s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(test_trim19) {
    char str[] = "Ab000cd0";
    char trim_ch[] = "003";
    char expected[] = "Ab000cd";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(test_trim20) {
    char str[] = "DoNotTouch";
    char trim_ch[] = "Not";
    char expected[] = "DoNotTouch";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(test_trim21) {
    char str[] = "&* !!sc21 * **";
    char trim_ch[] = "&!* ";
    char expected[] = "sc21";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(test_trim22) {
    char str[] = " Good morning!    ";
    char trim_ch[] = " ";
    char expected[] = "Good morning!";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(test_trim23) {
    char str[] = "        abc         ";
    char trim_ch[] = "";
    char expected[] = "abc";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(test_trim24) {
    char str[] = "        abc         ";
    char *trim_ch = NULL;
    char expected[] = "abc";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST


Suite * string_test(void) {
    Suite *s;
    TCase *tc_trim1, *tc_trim2;
    s = suite_create("String_trim");
    tc_trim1 = tcase_create("Core_trim1");
    tcase_add_test(tc_trim1, test_trim1);
    tcase_add_test(tc_trim1, test_trim2);
    tcase_add_test(tc_trim1, test_trim3);
    tcase_add_test(tc_trim1, test_trim4);
    suite_add_tcase(s, tc_trim1);
    tc_trim2 = tcase_create("Core_trim2");
    tcase_add_test(tc_trim2, test_trim5);
    tcase_add_test(tc_trim2, test_trim6);
    tcase_add_test(tc_trim2, test_trim7);
    tcase_add_test(tc_trim2, test_trim8);
    tcase_add_test(tc_trim2, test_trim9);
    tcase_add_test(tc_trim2, test_trim10);
    tcase_add_test(tc_trim2, test_trim11);
    tcase_add_test(tc_trim2, test_trim12);
    tcase_add_test(tc_trim2, test_trim14);
    tcase_add_test(tc_trim2, test_trim15);
    tcase_add_test(tc_trim2, test_trim16);
    tcase_add_test(tc_trim2, test_trim17);
    tcase_add_test(tc_trim2, test_trim18);
    tcase_add_test(tc_trim2, test_trim19);
    tcase_add_test(tc_trim2, test_trim20);
    tcase_add_test(tc_trim2, test_trim21);
    tcase_add_test(tc_trim2, test_trim22);
    tcase_add_test(tc_trim2, test_trim23);
    tcase_add_test(tc_trim2, test_trim24);
    suite_add_tcase(s, tc_trim2);
    return s;
}

int main() {
    int number_failed;
    Suite *s;
    SRunner *sr;
    s = string_test();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
