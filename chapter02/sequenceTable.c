#include "stdio.h"
#include "conio.h"

#define MaxSize 50                  //�������Ա���ܴﵽ����󳤶�

typedef char ElementType;

typedef struct node
{
    ElementType data[MaxSize];      //��̬�����һά����
    int length;                     //��ǰ����
}SeqList, *list;

//��ʼ��˳���
void InitList(list l)
{
    l->length = 0;
}

//˳�����
int LengthList(list l)
{
    return l->length;
}
int length(list l)
{
    return l->length;
}

//��ȡ˳���ĵ�i������ֵ
ElementType GetNode(list l, int i)
{
    if(i < 1 || i > l->length)
    {
        printf("get node error");
        return '\0';
    }
    else
    {
        return l->data[i - 1];
    }
}

//����x��˳����е�λ��
int LocationList(list l, ElementType x)
{
    int i = 0;
    while(i < l->length && l->data[i] != x)
        i++;
    if(i == l->length)
        return -1;                          //û�ҵ�����
    else
        return (i + 1);
}

//��˳����������
void InsertList(list l, int pos, ElementType x)
{
    //printf(" InsertList===pos = %d, x = %c\n", pos, x);
    int j;
    if(pos < 1 || pos > l->length + 1)
        printf("insert error\n");
    else
    {
        l->length++;                        //˳����ȼ�1
        for(j = l->length; j >= pos; j--)
            l->data[j] = l->data[j - 1];    //posλ�ú�������ݶ������ƶ�һ��λ��
        l->data[pos - 1] = x;               //��x���뵽posλ�ã�
    }
}

//ɾ��˳����еĽ��
void DeleteNode(list l, int pos)
{
    int j;
    if(pos < 1 || pos > l->length)
        printf("delete error\n");
    else
    {
        for(j = pos; j < l->length; j++)
            l->data[j - 1] = l->data[j];    //posλ�ú�������ݶ���ǰ��һ��λ��
        l->data[l->length - 1] = '\0';      //���һ��Ԫ���ÿ�
        l->length--;                        //˳���ĳ��ȼ�1
    }
}

//���˳���
void print(list l)
{
    int i;
    for(i = 1; i < l->length; i++)
        printf("%c->",l->data[i-1]);
    printf("%c", l->data[l->length-1]);
}


int main()
{
    int i = 1, n;
    SeqList l;
    char ch, x;
    InitList(&l);
    printf("\n\n\n *************************˳�����ʾ����***********\n");
    printf(" ���������뽨����˳����Ԫ�أ��ԣ�����:");
    ch=getchar();

    while(ch != '?')
    {
        InsertList(&l, i, ch);
        i++;
        ch = getchar();
    };

    printf(" �㽨����˳���Ϊ:");
    print(&l);
    printf("\n ˳���ĳ���Ϊ:%d", l.length);
    printf("\n ����������ҵ�Ԫ�أ�");
    fflush(stdin); //vs2017��֧��

    scanf(" %c", &x);
    printf(" ����ҵ�Ԫ��Ϊ%c��λΪ%d", x, LocationList(&l, x));

    printf("\n ����������ҵ�Ԫ����λ:");
    scanf(" %d", &n);
    printf("\n ����ҵ�Ԫ��Ϊ��%c", GetNode(&l, n));
    printf("\n ������������Ԫ���Լ���λ:<�ö��Ÿ���>:");

    scanf(" %c,%d", &x, &n);
    InsertList(&l, n, x);
    printf("\n �����˳���Ϊ��");
    print(&l);
    fflush(stdin);
    printf("\n ����������ɾ����Ԫ����λ��");
    scanf(" %d", &n);

    DeleteNode(&l, n);
    printf("\n ɾ�����˳���Ϊ��");
    print(&l);
    printf("\n ���Ա��˳��洢�Ļ������������ϣ�ллʹ��!");
    return 0;
}


//��ע��
//scanf(" %d", &n); scanf����ǰ���һ���ո��ԭ����ɾ���������ĵ�һ���ַ��ǻس������߿ո��
//��Ϊǰ��������ַ�fflush(stdin);������������յ����ã���������ʱ��ֱ�Ӷ�ȡ�������Ļػ����ˡ�
//����ͱ������й�ϵ
//����ƽ̨��win10   QT5.13.1 VS2017
//�ο����ӣ�
//https://blog.csdn.net/lrgy_zhch/article/details/6268386
//https://blog.csdn.net/weixin_45677047/article/details/104755732
//https://blog.csdn.net/fxwzzbd/article/details/2514042
//https://blog.csdn.net/jonathanlin2008/article/details/5026895

