#include <stdio.h>

int main()
{
    int i, j, t, n, a[11]; //�������������Ϊ��������
    printf("please input the value of n\n");
    scanf_s("%d", &n);//�Ӽ���������10��
    printf("please input your number:\n");
    for(i = 0; i < n; ++i)
        scanf_s("%d", &a[i]);
    printf("ԭʼ˳���ǣ�\n");
    for(i = 0; i < 10; ++i)
        printf("%5d", a[i]);
    printf("\n");
    for(i = 1; i < n; ++i)//����i����Ƚϵ�����
    {
        for(j = 1; j < n - i; ++j)//����j����ÿ�������ȽϵĴ���
            if(a[j] > a[j+1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
    }

    printf("������˳���ǣ�\n");
    for(i = 0; i < 10; ++i)
        printf("%5d", a[i]);

    printf("\n");
    return 0;
}


