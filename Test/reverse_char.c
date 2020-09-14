/*
***写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。（字符串长度不超过1000）
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LENGTH 1000

int main()
{
    char *String;
    int Count_Char = 0;
    int Count = 0;
    
    String = (char*)malloc(MAX_LENGTH * sizeof(char));
    if(!String)
        exit(1);
    
    while(Count_Char < MAX_LENGTH - 1 && (*(String + Count_Char) = getchar()) != '\n')
    {
        Count_Char++;
    }
    Count = Count_Char - 1;
    while(Count >= 0)
    {
        putchar(*(String + Count));
        Count--;
    }

    return 0;
}