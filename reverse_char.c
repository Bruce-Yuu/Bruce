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