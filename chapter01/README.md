

1．一个函数输入一组数据存入一维数组中，数据元素的个数和数据值的输入都在这个函数中完成；编写算法求这组数据的最大值、最小值，并通过函数参数返回。
【算法描述】
根据本题意，需要将函数中变化的形式参数的值反映在实际参数中，就可以通过引用参数调用的形式。而在 C语言的实现中，就可以通过指针变量作形式参数，接受变量的地址，达到“传地址”的目的。以下有两个问题，用类 C 语言描述算法，然后写出对应的完整的源程序。

![image](https://github.com/ScottYijun/DataStructures/blob/master/chapter01/example1.png)

2.字符加密的问题
【问题描述】
字符串加密的方法是：
(1) 如果字符是小写字母 a～z，假设转换成相应逆序的大写字母 Z～A；
(2) 如果字符是大写字母 A～Z，假设转换成相应逆序的小写字母 z～a；
(3) 为了提高字符加密的可靠性和灵活性，可以给每个字母的 ASCII 值加一个大于等于 0 且小于 26 的一个数字。
根据字符加密的方法，实际上是大小写字母间的逆序相互转换和数字与数字之间的逆序转换问题，在此基础上为每个字母的 ASCII 值加一个大于等于 0 且小于 26 的一个数字，例如，增加 5，输入字符串“ace”，加密后转换成“USQ”输出；输入字符串“ACE”，加密后转换成“usq”输出。
【算法描述】
针对本题意，对于大小写字母的逆序转换其算法可以分为两步完成。
(1) 可以先求出小写字母与其相对应的逆序大写字母或者大写字母与其相对应的逆序小写字母。大、小写字母 A～Z、a～z 与其逆序的相应大、小写字母的 ASCII 码值的和都是 187，比如 a 的 ASCII 值为 97，Z 的 ASCII 值为 90，其和为 187；再如 X 的 ASCII 值为88，c 的 ASCII 值为 99，其和为 187；依次类推。
(2) 求出(1)中得到的大、小写字母在其字母表中的顺序号。例如输入的文本为“ace”，按逆序转换的方式，得到文本“ZXV”，其中 Z、X、V 在大写逆序字母表中的顺序号为 1、3、5。分别取大写逆序字母表中序号 1、3 和 5，即为大写字母表 Z、X、V。
(3) 再考虑在已经求出的顺序号基础上分别按大写逆序增加 Num1、小写逆序增加Num2 的位移，得到新的顺序号。例如 Num1=6，则不是把小写字母 a 转换成大写字母 Z，而是把 a 转换成大写字母表中 T。但必须考虑如果“序号＋Num1”大于 26，则应将新的顺序号对 26 求余。

![image](https://github.com/ScottYijun/DataStructures/blob/master/chapter01/example2.png)



3.打印100-999之间所有的“水仙花数”。“水仙花数”是一个三位数，其各位数立方和等于该数本身。
例如153是“水仙花数”，因为：153 = 13 + 53 + 33。 

![image](https://github.com/ScottYijun/DataStructures/blob/master/chapter01/example3.png)


4.打印下列图案
      *
      ***
      *****
      ***
      *


![image](https://github.com/ScottYijun/DataStructures/blob/master/chapter01/example4.png)


5.写一个判断素数的函数，在主函数输入一个整数，输出是否素数的信息。

![image](https://github.com/ScottYijun/DataStructures/blob/master/chapter01/example5.png)

6.有一数组存放了 10 个数，编写程序，把这 10 个数倒序后再存放到原数组中。
编程提示：
可在数组头与尾分别设两个指示变量，把头、尾指示变量所指数据交换位置后，头后移一个位置，尾前移一个位置，直到头位置大于尾位置为止。

![image](https://github.com/ScottYijun/DataStructures/blob/master/chapter01/example6.png)

7.输入 10 个数，对这 10 个数按从小到大排序输出。
编程提示：
可采用冒泡排序法，其基本思路是从头扫描待排序数据，在扫描过程中不断将相邻两个数据中值大的后移，最后将最大的值放在最后，再次从头扫描，找出次大数放在倒数第二单元中，依次类推。

![image](https://github.com/ScottYijun/DataStructures/blob/master/chapter01/example7.png)

