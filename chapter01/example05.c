#include <stdio.h>

int main()
{
    int number;
    printf("please input a number: \n");
    scanf_s("%d", &number);
    if(prime(number))
        printf("\n%d is prime !", number);
    else
        printf("\n%d not is prime !", number);

    return 0;
}

int prime(int number)
{
    int flag = 1, n;
    for(n = 2; n < number/2 && flag == 1; ++n)
        if(number % n == 0)
            flag = 0;
    return flag;
}






