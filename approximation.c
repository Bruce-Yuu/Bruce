#include<stdio.h>
int main()
{
    /*
    ***接受一个正浮点数值，输出该数值的近似整数值。如果小数点后数值大于等于5,向上取整；小于5，则向下取整。***
    */
    float real;
    int integer;
    
    scanf("%f", &real);
    
    if((real - (int)(real)) >= 0.5)
        printf("%d", (int)(real) + 1);
    else
        printf("%d", (int)(real));
    
    return 0;
}