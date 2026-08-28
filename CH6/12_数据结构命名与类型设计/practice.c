#include <stdio.h>

typedef enum
{
    /* TODO：声明 active 和 archived */
} RecordStatus;

typedef struct
{
    /* TODO：声明 id、name、score、status */
} Record;

static int valid_record(const Record *record)
{
    if (/* TODO：空指针检查 */) {
        return 0;
    }

    return record->id > 0
        && record->score >= 0
        && record->score <= 100;
}

int main(void)
{
    Record record = /* TODO：初始化一条记录 */;

    printf("valid = %d\n", valid_record(&record));
    return 0;
}

