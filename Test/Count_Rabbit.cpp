/*
***有一只兔子，从出生后第3个月起每个月都生一只
***兔子，小兔子长到第三个月后每个月又生一只兔子，
***假如兔子都不死，问每个月的兔子总数为多少？
*/
#include<iostream>
using namespace std;

int main()
{
    int Month;
    int Total_Count;
    int Get_Total_Count(int Month);
    
    while(cin >> Month)
    {
        Total_Count = Get_Total_Count(Month);
        cout << Total_Count << endl;
    }
    
    return 0;
}

int Get_Total_Count(int Month)
{
    int Total;
        
    if(Month == 1 || Month == 2)
        Total = 1;
    else
        Total = Get_Total_Count(Month - 2) + Get_Total_Count(Month - 1);
    
    return Total;
}