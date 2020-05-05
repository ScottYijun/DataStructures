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

#define Max_ 10      //数组个数
#define RADIX_10 10    //整形排序
#define KEYNUM_31 10     //关键字个数，这里为整形位数

void print(int arr[], int len)
{
    for(int i = 0; i < len; ++i)
    {
        printf("%d ", arr[i]);
    }
}

//找到num的从低到高的第pos位的数据
int getNumInPos(int num, int pos)
{
    int temp = 1;
    for(int i = 0; i < pos - 1; ++i)
    {
        temp *= 10;
    }

    return (num / temp) % 10;
}

//基数排序 array无序数组，  size为无序数据个数
void radixSort(int array[], int size)
{
    int *radixArrays[size];
    for(int i = 0; i < 10; ++i)
    {
        //申请空间并初始化为0， 第一个参数为元素的个数，第二个参数为每个元素所占空间的大小
        radixArrays[i] = (int*)calloc(sizeof(int) * (size + 1), sizeof(array[0]));
        radixArrays[i][0] = 0;//index为0处理记录这组数据的个数
    }

    for(int pos = 1; pos <= KEYNUM_31; ++pos)
    {
        for(int i = 0; i < size; ++i)
        {
            int num = getNumInPos(array[i], pos);
            int index = ++radixArrays[num][0];
            radixArrays[num][index] = array[i];
        }

        for(int i = 0, j = 0; i < RADIX_10; ++i)
        {
            for(int k = 1; k <= radixArrays[i][0]; ++k)
                array[j++] = radixArrays[i][k];
            radixArrays[i][0] = 0;
        }
    }
}

int main()
{
    int array[10] = {43, 49, 57, 12, 9, 32, 83, 28, 5, 51};
    printf("radix基数排序前\n");
    print(array, 10);
    printf("\n");
    int size = sizeof(array) / sizeof(array[0]);
    radixSort(array, size);
    printf("radix基数排序后\n");
    print(array, 10);
    printf("\n");
    printf("Hello World!\n");
    return 0;
}












