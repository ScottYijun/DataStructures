/*
 * filename: selectionSort.c
 *
ѡ������Selection Sort��

ѡ������(Selection-sort)��һ�ּ�ֱ�۵������㷨��
���Ĺ���ԭ��������δ�����������ҵ���С����Ԫ�أ���ŵ��������е���ʼλ�ã�
Ȼ���ٴ�ʣ��δ����Ԫ���м���Ѱ����С����Ԫ�أ�Ȼ��ŵ����������е�ĩβ��
�Դ����ƣ�ֱ������Ԫ�ؾ�������ϡ�

�㷨����

n����¼��ֱ��ѡ������ɾ���n-1��ֱ��ѡ������õ��������������㷨�������£�
��ʼ״̬��������ΪR[1..n]��������Ϊ�գ�
��i������(i=1,2,3��n-1)��ʼʱ����ǰ���������������ֱ�ΪR[1..i-1]��R(i..n����
��������ӵ�ǰ��������-ѡ���ؼ�����С�ļ�¼ R[k]���������������ĵ�1����¼R������
ʹR[1..i]��R[i+1..n)�ֱ��Ϊ��¼��������1�������������ͼ�¼��������1��������������
n-1�˽��������������ˡ�


*/

#include <stdio.h>

void selectionSort(int array[], int len)
{
    int minIndex, temp;
    for(int i = 0; i < len - 1; ++i)
    {
        minIndex = i;
        for(int j = i + 1; j < len; ++j)
        {
            if(array[j] < array[minIndex])//Ѱ����С����
            {
                minIndex = j;//����С������������
            }
        }
        temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
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
    printf("ѡ������ǰ\n");
    print(array, 10);
    printf("\n");
    selectionSort(array, 10);
    printf("ѡ�������\n");
    print(array, 10);
    printf("\n");
    printf("Hello World!\n");
    return 0;
}
