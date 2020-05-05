/*
1959年Shell发明，第一个突破O(n2)的排序算法，是简单插入排序的改进版。
它与插入排序的不同之处在于，它会优先比较距离较远的元素。希尔排序又叫缩小增量排序。
算法描述

先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，具体算法描述：

1.选择一个增量序列t1，t2，…，tk，其中ti>tj，tk=1；
2.按增量序列个数k，对序列进行k 趟排序；
3.每趟排序，根据对应的增量ti，将待排序列分割成若干长度为m 的子序列，
分别对各子表进行直接插入排序。仅增量因子为1 时，整个序列作为一个表来处理，
表长度即为整个序列的长度。


算法分析

希尔排序的核心在于间隔序列的设定。既可以提前设定好间隔序列，也可以动态的定义间隔序列。
动态定义间隔序列的算法是《算法（第4版）》的合著者Robert Sedgewick提出的。

fileName:shellSort.c

*/

#include <stdio.h>
#include <math.h>

int* shellSort(int *array, int len)
{
    for(int i = floor(len / 2); i > 0; i = floor(i / 2))
    {
        for(int j = i; j < len; ++j)
        {
            int t = j;
            int current = array[j];
            while(t - i >= 0 && current < array[t - i]){
                array[t] = array[t - i];
                t = t - i;
            }
            array[t] = current;
        }
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
    printf("shell排序前\n");
    print(array, 10);
    printf("\n");
    shellSort(array, 10);
    printf("shell排序后\n");
    print(array, 10);
    printf("\n");
    printf("Hello World!\n");
    return 0;
}















