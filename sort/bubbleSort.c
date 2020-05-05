/*
 * filename: bubbleSort.c
 *
ð������Bubble Sort��
ð��������һ�ּ򵥵������㷨�����ظ����߷ù�Ҫ��������У�һ�αȽ�����Ԫ�أ�
������ǵ�˳�����Ͱ����ǽ����������߷����еĹ������ظ��ؽ���ֱ��û������Ҫ������
Ҳ����˵�������Ѿ�������ɡ�����㷨��������������ΪԽС��Ԫ�ػᾭ�ɽ������������������еĶ��ˡ�

�㷨����
1.�Ƚ����ڵ�Ԫ�ء������һ���ȵڶ����󣬾ͽ�������������
2.��ÿһ������Ԫ����ͬ���Ĺ������ӿ�ʼ��һ�Ե���β�����һ�ԣ�����������Ԫ��Ӧ�û�����������
3.������е�Ԫ���ظ����ϵĲ��裬�������һ����
4.�ظ�����1~3��ֱ��������ɡ�

*/

#include <stdio.h>

void bubbleSort(int array[], int len)
{
    for(int i = 0; i < len - 1; ++i)
    {
        for(int j = 0; j < len - 1 - i; ++j)
        {
            if(array[j] > array[j + 1])//�������������Ƚ�
            {
                int temp = array[j + 1];//Ԫ�ؽ���
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
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
    printf("����ǰ\n");
    print(array, 10);
    printf("\n");
    bubbleSort(array, 10);
    printf("�����\n");
    print(array, 10);
    printf("\n");
    printf("Hello World!\n");
    return 0;
}
