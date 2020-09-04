#include<stdio.h>

int main()
{
    int integer;
    int Count_Bit_One = 0;
    
    scanf("%d", &integer);
    /*
    ***计算出该int型数据在内存中存储时1的个数.***
    */
    while(integer)
    {
        if(integer % 2 == 1)
            Count_Bit_One++;
        integer = integer / 2;
    }
    
    printf("%d", Count_Bit_One);
}