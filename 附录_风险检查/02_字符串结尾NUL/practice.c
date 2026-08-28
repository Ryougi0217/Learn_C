#include <stdio.h>
#include <string.h>

int main(void)
{
    char word[4] = {'c', 'a', 't', /* TODO：填写字符串结束符 */};

    printf("%s length=%zu\n", word, strlen(word));
    return 0;
}

