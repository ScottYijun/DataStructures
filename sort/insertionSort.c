/*
��������Insertion Sort��

��������Insertion-Sort�����㷨������һ�ּ�ֱ�۵������㷨��
���Ĺ���ԭ����ͨ�������������У�����δ�������ݣ�
�������������дӺ���ǰɨ�裬�ҵ���Ӧλ�ò����롣

�㷨����

һ����˵���������򶼲���in-place��������ʵ�֡������㷨�������£�
1.�ӵ�һ��Ԫ�ؿ�ʼ����Ԫ�ؿ�����Ϊ�Ѿ�������
2.ȡ����һ��Ԫ�أ����Ѿ������Ԫ�������дӺ���ǰɨ�裻
3.�����Ԫ�أ������򣩴�����Ԫ�أ�����Ԫ���Ƶ���һλ�ã�
4.�ظ�����3��ֱ���ҵ��������Ԫ��С�ڻ��ߵ�����Ԫ�ص�λ�ã�
5.����Ԫ�ز��뵽��λ�ú�
 �ظ�����2~5��

�㷨����

����������ʵ���ϣ�ͨ������in-place���򣨼�ֻ���õ�O(1)�Ķ���ռ�����򣩣�
����ڴӺ���ǰɨ������У���Ҫ������������Ԫ�������Ųλ��Ϊ����Ԫ���ṩ����ռ䡣

fileName:insertionSort.c

*/

#include <stdio.h>

int* insertionSort(int *array, int len)
{
    int preIndex, current;
    for(int i = 1; i < len; ++i)
    {
        preIndex = i - 1;
        current = array[i];
        while (preIndex >= 0 && array[preIndex] > current)
        {
            array[preIndex + 1] = array[preIndex];
            preIndex--;
        }
        array[preIndex + 1] = current;
    }

    return array;
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
    printf("��������ǰ\n");
    print(array, 10);
    printf("\n");
    insertionSort(array, 10);
    printf("���������\n");
    print(array, 10);
    printf("\n");
    printf("Hello World!\n");
    return 0;
}















