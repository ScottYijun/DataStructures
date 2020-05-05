/*
1959��Shell��������һ��ͻ��O(n2)�������㷨���Ǽ򵥲�������ĸĽ��档
�����������Ĳ�֮ͬ�����ڣ��������ȱȽϾ����Զ��Ԫ�ء�ϣ�������ֽ���С��������
�㷨����

�Ƚ�����������ļ�¼���зָ��Ϊ���������зֱ����ֱ�Ӳ������򣬾����㷨������

1.ѡ��һ����������t1��t2������tk������ti>tj��tk=1��
2.���������и���k�������н���k ������
3.ÿ�����򣬸��ݶ�Ӧ������ti�����������зָ�����ɳ���Ϊm �������У�
�ֱ�Ը��ӱ����ֱ�Ӳ������򡣽���������Ϊ1 ʱ������������Ϊһ����������
���ȼ�Ϊ�������еĳ��ȡ�


�㷨����

ϣ������ĺ������ڼ�����е��趨���ȿ�����ǰ�趨�ü�����У�Ҳ���Զ�̬�Ķ��������С�
��̬���������е��㷨�ǡ��㷨����4�棩���ĺ�����Robert Sedgewick����ġ�

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
    printf("shell����ǰ\n");
    print(array, 10);
    printf("\n");
    shellSort(array, 10);
    printf("shell�����\n");
    print(array, 10);
    printf("\n");
    printf("Hello World!\n");
    return 0;
}















