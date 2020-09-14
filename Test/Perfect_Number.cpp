/*
***完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。

***它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。

***例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1+2+4+7+14=28。

***给定函数count(int n),用于计算n以内(含n)完全数的个数。计算范围, 0 < n <= 500000

***返回n以内完全数的个数
*/
#include<iostream>
using namespace std;

int main()
{
    long Range, Count, Inner;
    int Sum, Count_Perfect = 0;
    
    cin >> Range;
    
    for(Count = 2; Count <= Range; Count++)
    {
        Sum = 0;
        for(Inner = 1; Inner < Count; Inner++)
        {
            if(Count % Inner == 0)
                Sum += Inner;
        }
        if(Sum == Count)
            Count_Perfect++;
    }
    
    cout << Count_Perfect << endl;
    
    return 0;
}