#include "strings.h"

// длинна строки //
int slen(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// сравнение двух строк //
int scmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++, s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

// копирование строки //
void scpy(char *dest, const char *src) {
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}

// конкатенация двух строк //
void scat(char *dest, const char *src) {
    while (*dest) {
        dest++;
    }
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}

// поиск элемента в строке //
int sspn(const char *str, const char *set) {
    const char *s;
    for (int i = 0; str[i]; i++) {
        for (s = set; *s; s++) {
            if (str[i] == *s) break;
        }
        if (!*s) return i; 
    }
    return -1;
}

// разбиение строки на подстроки //
char* stok(char *str, const char delimiter) {
    static char* input = NULL;
    if (str != NULL) input = str;
    if (input == NULL) return NULL;

    char *result = input, *p;
    p = input;
    while (*p != '\0') {
        if (*p == delimiter) {
            *p = '\0';
            input = p + 1;
            return result;
        }
        p++;
    }

    input = NULL;
    return result;
}
