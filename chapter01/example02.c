#include <stdio.h>

#define LEN 100

int main()
{
    int n, j;
    int num1, num2, chr1, chr2;
    char chr[LEN], temp[LEN];
    printf("please input the string:");//������Ҫ���ܵ��ַ���
    fgets(chr, LEN, stdin); //��ȡ�ַ�����gets�������Ѿ�������
    printf("\nthe string is:%s", chr);
    printf("\nplease input num2(1<=num2<=26)");
    scanf_s("%d", &num2);
    printf("\nplease input num1(1<=num1<=26)");
    scanf_s("%d", &num1);
    j = 0;
    while('\0' != chr[j])
    {
        if((chr[j] >= 'A') && (chr[j] <= 'Z'))
        {
            chr1 = 91 -chr[j];//ת����õ���Сд��ĸ����ĸ���е�˳���
            if((chr1 - num2) < 0)
                temp[j] = 187 - chr[j] - num2 + 26;//����ת����ѭ����ʼ��Сд��ĸ
            else
                temp[j] = 187 - chr[j] - num2;//���򣬵õ�������ת������ӦСд��ĸ
        }
        else if((chr[j] >= 'a') && (chr[j] < 'z'))
        {
            chr2 = 123 - chr[j];
            if((chr2 - num1) < 0)
                temp[j] = 187 - chr[j] - num1 + 26;
            else
                temp[j] = 187 - chr[j] - num1;
        }

        ++j;
    }

    n = j;
    //�����ַ����ĳ���
    printf("\nthe result string:");//������ܺ�Ľ��
    for(j = 0; j < n; ++j)
        putchar(temp[j]);
    printf("\n");

    return 0;
}
