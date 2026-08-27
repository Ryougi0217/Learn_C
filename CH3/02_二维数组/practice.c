#include <stdio.h>

int main(void)
{
    int board[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    size_t rows = sizeof board / sizeof board[0];
    size_t columns = sizeof board[0] / sizeof board[0][0];

    for (size_t row = 0; row < rows; row++) {
        for (size_t column = 0; column < columns; column++) {
            printf("%d ", board[row][column]);
        }
        putchar('\n');
    }

    return 0;
}

