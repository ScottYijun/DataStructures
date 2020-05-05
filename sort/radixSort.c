/*
Ͱ����Bucket Sort��

Ͱ�����Ǽ�������������档�������˺�����ӳ���ϵ����Ч���Ĺؼ����������ӳ�亯����ȷ����
Ͱ���� (Bucket sort)�Ĺ�����ԭ�������������ݷ��Ӿ��ȷֲ��������ݷֵ�����������Ͱ�
ÿ��Ͱ�ٷֱ������п�����ʹ�ñ�������㷨�����Եݹ鷽ʽ����ʹ��Ͱ��������ţ���
1 �㷨����

����һ�����������鵱����Ͱ��
�����������ݣ����Ұ�����һ��һ���ŵ���Ӧ��Ͱ��ȥ��
��ÿ�����ǿյ�Ͱ��������
�Ӳ��ǿյ�Ͱ����ź��������ƴ��������

�㷨����
Ͱ������������ʹ������ʱ��O(n)��Ͱ�����ʱ�临�Ӷȣ�
ȡ����Ը���Ͱ֮�����ݽ��������ʱ�临�Ӷȣ���Ϊ�������ֵ�ʱ�临�Ӷȶ�ΪO(n)��
����Ȼ��Ͱ���ֵ�ԽС������Ͱ֮�������Խ�٣��������õ�ʱ��Ҳ��Խ�١�
����Ӧ�Ŀռ����ľͻ�����

fileName:bucketSort.c
*/

#include <stdio.h>
#include <stdlib.h>

#define Max_ 10      //�������
#define RADIX_10 10    //��������
#define KEYNUM_31 10     //�ؼ��ָ���������Ϊ����λ��

void print(int arr[], int len)
{
    for(int i = 0; i < len; ++i)
    {
        printf("%d ", arr[i]);
    }
}

//�ҵ�num�Ĵӵ͵��ߵĵ�posλ������
int getNumInPos(int num, int pos)
{
    int temp = 1;
    for(int i = 0; i < pos - 1; ++i)
    {
        temp *= 10;
    }

    return (num / temp) % 10;
}

//�������� array�������飬  sizeΪ�������ݸ���
void radixSort(int array[], int size)
{
    int *radixArrays[size];
    for(int i = 0; i < 10; ++i)
    {
        //����ռ䲢��ʼ��Ϊ0�� ��һ������ΪԪ�صĸ������ڶ�������Ϊÿ��Ԫ����ռ�ռ�Ĵ�С
        radixArrays[i] = (int*)calloc(sizeof(int) * (size + 1), sizeof(array[0]));
        radixArrays[i][0] = 0;//indexΪ0�����¼�������ݵĸ���
    }

    for(int pos = 1; pos <= KEYNUM_31; ++pos)
    {
        for(int i = 0; i < size; ++i)
        {
            int num = getNumInPos(array[i], pos);
            int index = ++radixArrays[num][0];
            radixArrays[num][index] = array[i];
        }

        for(int i = 0, j = 0; i < RADIX_10; ++i)
        {
            for(int k = 1; k <= radixArrays[i][0]; ++k)
                array[j++] = radixArrays[i][k];
            radixArrays[i][0] = 0;
        }
    }
}

int main()
{
    int array[10] = {43, 49, 57, 12, 9, 32, 83, 28, 5, 51};
    printf("radix��������ǰ\n");
    print(array, 10);
    printf("\n");
    int size = sizeof(array) / sizeof(array[0]);
    radixSort(array, size);
    printf("radix���������\n");
    print(array, 10);
    printf("\n");
    printf("Hello World!\n");
    return 0;
}












