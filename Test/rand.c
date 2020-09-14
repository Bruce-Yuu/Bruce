/*
***明明想在学校中请一些同学一起做一项问卷
***调查，为了实验的客观性，他先用计算机生
***成了N个1到1000之间的随机整数（N≤1000），
***对于其中重复的数字，只保留一个，把其余
***相同的数去掉，不同的数对应着不同的学生
***的学号。然后再把这些数从小到大排序，按
***照排好的顺序去找同学做调查。请你协助明
***明完成“去重”与“排序”的工作(同一个测试
***用例里可能会有多组数据，希望大家能正确
***处理)。
*/
#include<stdio.h>

int main()
{
    int Rand_Number;
    int Input_Array[1001];
    int Count, Num;
    
    while(scanf("%d",&Rand_Number)!=EOF)
    {
        for(Count=0;Count<1001;Count++)
            Input_Array[Count]=0;
        while(Rand_Number--)
        {
            scanf("%d",&Num);
            Input_Array[Num]++;
        }
        for(Count=0; Count<1001; Count++)
            if(Input_Array[Count]!=0)
                printf("%d\n",Count);
    }
    return 0;
}