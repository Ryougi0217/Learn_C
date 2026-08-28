#include <stdio.h>

static int copy_file(const char *source_name,
                     const char *target_name)
{
    FILE *source = /* TODO：以 rb 打开 */;
    if (source == NULL) {
        return 0;
    }

    FILE *target = /* TODO：以 wb 打开 */;
    if (target == NULL) {
        fclose(source);
        return 0;
    }

    unsigned char buffer[256];
    size_t count;

    while ((count = /* TODO：从 source 读取 */) > 0) {
        if (/* TODO：把 count 个字节写到 target */ != count) {
            fclose(source);
            fclose(target);
            return 0;
        }
    }

    if (/* TODO：检查 source 读取错误 */) {
        fclose(source);
        fclose(target);
        return 0;
    }

    return /* TODO：成功关闭两个文件 */;
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "usage: %s SOURCE TARGET\n", argv[0]);
        return 2;
    }

    return copy_file(argv[1], argv[2]) ? 0 : 1;
}

