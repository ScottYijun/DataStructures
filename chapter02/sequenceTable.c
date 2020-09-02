#include "stdio.h"
#include "conio.h"

#define MaxSize 50                  //定义线性表可能达到的最大长度

typedef char ElementType;

typedef struct node
{
    ElementType data[MaxSize];      //动态分配的一维数组
    int length;                     //当前长度
}SeqList, *list;

//初始化顺序表
void InitList(list l)
{
    l->length = 0;
}

//顺序表长度
int LengthList(list l)
{
    return l->length;
}
int length(list l)
{
    return l->length;
}

//获取顺序表的第i个结点的值
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

//查找x在顺序表中的位置
int LocationList(list l, ElementType x)
{
    int i = 0;
    while(i < l->length && l->data[i] != x)
        i++;
    if(i == l->length)
        return -1;                          //没找到数据
    else
        return (i + 1);
}

//向顺序表插入数据
void InsertList(list l, int pos, ElementType x)
{
    //printf(" InsertList===pos = %d, x = %c\n", pos, x);
    int j;
    if(pos < 1 || pos > l->length + 1)
        printf("insert error\n");
    else
    {
        l->length++;                        //顺序表长度加1
        for(j = l->length; j >= pos; j--)
            l->data[j] = l->data[j - 1];    //pos位置后面的数据都往后移动一个位置
        l->data[pos - 1] = x;               //把x插入到pos位置，
    }
}

//删除顺序表中的结点
void DeleteNode(list l, int pos)
{
    int j;
    if(pos < 1 || pos > l->length)
        printf("delete error\n");
    else
    {
        for(j = pos; j < l->length; j++)
            l->data[j - 1] = l->data[j];    //pos位置后面的数据都往前移一个位置
        l->data[l->length - 1] = '\0';      //最后一个元素置空
        l->length--;                        //顺序表的长度减1
    }
}

//输出顺序表
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
    printf("\n\n\n *************************顺序表演示程序***********\n");
    printf(" 请输入你想建立的顺序表的元素，以？结束:");
    ch=getchar();

    while(ch != '?')
    {
        InsertList(&l, i, ch);
        i++;
        ch = getchar();
    };

    printf(" 你建立的顺序表为:");
    print(&l);
    printf("\n 顺序表的长度为:%d", l.length);
    printf("\n 输入你想查找的元素：");
    fflush(stdin); //vs2017不支持

    scanf(" %c", &x);
    printf(" 你查找的元素为%c序位为%d", x, LocationList(&l, x));

    printf("\n 输入你想查找的元素序位:");
    scanf(" %d", &n);
    printf("\n 你查找的元素为：%c", GetNode(&l, n));
    printf("\n 输入你想插入的元素以及序位:<用逗号隔开>:");

    scanf(" %c,%d", &x, &n);
    InsertList(&l, n, x);
    printf("\n 插入后顺序表为：");
    print(&l);
    fflush(stdin);
    printf("\n 请输入你想删除的元素序位：");
    scanf(" %d", &n);

    DeleteNode(&l, n);
    printf("\n 删除后的顺序表为：");
    print(&l);
    printf("\n 线性表的顺序存储的基本运算操作完毕，谢谢使用!");
    return 0;
}


//备注：
//scanf(" %d", &n); scanf函数前面加一个空格的原因是删除缓冲区的第一个字符是回车符或者空格符
//因为前面输入的字符fflush(stdin);并不有起来清空的作用，所以运行时就直接读取缓冲区的回画符了。
//这个和编译器有关系
//运行平台，win10   QT5.13.1 VS2017
//参考链接：
//https://blog.csdn.net/lrgy_zhch/article/details/6268386
//https://blog.csdn.net/weixin_45677047/article/details/104755732
//https://blog.csdn.net/fxwzzbd/article/details/2514042
//https://blog.csdn.net/jonathanlin2008/article/details/5026895

