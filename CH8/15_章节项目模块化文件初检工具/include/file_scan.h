#ifndef FILE_SCAN_H
#define FILE_SCAN_H

#include <stddef.h>

long scan_file_size(const char *path);
const char *scan_format(const unsigned char *header, size_t count);

#endif

