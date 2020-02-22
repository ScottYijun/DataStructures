#include <stdio.h>

int main()
{
    char i, j;
    for(i = 1; i < 4; ++i)
    {
        for(j = 1; j <= 2 * i - 1; ++j)
            printf("%c", '*');
        printf("\n");
    }

    for(i = 1; i < 3; ++i)
    {
        for(j = 4; j > 2*i - 1; j--)
            printf("%c", '*');
        printf("\n");
    }


    return 0;
}




