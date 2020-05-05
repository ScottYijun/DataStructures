/*
归并排序（Merge Sort）

归并排序是建立在归并操作上的一种有效的排序算法。
该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。
将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。
若将两个有序表合并成一个有序表，称为2-路归并。
算法描述
1.把长度为n的输入序列分成两个长度为n/2的子序列；
2.对这两个子序列分别采用归并排序；
3.将两个排序好的子序列合并成一个最终的排序序列。

算法分析

归并排序是一种稳定的排序方法。和选择排序一样，归并排序的性能不受输入数据的影响，
但表现比选择排序好的多，因为始终都是O(nlogn）的时间复杂度。代价是需要额外的内存空间。

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
    printf("merge归并排序前\n");
    print(array, 10);
    printf("\n");
    mergesort(array, 0, 10);
    printf("merge归并排序后\n");
    print(array, 10);
    printf("\n");
    printf("Hello World!\n");
    return 0;
}















