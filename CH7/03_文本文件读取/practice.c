#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s FILE\n", argv[0]);
        return 2;
    }

    FILE *file = fopen(argv[1], /* TODO：文本读取模式 */);
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    char line[128];
    size_t number = 0;

    while (/* TODO：用 fgets 成功读取一行 */) {
        number++;
        printf("%zu: %s", number, line);
    }

    if (/* TODO：检查读取错误 */) {
        perror("read");
        fclose(file);
        return 1;
    }

    fclose(file);
    return 0;
}

