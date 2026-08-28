#include <stdio.h>
#include <stddef.h>

typedef enum
{
    RECORD_ACTIVE,
    RECORD_ARCHIVED
} RecordStatus;

typedef struct
{
    int id;
    const char *name;
    int score;
    RecordStatus status;
} Record;

static int add_record(Record records[],
                      size_t *count,
                      size_t capacity,
                      Record record)
{
    if (/* TODO：容量已满 */) {
        return 0;
    }

    /* TODO：保存 record 并增加 count */
    return 1;
}

static Record *find_record(Record records[],
                           size_t count,
                           int id)
{
    for (size_t i = 0; i < count; i++) {
        if (/* TODO：找到匹配 id */) {
            /* TODO：返回当前记录地址 */
        }
    }

    return NULL;
}

static void print_record(const Record *record)
{
    if (record == NULL) {
        return;
    }

    printf("#%d %s score=%d status=%d\n",
           record->id, record->name,
           record->score, record->status);
}

int main(void)
{
    Record records[4];
    size_t count = 0;

    add_record(records, &count, 4,
               (Record){1, "Ada", 98, RECORD_ACTIVE});
    add_record(records, &count, 4,
               (Record){2, "Lin", 87, RECORD_ACTIVE});

    print_record(find_record(records, count, 2));
    return 0;
}

