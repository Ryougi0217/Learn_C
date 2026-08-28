#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *log =
        "INFO start\n"
        "WARN slow\n"
        "ERROR failed\n"
        "INFO stop\n";
    size_t info = 0;
    size_t warn = 0;
    size_t error = 0;
    char line[64];

    const char *cursor = log;
    while (/* TODO：尚未到字符串末尾 */) {
        size_t length = 0;
        while (/* TODO：找到当前行长度 */) {
            length++;
        }

        if (length >= sizeof line) {
            return 1;
        }

        memcpy(line, cursor, length);
        line[length] = '\0';

        if (/* TODO：识别 INFO */) {
            info++;
        } else if (/* TODO：识别 WARN */) {
            warn++;
        } else if (/* TODO：识别 ERROR */) {
            error++;
        }

        cursor += length;
        if (*cursor == '\n') {
            cursor++;
        }
    }

    printf("info=%zu warn=%zu error=%zu\n",
           info, warn, error);
    return 0;
}

