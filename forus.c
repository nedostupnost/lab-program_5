#include "forus.h"

// ввод //
char* input() {
    static char buffer[1024];
    printf("Введите пути, разделенные '+': ");
    scanf("%1023s", buffer);
    return buffer;
}

// проверка на длинну строки и корректность символов //
int check(const char *path) {
    if (slen(path) > 1023) return 1;
    if (sspn(path, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789:/\\+_.") != -1) return 2;
    return 0;
}

// преобразование путей //
char* process(const char *path) {
    static char new_path[2048];
    char *token = stok(path, '+');
    char temp[1024], *p;

    new_path[0] = '\0';
    while (token) {
        if (slen(token) > 2 && token[1] == ':' && (token[2] == '\\' || token[2] == '/')) {
            // Определяем букву диска и переводим её в нижний регистр
            char drive = token[0];
            if (drive >= 'A' && drive <= 'Z') {
                drive = drive - 'A' + 'a'; // Преобразование в нижний регистр
            }
            
            scpy(temp, "/cygdrive/");
            temp[10] = drive; // Копирование диска в нижнем регистре
            temp[11] = '\0';
            scat(temp, "/");
            scat(temp, token + 3);
            for (p = temp + 12; *p; p++) {
                if (*p == '\\') *p = '/'; // Замена обратных слешей на прямые
            }
            
            if (slen(new_path) + slen(temp) + 1 < sizeof(new_path)) {
                if (new_path[0] != '\0') scat(new_path, "+");
                scat(new_path, temp);
            }
        } else {
            if (new_path[0] != '\0') scat(new_path, "+");
            scat(new_path, token);
        }
        token = stok(NULL, '+');
    }

    return new_path;
}

// ввывод //
void output(const char *result) {
    printf("Преобразованные пути: %s\n", result);
}