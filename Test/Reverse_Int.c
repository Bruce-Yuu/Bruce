/*
***输入一个整数，将这个整数以字符串的形式逆序输出
***程序不考虑负数的情况，若数字含有0，则逆序形式也
***含有0，如输入为100，则输出为001
*/
#include<stdio.h>

void main()
{
    int Number;
    
    scanf("%d",&Number);
    
    while(Number)
    {
        printf("%d", Number % 10);
        Number = Number / 10;
    }
}