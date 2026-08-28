#include "file_scan.h"
#include <stdio.h>
#include <string.h>

long scan_file_size(const char *path)
{
    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        return -1;
    }

    if (/* TODO：移动到文件末尾 */ != 0) {
        fclose(file);
        return -1;
    }

    long size = /* TODO：读取位置 */;
    fclose(file);
    return size;
}

const char *scan_format(const unsigned char *header, size_t count)
{
    if (/* TODO：检测 PDF */) {
        return "PDF";
    }
    return "unknown";
}

