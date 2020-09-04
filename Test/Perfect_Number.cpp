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