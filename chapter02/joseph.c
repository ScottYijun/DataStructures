#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

typedef int Elemtype;               //��������Ԫ������

typedef struct Cnode
{
    Elemtype data;
    struct Cnode *next;
}CNode;

CNode *joseph;                      //����һ��ȫ�ֱ���

Status createList(CNode *list, int n)
{
    CNode *p, *q;
    int i;
    list = NULL;
    for(i = n; i >= 1; i--)
    {
        p = (CNode*)malloc(sizeof(CNode));
        if(NULL == p)
            return OVERFLOW;        //�����ڴ�ʧ��
        p->data = i;
        p->next = list;
        list = p;
        if(i == n)
            q = p;                  //��qָ����������һ�����
    }
    q->next = list;                 //����������һ����������ָ������ĵ�һ����㣬����ѭ������
    joseph = list;                  //�Ѵ����õ�ѭ������ͷָ�븳��ȫ�ֱ���
    return OK;
}

Status Joseph(CNode *list, int pos, int num, int k)
{
    int i;
    CNode *p, *q;
    if(pos > num)
        return ERROR;               //��ʼλ�ô�
    if(!createList(list, num))
        return ERROR;               //ѭ��������ʧ��
    p = joseph;                     //pָ�򴴽��õ�ѭ������
    for(i = 1; i < pos; i++)
        p = p->next;                //pָ��posλ�õĽ��
    while(p)
    {
        for(i = 1; i < k - 1; i++)
            p = p->next;            //�ҳ���k�����

        q = p->next;
        printf(" %d\t", q->data);    //���Ӧ���еĽ��
        if(p->next == p)
        {
            p = NULL;               //ɾ�����һ�����
        }
        else
        {
            p->next = q->next;
            p = p->next;
            free(q);
        }
    }
    list = NULL;

    return OK;
}

int main()
{
    int pos, num, k;
    CNode *list;
    list = NULL;                    //��ʼ��list
    printf("\n ������Χ����Բ����Χ������num:");
    scanf(" %d", &num);
    printf("\n �������һ�ο�ʼ�����˵�λ��pos:");
    scanf(" %d", &pos);
    printf("\n ��ϣ���������ڼ��������˳��У�");
    scanf(" %d", &k);
    createList(list, num);          //����һ����n������ѭ������list;
    printf("\n ���е�˳�����£�\n");
    Joseph(list, pos, num, k);

    printf("\nhello Joseph\n");
    return 0;
}


