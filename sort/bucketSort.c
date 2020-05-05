/*
桶排序（Bucket Sort）

桶排序是计数排序的升级版。它利用了函数的映射关系，高效与否的关键就在于这个映射函数的确定。
桶排序 (Bucket sort)的工作的原理：假设输入数据服从均匀分布，将数据分到有限数量的桶里，
每个桶再分别排序（有可能再使用别的排序算法或是以递归方式继续使用桶排序进行排）。
1 算法描述

设置一个定量的数组当作空桶；
遍历输入数据，并且把数据一个一个放到对应的桶里去；
对每个不是空的桶进行排序；
从不是空的桶里把排好序的数据拼接起来。

算法分析
桶排序最好情况下使用线性时间O(n)，桶排序的时间复杂度，
取决与对各个桶之间数据进行排序的时间复杂度，因为其它部分的时间复杂度都为O(n)。
很显然，桶划分的越小，各个桶之间的数据越少，排序所用的时间也会越少。
但相应的空间消耗就会增大。

fileName:bucketSort.c
*/

#include <stdio.h>
#include <stdlib.h>

void print(int arr[], int len)
{
    for(int i = 0; i < len; ++i)
    {
        printf("%d ", arr[i]);
    }
}

//获得未排序数组中最大的一个元素值
int getMaxVal(int array[], int len)
{
    int maxVal = array[0];//假设最大为array[0]
    for(int i = 1; i < len; ++i)//遍历比较，找到大的就赋值 给maxVal
    {
        if(array[i] > maxVal)
            maxVal = array[i];
    }

    return maxVal;
}

//桶排序，参数：数组及其长度
void bucketSort(int array[], int len)
{
    int tempArrLen = getMaxVal(array, len) + 1;
    int tempArray[tempArrLen];//获得空桶大小
    int i,j;
    memset(tempArray, 0, tempArrLen);//空桶初始化
    for(i = 0, j = 0; i < len; ++i)
    {
        while(tempArray[i] != 0)//对每个不是空的桶子进行排序
        {
            array[j] = i;
            j++;
            tempArray[i]--;
        }
    }
}

int main()
{
    int array[10] = {43, 49, 57, 12, 9, 32, 83, 28, 5, 51};
    printf("bucket桶排序前\n");
    print(array, 10);
    printf("\n");
    int size = sizeof(array) / sizeof(array[0]);
    bucketSort(array, size);
    printf("bucket桶排序后\n");
    print(array, 10);
    printf("\n");
    printf("Hello World!\n");
    return 0;
}















