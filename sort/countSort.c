/*
计数排序（Counting Sort）

计数排序不是基于比较的排序算法，其核心在于将输入的数据值转化为键存储在额外开辟的数组空间中。
作为一种线性时间复杂度的排序，计数排序要求输入的数据必须是有确定范围的整数。
1 算法描述

找出待排序的数组中最大和最小的元素；
统计数组中每个值为i的元素出现的次数，存入数组C的第i项；
对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）；
反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1。

算法分析
计数排序是一个稳定的排序算法。当输入的元素是 n 个 0到 k 之间的整数时，时间复杂度是O(n+k)，
空间复杂度也是O(n+k)，其排序速度快于任何比较排序算法。当k不是很大并且序列比较集中时，
计数排序是一个很有效的排序算法。

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
    for(i = 0; i < size; i++)//计算数据的分散空间
    {
        if(array[i] < minValue){
            minValue = array[i];
        }
        if(array[i] > maxValue) {
            maxValue = array[i];
        }
    }
    range = maxValue - minValue + 1;
    //申请空间并初始化为0， 第一个参数为元素的个数，第二个参数为每个元素所占空间的大小
    pTemp = (int*)calloc(range, sizeof(array[0]));
    if(pTemp == NULL)
        return;


    for(i = 0; i < size; ++i)//统计每个元素出现的次数
    {
        int index = array[i] - minValue;
        pTemp[index]++;
    }
    for(i = 0; i < range; ++i)//通过统计pTemp[];回收元素
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
    printf("count计数排序前\n");
    print(array, 10);
    printf("\n");
    int size = sizeof(array) / sizeof(array[0]);
    countSort(array, size);
    printf("count计数排序后\n");
    print(array, 10);
    printf("\n");
    printf("Hello World!\n");
    return 0;
}















