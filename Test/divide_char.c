/*
***连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组；
***长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_INPUT 100
#define OUTPUT_ARRAY_LENGTH 208

int main()
{
    int *Source_One;
    int *Source_Two;
    int Dest[OUTPUT_ARRAY_LENGTH] = {0};
    int Source_One_Leng = 0;
    int Source_Two_Leng = 0;

    int Read_String(int *String);
    void Divide_Char(int *Dest, int *Source, int Length_Of_Source);

    Source_One = (int *)malloc(MAX_INPUT*sizeof(int));
    if(!Source_One)
        exit(1);

    Source_Two = (int *)malloc(MAX_INPUT*sizeof(int));
    if(!Source_Two)
        exit(1);

    Source_One_Leng = Read_String(Source_One);
    Source_Two_Leng = Read_String(Source_Two);
    Divide_Char(Dest, Source_One, Source_One_Leng);
    Divide_Char(Dest, Source_Two, Source_Two_Leng);

    return 0;
}

/*
***依次读入字符串，当输入结束或输入长度大于100时就结束读入***
*/
int Read_String(int *String)
{
    int Count = 0;

    while(Count < MAX_INPUT && (*(String + Count) = getchar()) != EOF && *(String + Count) != '\n')
    {
            Count++;
        
    }
    *(String + Count) = '\0';

    return Count;
}

/*
***按长度8对输入字符串进行分割，长度不足8用0补齐，空字符不处理***
*/
void Divide_Char(int *Dest, int *Source, int Length_Of_Source)
{
    int Count = 0;
    int Quotient = 0;    //商
    int Remainder = 0;    //余数

    if(!Source)
        exit(1);

    if(!(Length_Of_Source % 8))
    {
        for(Count = 0; Count < Length_Of_Source;)
        {
            putchar(*(Dest + Count) = *(Source + Count));
            Count++;
            if(!(Count % 8))
                printf("\n");
        }
    }
    else
    {
        Quotient = Length_Of_Source / 8;
        Remainder = Length_Of_Source % 8;
        for(Count = 0; Count < Quotient * 8;)
        {
            putchar(*(Dest + Count) = *(Source + Count));
            Count++;
            if(!(Count % 8))
                printf("\n");
        }
        for(Count; Count < Length_Of_Source; Count++)
            putchar(*(Dest + Count) = *(Source + Count));
        for(Count; Count < Length_Of_Source + 8 - Remainder; Count++)
            {
                printf("%d", *(Dest + Count) = 0);
            }
        printf("\n");
    }
}
