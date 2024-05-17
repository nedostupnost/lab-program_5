#include "forus.h"
int main() {
    char* path = input();
    if (check(path) == 0) {
        char* result = process(path);
        output(result);
    } else {
        printf("Ошибка в введенном пути\n");
    }
    return 0;
}



// delim: +
// paths: C:\Windows\system32+E:\Distrib\msoffice.exe+/home/vadim/prog/lab5.c