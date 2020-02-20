#include <stdio.h>

#define MAXSIZE 10

typedef int ElementType;

void Create(ElementType x[], int *n)
{
    int i;
    printf("\n���������ݸ�����n=");
    scanf_s("%d", &(*n));
    printf("������%d���ݣ�",*n);
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
    printf("\n���鴴����ϣ� \n������������ǣ�");
    for(i = 0; i < n; ++i)
        printf("%4d", data[i]);
    Maxmin(data, n, &max, &min);

    printf("\n���ֵ�ǣ�%d\t��Сֵ�ǣ�%d\n", max, min);
    return 0;
}


