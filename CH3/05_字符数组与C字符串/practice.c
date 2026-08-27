#include <stdio.h>

int main(void)
{
    char grade = 'A';
    char word[] = "Bootdev";
    char message[32] = "C arrays";

    printf("grade = %c\n", grade);
    printf("word = %s\n", word);
    printf("message = %s\n", message);

    for (size_t i = 0; word[i] != '\0'; i++) {
        printf("word[%zu] = %c\n", i, word[i]);
    }

    return 0;
}

