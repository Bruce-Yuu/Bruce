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