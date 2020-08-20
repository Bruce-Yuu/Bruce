#include<stdio.h>
#include<string.h>

int main()
{
    char Input[] = {0};
    char Ch;
    int Count = 0;
    int Count_Ch = 0;

    /*
    ***读取字符串，如果读到换行符就停止***
    */
    while((Input[Count] = getchar()) != '\n')
        Count += 1;
    
    /*
    ***读入一个字符Ch***
    */
    scanf("%c", &Ch);

     /*
    ***统计输入字符串中字符Ch出现的次数***
    */
    for(; Count >= 0; Count--)
    {
        if(Input[Count] >= 'a' && Input[Count] <= 'z')
        {
            if(Ch == Input[Count] || Ch == Input[Count] - 32)
                Count_Ch++;
        }
        else if(Input[Count] >= 'A' && Input[Count] < 'Z')
        {
            if(Ch == Input[Count] || Ch == Input[Count] + 32)
                Count_Ch++;
        }
    }

    printf("%d\n", Count_Ch);
    return 0;
}