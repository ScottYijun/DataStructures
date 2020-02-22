#include <stdio.h>

#define LEN 100

int main()
{
    int n, j;
    int num1, num2, chr1, chr2;
    char chr[LEN], temp[LEN];
    printf("please input the string:");//输入需要加密的字符串
    fgets(chr, LEN, stdin); //获取字符串，gets函数在已经过期了
    printf("\nthe string is:%s", chr);
    printf("\nplease input num2(1<=num2<=26)");
    scanf_s("%d", &num2);
    printf("\nplease input num1(1<=num1<=26)");
    scanf_s("%d", &num1);
    j = 0;
    while('\0' != chr[j])
    {
        if((chr[j] >= 'A') && (chr[j] <= 'Z'))
        {
            chr1 = 91 -chr[j];//转换后得到的小写字母在字母表中的顺序号
            if((chr1 - num2) < 0)
                temp[j] = 187 - chr[j] - num2 + 26;//逆序转换且循环起始的小写字母
            else
                temp[j] = 187 - chr[j] - num2;//否则，得到按逆序转换的相应小写字母
        }
        else if((chr[j] >= 'a') && (chr[j] < 'z'))
        {
            chr2 = 123 - chr[j];
            if((chr2 - num1) < 0)
                temp[j] = 187 - chr[j] - num1 + 26;
            else
                temp[j] = 187 - chr[j] - num1;
        }

        ++j;
    }

    n = j;
    //保存字符串的长度
    printf("\nthe result string:");//输出加密后的结果
    for(j = 0; j < n; ++j)
        putchar(temp[j]);
    printf("\n");

    return 0;
}
