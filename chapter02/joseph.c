#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

typedef int Elemtype;               //定义数据元素类型

typedef struct Cnode
{
    Elemtype data;
    struct Cnode *next;
}CNode;

CNode *joseph;                      //定义一个全局变量

Status createList(CNode *list, int n)
{
    CNode *p, *q;
    int i;
    list = NULL;
    for(i = n; i >= 1; i--)
    {
        p = (CNode*)malloc(sizeof(CNode));
        if(NULL == p)
            return OVERFLOW;        //分配内存失败
        p->data = i;
        p->next = list;
        list = p;
        if(i == n)
            q = p;                  //用q指向链表的最后一个结点
    }
    q->next = list;                 //把链表的最后一个结点的链域指向链表的第一个结点，构成循环链表
    joseph = list;                  //把创建好的循环链表头指针赋给全局变量
    return OK;
}

Status Joseph(CNode *list, int pos, int num, int k)
{
    int i;
    CNode *p, *q;
    if(pos > num)
        return ERROR;               //起始位置错
    if(!createList(list, num))
        return ERROR;               //循环链表创建失败
    p = joseph;                     //p指向创建好的循环链表
    for(i = 1; i < pos; i++)
        p = p->next;                //p指向pos位置的结点
    while(p)
    {
        for(i = 1; i < k - 1; i++)
            p = p->next;            //找出第k个结点

        q = p->next;
        printf(" %d\t", q->data);    //输出应出列的结点
        if(p->next == p)
        {
            p = NULL;               //删除最后一个结点
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
    list = NULL;                    //初始化list
    printf("\n 请输入围坐在圆桌周围的人数num:");
    scanf(" %d", &num);
    printf("\n 请输入第一次开始报数人的位置pos:");
    scanf(" %d", &pos);
    printf("\n 你希望报数到第几个数的人出列？");
    scanf(" %d", &k);
    createList(list, num);          //创建一个有n个结点的循环链表list;
    printf("\n 出列的顺序如下：\n");
    Joseph(list, pos, num, k);

    printf("\nhello Joseph\n");
    return 0;
}


