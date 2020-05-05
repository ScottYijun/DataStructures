/*
��������Quick Sort��

��������Ļ���˼�룺ͨ��һ�����򽫴��ż�¼�ָ��ɶ����������֣�
����һ���ּ�¼�Ĺؼ��־�����һ���ֵĹؼ���С��
��ɷֱ���������ּ�¼�������������Դﵽ������������

1 �㷨����
��������ʹ�÷��η�����һ������list����Ϊ�����Ӵ���sub-lists���������㷨�������£�
������������һ��Ԫ�أ���Ϊ ����׼����pivot����
�����������У�����Ԫ�رȻ�׼ֵС�İڷ��ڻ�׼ǰ�棬
����Ԫ�رȻ�׼ֵ��İ��ڻ�׼�ĺ��棨��ͬ�������Ե���һ�ߣ���
����������˳�֮�󣬸û�׼�ʹ������е��м�λ�á������Ϊ������partition��������
�ݹ�أ�recursive����С�ڻ�׼ֵԪ�ص������кʹ��ڻ�׼ֵԪ�ص�����������


fileName:quickSort.c

*/

#include <stdio.h>

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

int partition(int array[], int start, int end)
{
    int pivot = array[start];
    int j;
    j = start;
    for(int i = start + 1; i <= end; ++i)
    {
        if(array[i] < pivot)
        {
            swap(&array[j + 1], &array[i]);//����û�и��õ����ݽ�����ʽ��
            ++j;
        }
    }
    swap(&array[start], &array[j]);

    return j;
}

void quickSort(int array[], int start, int end)
{
    if(start >= end)
    {
        return;
    }

    int smallIndex = partition(array, start, end);
    if(smallIndex > start)
        quickSort(array, start, smallIndex - 1);
    if(smallIndex < end)
        quickSort(array, smallIndex + 1, end);
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
    printf("quick��������ǰ\n");
    print(array, 10);
    printf("\n");
    quickSort(array, 0, 9);
    printf("quik���������\n");
    print(array, 10);
    printf("\n");
    printf("Hello World!\n");
    return 0;
}















