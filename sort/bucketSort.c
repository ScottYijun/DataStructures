/*
Ͱ����Bucket Sort��

Ͱ�����Ǽ�������������档�������˺�����ӳ���ϵ����Ч���Ĺؼ����������ӳ�亯����ȷ����
Ͱ���� (Bucket sort)�Ĺ�����ԭ�������������ݷ��Ӿ��ȷֲ��������ݷֵ�����������Ͱ�
ÿ��Ͱ�ٷֱ������п�����ʹ�ñ�������㷨�����Եݹ鷽ʽ����ʹ��Ͱ��������ţ���
1 �㷨����

����һ�����������鵱����Ͱ��
�����������ݣ����Ұ�����һ��һ���ŵ���Ӧ��Ͱ��ȥ��
��ÿ�����ǿյ�Ͱ��������
�Ӳ��ǿյ�Ͱ����ź��������ƴ��������

�㷨����
Ͱ������������ʹ������ʱ��O(n)��Ͱ�����ʱ�临�Ӷȣ�
ȡ����Ը���Ͱ֮�����ݽ��������ʱ�临�Ӷȣ���Ϊ�������ֵ�ʱ�临�Ӷȶ�ΪO(n)��
����Ȼ��Ͱ���ֵ�ԽС������Ͱ֮�������Խ�٣��������õ�ʱ��Ҳ��Խ�١�
����Ӧ�Ŀռ����ľͻ�����

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

//���δ��������������һ��Ԫ��ֵ
int getMaxVal(int array[], int len)
{
    int maxVal = array[0];//�������Ϊarray[0]
    for(int i = 1; i < len; ++i)//�����Ƚϣ��ҵ���ľ͸�ֵ ��maxVal
    {
        if(array[i] > maxVal)
            maxVal = array[i];
    }

    return maxVal;
}

//Ͱ���򣬲��������鼰�䳤��
void bucketSort(int array[], int len)
{
    int tempArrLen = getMaxVal(array, len) + 1;
    int tempArray[tempArrLen];//��ÿ�Ͱ��С
    int i,j;
    memset(tempArray, 0, tempArrLen);//��Ͱ��ʼ��
    for(i = 0, j = 0; i < len; ++i)
    {
        while(tempArray[i] != 0)//��ÿ�����ǿյ�Ͱ�ӽ�������
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
    printf("bucketͰ����ǰ\n");
    print(array, 10);
    printf("\n");
    int size = sizeof(array) / sizeof(array[0]);
    bucketSort(array, size);
    printf("bucketͰ�����\n");
    print(array, 10);
    printf("\n");
    printf("Hello World!\n");
    return 0;
}















