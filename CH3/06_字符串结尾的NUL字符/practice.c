#include <stdio.h>

int main(void)
{
    char word[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char prefix[4] = {'C', 'H', '3', '\0'};

    printf("word = %s\n", word);
    printf("prefix = %s\n", prefix);

    for (size_t i = 0; i < sizeof word; i++) {
        printf("word[%zu] numeric value = %u\n",
               i,
               (unsigned int) (unsigned char) word[i]);
    }

    return 0;
}

