#include <stdio.h>

int main()
{
    int digit;      //��λ��
    int ten;        //ʮλ��
    int hun;        //��λ��
    int daffodil;   //ˮ�ɻ���
    printf("daffodil data ��");
    for(int n = 100; n < 1000; ++n)
    {
        digit = n % 10;
        ten = (n / 10) % 10;
        hun = n / 100;
        daffodil = (digit * digit * digit) + (ten * ten * ten) + (hun * hun * hun);
        if(n == daffodil)
        {
            printf("%d ", n);
        }
    }
    printf("\n");

    return 0;
}
