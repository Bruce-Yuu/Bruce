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