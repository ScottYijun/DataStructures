#include <stdio.h>

#define MAXSIZE 10

typedef int ElementType;

void Create(ElementType x[], int *n)
{
    int i;
    printf("\n请输入数据个数据n=");
    scanf_s("%d", &(*n));
    printf("请输入%d数据：",*n);
    for(i = 0; i < *n; ++i)
    {
        scanf_s("%d", &x[i]);
    }
}

void Maxmin(ElementType x[], int n, int *max, int *min)
{
    int i;
    *max = *min = x[1];
    for(i = 0; i < n; ++i)
    {
        if(x[i] > *max)
            *max = x[i];
        if(x[i] < *min)
            *min = x[i];
    }
}

int main()
{
    ElementType data[MAXSIZE + 1];
    int i, n, max, min;
    Create(data, &n);
    printf("\n数组创建完毕！ \n所输入的数据是：");
    for(i = 0; i < n; ++i)
        printf("%4d", data[i]);
    Maxmin(data, n, &max, &min);

    printf("\n最大值是：%d\t最小值是：%d\n", max, min);
    return 0;
}


