#include <stdio.h>

int main()
{
    int a[10], i, t, *p, *r;
    printf("\nplease input ten number:\n");
    for(i = 0; i < 10; ++i)
    {
        scanf_s("%d", &a[i]);
    }
    printf("ԭ����˳��Ϊ��\n");
    for(i = 0; i < 10; ++i)
    {
        printf("%d  ", a[i]);
    }
    p = &a[0];
    r = &a[9];
    while (p < r)
    {
        t = *p;
        *p = *r;
        *r = t;
        p++;
        r--;
    }

    printf("\n����õ�˳��Ϊ��\n");
    for(i = 0; i < 10; ++i)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");

    return 0;
}
