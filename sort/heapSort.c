/*
堆排序（Heapsort） 是指利用堆这种数据结构所设计的一种排序算法。
堆积是一个近似完全二叉树的结构，并同时满足堆积的性质：
即子结点的键值或索引总是小于（或者大于）它的父节点。

1 算法描述
步骤1：将初始待排序关键字序列(R1,R2….Rn)构建成大顶堆，此堆为初始的无序区；

步骤2：将堆顶元素R[1]与最后一个元素R[n]交换，
此时得到新的无序区(R1,R2,……Rn-1)和新的有序区(Rn),且满足R[1,2…n-1]<=R[n]；

步骤3：由于交换后新的堆顶R[1]可能违反堆的性质，
因此需要对当前无序区(R1,R2,……Rn-1)调整为新堆，然后再次将R[1]与无序区最后一个元素交换，
得到新的无序区(R1,R2….Rn-2)和新的有序区(Rn-1,Rn)。
不断重复此过程直到有序区的元素个数为n-1，则整个排序过程完成。

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
    //如果有左子树，且左子树大于父节点，则将最大指针指向左子树
    if(i * 2 < len && array[i * 2] > array[maxIndex])
        maxIndex = i * 2;
    //如果没有右子树，且右子树大于父节点，则将最大指针指向右子树
    if(i * 2 + 1 < len && array[i * 2 + 1] > array[maxIndex])
        maxIndex = i * 2 + 1;
    //如果父节点不是最大值 ，则将父节点与最大值交换，并且递归调整与父节点交换的位置。
    if(maxIndex != i)
    {
        swap(&array[maxIndex], &array[i]);
        adjustHeap(array, maxIndex, len);
    }
}

void buildMaxHeap(int array[], int len)
{
    //从最后一个非叶子节点开始向上构造最大堆
    //for循环这样写会更好一点：i的左子树和右子对分别2i + 1和2(i+1)
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

    //1.构造一个最大堆
    buildMaxHeap(array, len);
    //2、循环将堆首位（最大值 ）与末位交换，然后在重新调整最大堆
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
    printf("heap堆排序前\n");
    print(array, 10);
    printf("\n");
    heapSort(array, 10);
    printf("heap堆排序后\n");
    print(array, 10);
    printf("\n");
    printf("Hello World!\n");
    return 0;
}















