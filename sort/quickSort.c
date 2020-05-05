/*
快速排序（Quick Sort）

快速排序的基本思想：通过一趟排序将待排记录分隔成独立的两部分，
其中一部分记录的关键字均比另一部分的关键字小，
则可分别对这两部分记录继续进行排序，以达到整个序列有序。

1 算法描述
快速排序使用分治法来把一个串（list）分为两个子串（sub-lists）。具体算法描述如下：
从数列中挑出一个元素，称为 “基准”（pivot）；
重新排序数列，所有元素比基准值小的摆放在基准前面，
所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。
在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；
递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序。


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
            swap(&array[j + 1], &array[i]);//还有没有更好的数据交换方式？
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
    printf("quick快速排序前\n");
    print(array, 10);
    printf("\n");
    quickSort(array, 0, 9);
    printf("quik快速排序后\n");
    print(array, 10);
    printf("\n");
    printf("Hello World!\n");
    return 0;
}















