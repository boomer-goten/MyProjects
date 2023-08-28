// Написать bash-скрипт или программу на Си, генерирующий 5 файлов логов nginx в
// combined формате. Каждый лог должен содержать информацию за 1 день. За день
// должно быть сгенерировано случайное число записей от 100 до 1000. Для каждой
// записи должны случайным образом генерироваться:

// IP (любые корректные, т.е. не должно быть ip вида 999.111.777.777)
// Коды ответа (200, 201, 400, 401, 403, 404, 500, 501, 502, 503)
// Методы (GET, POST, PUT, PATCH, DELETE)
// Даты (в рамках заданного дня лога, должны идти по увеличению)
// URL запроса агента
// Агенты (Mozilla, Google Chrome, Opera, Safari, Internet Explorer, Microsoft
// Edge, Crawler and bot, Library and net tool)

// Формат определяется этим выражением:
// "%h %l %u %t \"%r\" %>s %b \"%{Referer}i\" \"%{User-agent}i\""
// "%ip %ident %user \"%date\" %>method_path %code \"%{url}" \"%{User-agent}i\""
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_day(char *tmp);
void get_ip(char *entry_line);
void get_ident(char *entry_line);
void get_user(char *entry_line);
void get_date(char *entry_line, char *tmp, int *hour, int *minutes, int *seconds);
void get_method(char *entry_line);
void get_status_code(char *entry_line);
void get_count_of_bytes(char *entry_line);
void get_url(char *entry_line);
void get_agent(char *entry_line);

int main() {
    for (int i = 1; i < 6; i++) {
        char filename[10] = {'\0'};
        sprintf(filename, "%d", i);
        strcat(filename, ".log");
        FILE *fp = NULL;
        fp = fopen(filename, "w+");
        if (!fp) {
            printf("Файл %s не создался", filename);
        }
        int random_number = (100 + rand()) % 1000;
        char entry_line[1024] = {};
        char tmp[40] = {'\0'};
        get_day(tmp);
        int hour = 0;
        int minutes = 0;
        int seconds = 0;
        for (int j = 0; j < random_number; j++) {
            memset(entry_line, '\0', sizeof(char) * 1024);
            get_ip(entry_line);
            get_ident(entry_line);
            get_user(entry_line);
            get_date(entry_line, tmp, &hour, &minutes, &seconds);
            get_method(entry_line);
            get_status_code(entry_line);
            get_count_of_bytes(entry_line);
            get_url(entry_line);
            get_agent(entry_line);
            fprintf(fp, "%s\n", entry_line);
        }
        fclose(fp);
    }
    return 0;
}

void get_day(char *tmp) {
    int month_digit = rand() % 12;
    char month[12][20] = {"January", "February", "March",     "April",   "May",      "June",
                          "July",    "August",   "September", "October", "November", "December"};
    sprintf(tmp, "[%d/%s/", month_digit + 1, month[month_digit]);
}

void get_ip(char *entry_line) {
    char tmp[30] = {'\0'};
    sprintf(tmp, "%d.%d.%d.%d", rand() % 255, rand() % 255, rand() % 255, rand() % 255);
    strcat(entry_line, tmp);
}

void get_ident(char *entry_line) {
    char tmp[3] = {'\0'};
    sprintf(tmp, "%s", " -");
    strcat(entry_line, tmp);
}

void get_user(char *entry_line) {
    char tmp[4] = {'\0'};
    sprintf(tmp, "%s", " - ");
    strcat(entry_line, tmp);
}

void get_date(char *entry_line, char *tmp, int *hour, int *minutes, int *seconds) {
    char temp[100] = {'\0'};
    sprintf(temp, "%d:%d:%d:%d -%d00] ", 2022, *hour, *minutes, *seconds, rand() % 12);
    strcat(entry_line, tmp);
    strcat(entry_line, temp);
    (*seconds)++;
    if (*seconds == 60) {
        (*minutes)++;
        *seconds = *seconds - 60;
    }
}

void get_method(char *entry_line) {
    char tmp[] = {"/stuff.hmtl HTTP/1.1"};
    char request[5][10] = {"Get", "Post", "Put", "Patch", "Delete"};
    int random_req = rand() % 5;
    char request_str[60] = {'\0'};
    sprintf(request_str, "\"%s", request[random_req]);
    strcat(request_str, tmp);
    strcat(request_str, "\"");
    strcat(entry_line, request_str);
}

//  200-299 good connection
//  400-499 client error
//  500-599 server error
void get_status_code(char *entry_line) {
    char tmp[10] = {'\0'};
    int random_number = rand() % 10;
    char status_codes[10][5] = {"200 ", "201 ", "400 ", "401 ", "403 ",
                                "404 ", "500 ", "501 ", "502 ", "503 "};
    sprintf(tmp, " %s", status_codes[random_number]);
    strcat(entry_line, tmp);
}

void get_count_of_bytes(char *entry_line) {
    char tmp[100] = {'\0'};
    sprintf(tmp, "%d ", rand() % 100 + 1);
    strcat(entry_line, tmp);
}

void get_url(char *entry_line) {
    char tmp[100] = "\"https://boomergo.com/\"";
    strcat(entry_line, tmp);
    strcat(entry_line, " ");
}

void get_agent(char *entry_line) {
    char tmp[10][40] = {"Mozilla",        "Google Chrome", "Opera", "Safari",  "Internet Explorer",
                        "Microsoft Edge", "Crawler",       "bot",   "Library", "net tool"};
    int random_number = rand() % 10;
    strcat(entry_line, "\"");
    strcat(entry_line, tmp[random_number]);
    strcat(entry_line, "\"");
}