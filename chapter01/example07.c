#include <stdio.h>

int main()
{
    int i, j, t, n, a[11]; //定义变量及数组为基本整型
    printf("please input the value of n\n");
    scanf_s("%d", &n);//从键盘中输入10数
    printf("please input your number:\n");
    for(i = 0; i < n; ++i)
        scanf_s("%d", &a[i]);
    printf("原始顺序是：\n");
    for(i = 0; i < 10; ++i)
        printf("%5d", a[i]);
    printf("\n");
    for(i = 1; i < n; ++i)//变量i代表比较的趟数
    {
        for(j = 1; j < n - i; ++j)//变量j代码每趟两两比较的次数
            if(a[j] > a[j+1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
    }

    printf("排序后的顺序是：\n");
    for(i = 0; i < 10; ++i)
        printf("%5d", a[i]);

    printf("\n");
    return 0;
}


