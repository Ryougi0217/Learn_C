#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

static int hash_file(const char *path, uint64_t *result)
{
    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        return 0;
    }

    uint64_t hash = UINT64_C(14695981039346656037);
    unsigned char buffer[4096];
    size_t count;

    while ((count = /* TODO：分块读取 */) > 0) {
        for (size_t i = 0; i < count; i++) {
            /* TODO：执行 FNV-1a 更新 */
        }
    }

    if (/* TODO：检查读取错误 */) {
        fclose(file);
        return 0;
    }

    fclose(file);
    *result = hash;
    return 1;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 2;
    }

    uint64_t hash;
    if (!hash_file(argv[1], &hash)) {
        return 1;
    }

    printf("fnv1a = %016" PRIx64 "\n", hash);
    return 0;
}

