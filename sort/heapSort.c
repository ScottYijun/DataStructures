/*
������Heapsort�� ��ָ���ö��������ݽṹ����Ƶ�һ�������㷨��
�ѻ���һ��������ȫ�������Ľṹ����ͬʱ����ѻ������ʣ�
���ӽ��ļ�ֵ����������С�ڣ����ߴ��ڣ����ĸ��ڵ㡣

1 �㷨����
����1������ʼ������ؼ�������(R1,R2��.Rn)�����ɴ󶥶ѣ��˶�Ϊ��ʼ����������

����2�����Ѷ�Ԫ��R[1]�����һ��Ԫ��R[n]������
��ʱ�õ��µ�������(R1,R2,����Rn-1)���µ�������(Rn),������R[1,2��n-1]<=R[n]��

����3�����ڽ������µĶѶ�R[1]����Υ���ѵ����ʣ�
�����Ҫ�Ե�ǰ������(R1,R2,����Rn-1)����Ϊ�¶ѣ�Ȼ���ٴν�R[1]�����������һ��Ԫ�ؽ�����
�õ��µ�������(R1,R2��.Rn-2)���µ�������(Rn-1,Rn)��
�����ظ��˹���ֱ����������Ԫ�ظ���Ϊn-1�����������������ɡ�

fileName:heapSort.c
*/

#include <stdio.h>

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

void adjustHeap(int array[], int i, int len)
{
    int maxIndex = i;
    //������������������������ڸ��ڵ㣬�����ָ��ָ��������
    if(i * 2 < len && array[i * 2] > array[maxIndex])
        maxIndex = i * 2;
    //���û���������������������ڸ��ڵ㣬�����ָ��ָ��������
    if(i * 2 + 1 < len && array[i * 2 + 1] > array[maxIndex])
        maxIndex = i * 2 + 1;
    //������ڵ㲻�����ֵ ���򽫸��ڵ������ֵ���������ҵݹ�����븸�ڵ㽻����λ�á�
    if(maxIndex != i)
    {
        swap(&array[maxIndex], &array[i]);
        adjustHeap(array, maxIndex, len);
    }
}

void buildMaxHeap(int array[], int len)
{
    //�����һ����Ҷ�ӽڵ㿪ʼ���Ϲ�������
    //forѭ������д�����һ�㣺i�������������ӶԷֱ�2i + 1��2(i+1)
    for(int i = (len / 2 - 1); i >= 0; --i)
    {
        adjustHeap(array, i, len);
    }
}

void heapSort(int array[], int len1)
{
    if(len1 < 1)
        return;
    int len = len1;

    //1.����һ������
    buildMaxHeap(array, len);
    //2��ѭ��������λ�����ֵ ����ĩλ������Ȼ�������µ�������
    while(len > 0)
    {
        swap(&array[0], &array[len - 1]);
        --len;
        adjustHeap(array, 0, len);
    }
}

void print(int arr[], int len)
{
    for(int i = 0; i < len; ++i)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int array[10] = {43, 49, 57, 12, 9, 32, 83, 28, 5, 51};
    printf("heap������ǰ\n");
    print(array, 10);
    printf("\n");
    heapSort(array, 10);
    printf("heap�������\n");
    print(array, 10);
    printf("\n");
    printf("Hello World!\n");
    return 0;
}















