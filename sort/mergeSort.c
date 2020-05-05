/*
�鲢����Merge Sort��

�鲢�����ǽ����ڹ鲢�����ϵ�һ����Ч�������㷨��
���㷨�ǲ��÷��η���Divide and Conquer����һ���ǳ����͵�Ӧ�á�
��������������кϲ����õ���ȫ��������У�����ʹÿ��������������ʹ�����жμ�����
�������������ϲ���һ���������Ϊ2-·�鲢��
�㷨����
1.�ѳ���Ϊn���������зֳ���������Ϊn/2�������У�
2.�������������зֱ���ù鲢����
3.����������õ������кϲ���һ�����յ��������С�

�㷨����

�鲢������һ���ȶ������򷽷�����ѡ������һ�����鲢��������ܲ����������ݵ�Ӱ�죬
�����ֱ�ѡ������õĶ࣬��Ϊʼ�ն���O(nlogn����ʱ�临�Ӷȡ���������Ҫ������ڴ�ռ䡣

fileName:mergeSort.c

*/

#include <stdio.h>

void merge(int array[], int left, int right, int middle)
{
    int aux[right - left + 1], i, j, k;
    for(k = left; k <= right; ++k)
        aux[k - left] = array[k];

    i = left;
    j = middle + 1;
    for(k = left; k <= right; ++k)
    {
        if(i > middle)
        {
            array[k] = aux[j - left];
            ++j;
        }
        else if(j > right)
        {
            array[k] = aux[i - left];
            ++i;
        }
        else if(aux[i - left] > aux[j - left])
        {
            array[k] = aux[j - left];
            ++j;
        }
        else
        {
            array[k] = aux[i - left];
            ++i;
        }
    }
}

void merge_sort(int array[], int left, int right)
{
    if(left >= right)
        return;
    int middle = (left + right) / 2;
    merge_sort(array, left, middle);
    merge_sort(array, middle + 1, right);
    merge(array, left, right, middle);
}

void mergesort(int array[], int left, int right)
{
    merge_sort(array, left, right - 1);
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
    printf("merge�鲢����ǰ\n");
    print(array, 10);
    printf("\n");
    mergesort(array, 0, 10);
    printf("merge�鲢�����\n");
    print(array, 10);
    printf("\n");
    printf("Hello World!\n");
    return 0;
}















