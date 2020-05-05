/*
��������Counting Sort��

���������ǻ��ڱȽϵ������㷨����������ڽ����������ֵת��Ϊ���洢�ڶ��⿪�ٵ�����ռ��С�
��Ϊһ������ʱ�临�Ӷȵ����򣬼�������Ҫ����������ݱ�������ȷ����Χ��������
1 �㷨����

�ҳ��������������������С��Ԫ�أ�
ͳ��������ÿ��ֵΪi��Ԫ�س��ֵĴ�������������C�ĵ�i�
�����еļ����ۼӣ���C�еĵ�һ��Ԫ�ؿ�ʼ��ÿһ���ǰһ����ӣ���
�������Ŀ�����飺��ÿ��Ԫ��i����������ĵ�C(i)�ÿ��һ��Ԫ�ؾͽ�C(i)��ȥ1��

�㷨����
����������һ���ȶ��������㷨���������Ԫ���� n �� 0�� k ֮�������ʱ��ʱ�临�Ӷ���O(n+k)��
�ռ临�Ӷ�Ҳ��O(n+k)���������ٶȿ����καȽ������㷨����k���Ǻܴ������бȽϼ���ʱ��
����������һ������Ч�������㷨��

fileName:countSort.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int arr[], int len)
{
    for(int i = 0; i < len; ++i)
    {
        printf("%d ", arr[i]);
    }
}

void countSort(int *array, int size)
{
    int i;
    int minValue = array[0];
    int maxValue = array[0];
    int range = 0;
    int *pTemp = 0;
    int count = 0;
    for(i = 0; i < size; i++)//�������ݵķ�ɢ�ռ�
    {
        if(array[i] < minValue){
            minValue = array[i];
        }
        if(array[i] > maxValue) {
            maxValue = array[i];
        }
    }
    range = maxValue - minValue + 1;
    //����ռ䲢��ʼ��Ϊ0�� ��һ������ΪԪ�صĸ������ڶ�������Ϊÿ��Ԫ����ռ�ռ�Ĵ�С
    pTemp = (int*)calloc(range, sizeof(array[0]));
    if(pTemp == NULL)
        return;


    for(i = 0; i < size; ++i)//ͳ��ÿ��Ԫ�س��ֵĴ���
    {
        int index = array[i] - minValue;
        pTemp[index]++;
    }
    for(i = 0; i < range; ++i)//ͨ��ͳ��pTemp[];����Ԫ��
    {
        while(pTemp[i]--)
        {
            array[count++] = i + minValue;
        }
    }

    free(pTemp);
    pTemp = NULL;
}

int main()
{
    int array[10] = {43, 49, 57, 12, 9, 32, 83, 28, 5, 51};
    printf("count��������ǰ\n");
    print(array, 10);
    printf("\n");
    int size = sizeof(array) / sizeof(array[0]);
    countSort(array, size);
    printf("count���������\n");
    print(array, 10);
    printf("\n");
    printf("Hello World!\n");
    return 0;
}















