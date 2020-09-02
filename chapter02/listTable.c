#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

// ���ṹ�Ķ���
struct ListNode
{
    ElementType data;//������
    struct ListNode *next;//����
};

typedef struct ListNode Node;
typedef struct ListNode *Linklist;
//typedef Node *Linklist;


//��������
Linklist createList(Linklist head)
{
    Linklist ptr, temp;
    char ch;
    head = (Node *)malloc(sizeof(Node));
    if(NULL == head)
    {
        printf("����������󣬷���ռ�ʧ��");
        return NULL;
    }
    //����ռ�ɹ�
    head->next = NULL;
    ptr = head;
    printf("����������Ԫ�أ�����#�Ž���������\t");
    scanf(" %c", &ch);
    //while((ch = getchar()) != '#')
    while(ch != '#')
    {
        temp = (Node*)malloc(sizeof(Node));
        temp->next = NULL;//ָ����
        temp->data = ch;//������
        ptr->next = temp;//ptr����һ���ڵ�ָ��ýڵ�
        ptr = temp; //ptrָ��ýڵ㣬���ʱ��temp��nextΪNULL
        fflush(stdin);//ˢ�»�����
        printf("����������Ԫ�أ�����#�Ž���������\t");
        scanf(" %c", &ch);
    }

    return head->next;
}

//���ߺ���
void drawLine(char c)
{
    int i;
    printf("\n");
    for (i = 0; i < 70; i++)
        printf("%c", c);
    printf("\n");
}

//�����������
void printList(Linklist head)
{
    Linklist ptr;
    ptr = head;
    drawLine('-');
    printf("��������ʾ�ǣ�\n");
    while(ptr)
    {
        printf("%3c", ptr->data);
        ptr = ptr->next;
    }
    drawLine('-');
}

//�ͷ�����Ľ��ռ�
void freeList(Linklist head)
{
    Linklist temp;
    while(head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("\n ������Ľ��ռ��ͷųɹ���\n");
}

//�������в����½��
Linklist insertList(Linklist head, Linklist new, ElementType data)
{
    Linklist ptr;
    ElementType date;
    printf("��������Ҫ���������Ԫ�أ�");
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

//ɾ�������еĽ��
Linklist deleteList(Linklist head, ElementType data)
{
    Linklist ptr, prv;
    ptr = head;
    while(1)
    {
        if(ptr->next == NULL)
        {
            printf("û���ҵ���Ҫɾ��������Ԫ�أ�\n");
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


//�޸Ľ���������
Linklist modifyList(Linklist head, ElementType data)
{
    Linklist ptr;
    ElementType date;
    ptr = head;//��ptrָ��head���
    while(1)
    {
        if(ptr->next == NULL)
        {
            printf("û���ҵ���Ҫ�޸ĵ�����Ԫ�أ�\n");
            break;
        }
        else if(head->data == data)
        {
            fflush(stdin);
            printf("�����븲�� %c ������Ԫ��:", data);
            scanf(" %c", &date);
            ptr->data = date;
            fflush(stdin);
            break;
        }
        else
        {
            ptr = ptr->next;//ָ����һ�����
        }
    }
    return head;
}

//����ת��
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
        printf( "|1.���� 2.ɾ�� 3.�޸� 4.ת�� 5.�ͷ� 0 �˳� |\n" );
        printf( "+-------------------------------------------------+\n" );
        printf("����������Ҫѡ��Ĳ��� ( 0 -- 5 )��");
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
                printf("\n �����뵽�Ǹ�����Ԫ�صĺ��棺");
                scanf(" %c", &data);
                fflush(stdin);
                head = insertList(head, new, data);
                printList(head);
                break;
            case 2:
                fflush(stdin);
                printf("\n ��������Ҫɾ��������Ԫ��:");
                scanf(" %c", &data);
                fflush(stdin);
                head = deleteList(head, data);
                printList(head);
                break;
            case 3:
                fflush(stdin);
                printf("\n ����������Ҫ�޸ĵ�����Ԫ�أ�");
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
                printf("\n ���ѡ���ǷǷ��ģ�\n");
                break;
        }
    }


    return 0;
}
