#include <stdio.h>

static int is_valid_score(int score)
{
    /* TODO：接受 0~100 */
}

struct TestCase
{
    const char *name;
    int input;
    int expected;
};

int main(void)
{
    const struct TestCase cases[] = {
        {"zero", 0, 1},
        {"middle", 50, 1},
        {"max", 100, 1},
        {"below", -1, 0},
        {"above", 101, 0}
    };
    size_t count = sizeof cases / sizeof cases[0];
    size_t failures = 0;

    for (size_t i = 0; i < count; i++) {
        int actual = is_valid_score(cases[i].input);
        if (/* TODO：actual 不符合预期 */) {
            printf("FAIL %s expected=%d actual=%d\n",
                   cases[i].name, cases[i].expected, actual);
            failures++;
        }
    }

    return failures == 0 ? 0 : 1;
}

