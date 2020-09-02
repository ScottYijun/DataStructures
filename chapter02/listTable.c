#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

// 结点结构的定义
struct ListNode
{
    ElementType data;//数据域
    struct ListNode *next;//链域
};

typedef struct ListNode Node;
typedef struct ListNode *Linklist;
//typedef Node *Linklist;


//创建链表
Linklist createList(Linklist head)
{
    Linklist ptr, temp;
    char ch;
    head = (Node *)malloc(sizeof(Node));
    if(NULL == head)
    {
        printf("创建链表错误，分配空间失败");
        return NULL;
    }
    //分配空间成功
    head->next = NULL;
    ptr = head;
    printf("请输入数据元素（输入#号结束。）：\t");
    scanf(" %c", &ch);
    //while((ch = getchar()) != '#')
    while(ch != '#')
    {
        temp = (Node*)malloc(sizeof(Node));
        temp->next = NULL;//指针域
        temp->data = ch;//数据域
        ptr->next = temp;//ptr的下一个节点指向该节点
        ptr = temp; //ptr指向该节点，这个时候temp的next为NULL
        fflush(stdin);//刷新缓冲区
        printf("请输入数据元素（输入#号结束。）：\t");
        scanf(" %c", &ch);
    }

    return head->next;
}

//画线函数
void drawLine(char c)
{
    int i;
    printf("\n");
    for (i = 0; i < 70; i++)
        printf("%c", c);
    printf("\n");
}

//输出链表数据
void printList(Linklist head)
{
    Linklist ptr;
    ptr = head;
    drawLine('-');
    printf("单链表显示是：\n");
    while(ptr)
    {
        printf("%3c", ptr->data);
        ptr = ptr->next;
    }
    drawLine('-');
}

//释放链表的结点空间
void freeList(Linklist head)
{
    Linklist temp;
    while(head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("\n 单链表的结点空间释放成功！\n");
}

//向链表中插入新结点
Linklist insertList(Linklist head, Linklist new, ElementType data)
{
    Linklist ptr;
    ElementType date;
    printf("请输入所要插入的数据元素：");
    //date = getchar();
    scanf(" %c", &date);
    new->data = date;
    ptr = head;
    while(1)
    {
        if(NULL == head)
        {
            new->next = head;
            head = new;
            break;
        }
        else if(ptr->data == data)
        {
            new->next = ptr->next;
            ptr->next = new;
            break;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    return head;
}

//删除链表中的结点
Linklist deleteList(Linklist head, ElementType data)
{
    Linklist ptr, prv;
    ptr = head;
    while(1)
    {
        if(ptr->next == NULL)
        {
            printf("没有找到所要删除的数据元素！\n");
            break;
        }
        if(head->data == data)
        {
            head = ptr->next;
            free(ptr);
            break;
        }
        prv = ptr;
        ptr = ptr->next;
        if(ptr->data == data)
        {
            prv->next = ptr->next;
            free(ptr);
            break;
        }
    }
    return head;
}


//修改结点的数据域
Linklist modifyList(Linklist head, ElementType data)
{
    Linklist ptr;
    ElementType date;
    ptr = head;//令ptr指向head结点
    while(1)
    {
        if(ptr->next == NULL)
        {
            printf("没有找到所要修改的数据元素！\n");
            break;
        }
        else if(head->data == data)
        {
            fflush(stdin);
            printf("请输入覆盖 %c 的数据元素:", data);
            scanf(" %c", &date);
            ptr->data = date;
            fflush(stdin);
            break;
        }
        else
        {
            ptr = ptr->next;//指向下一个结点
        }
    }
    return head;
}

//链表转置
Linklist invertList(Linklist head)
{
    Linklist ptr, prv, next;
    prv = head;
    ptr = prv->next;
    prv->next = NULL;
    next = ptr->next;
    ptr->next = prv;
    prv = ptr;
    ptr = next;
    while(ptr->next)
    {
        next = ptr->next;
        ptr->next = prv;
        prv = ptr;
        ptr = next;
    }
    ptr->next = prv;
    head = ptr;
    return head;
}


int main(void)
{
    Linklist head, new;
    ElementType data;
    int choose;
    head = NULL;

    drawLine('*');
    head = createList(head);
    printList(head);

    while (1)
    {
        printf( "\n\n +--------------------- Menu ------------------------+\n" );
        printf( "|1.插入 2.删除 3.修改 4.转置 5.释放 0 退出 |\n" );
        printf( "+-------------------------------------------------+\n" );
        printf("请输入你所要选择的操作 ( 0 -- 5 )：");
        scanf( " %d", &choose);
        switch (choose)
        {
            case 0:
                exit(0);
                break;
            case 1:
                new = (Node*)malloc(sizeof(Node));
                new->next = NULL;
                fflush(stdin);
                printf("\n 请输入到那个数据元素的后面：");
                scanf(" %c", &data);
                fflush(stdin);
                head = insertList(head, new, data);
                printList(head);
                break;
            case 2:
                fflush(stdin);
                printf("\n 请输入所要删除的数据元素:");
                scanf(" %c", &data);
                fflush(stdin);
                head = deleteList(head, data);
                printList(head);
                break;
            case 3:
                fflush(stdin);
                printf("\n 请输入你所要修改的数据元素：");
                scanf(" %c", &data);
                fflush(stdin);
                head = modifyList(head, data);
                printList(head);
                break;
            case 4:
                head = invertList(head);
                printList(head);
                break;
            case 5:
                freeList(head);
                break;
            default:
                printf("\n 你的选择是非法的！\n");
                break;
        }
    }


    return 0;
}
