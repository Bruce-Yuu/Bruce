#include<stdio.h>
#include<stdlib.h>
#define MAX_INPUT 1000

void main()
{
    int Count = 0;
    int Input_Array[MAX_INPUT] = {0};
    int Output_Array[MAX_INPUT] = {0};
    int Rand_Number = 0;
    void Sort(int *Dest, int Max);
    void Delete_Repeat(int *Source, int Max, int *Dest);
    /*
    ***输入需要读入的随机数的个数,如果大于1000则直接退出***
    */
    scanf("%d", &Rand_Number);
    if(Rand_Number > MAX_INPUT)
        exit(1);
    
    for(Count = 0; Count < Rand_Number; Count++)
    {
        scanf("%d", &Input_Array[Count]);
        printf("\n");
    }

    Sort(Input_Array, Rand_Number);
    Delete_Repeat(Input_Array, Rand_Number, Output_Array);

    for(Count = 0; Count < Rand_Number; Count++)
    {
	if(Output_Array[Count] == 1)
        	printf("%d\n", Count);
    }
}

/*
***采用冒泡排序法进行排序***
*/
void Sort(int *Dest, int Max)
{
    int Inner_Count = 0;
    int Out_Count = 0;
    int Exchange = 0;   //置换标记，如果发生了交换则置1，未发生交换则置0，默认未发生交换。一趟排序未发生交换表明排序已完成。
    int tmp = 0;

    for (Out_Count = 0; Out_Count < Max; Out_Count++)
    {
        for(Inner_Count = 0; Inner_Count < Max - Out_Count - 1; Inner_Count++)
        {
            if(Dest[Inner_Count] > Dest[Inner_Count + 1])
            {
                tmp = Dest[Inner_Count];
                Dest[Inner_Count] = Dest[Inner_Count + 1];
                Dest[Inner_Count + 1] = tmp;
                
                Exchange = 1;
            }
        }

        if(Exchange == 0)
            break;
    }
}

/*
***去除重复数字***
*/
void Delete_Repeat(int *Source, int Max, int *Dest)
{
    int Count = 0;

    for(Count = 0; Count < Max; Count++)
    {
        Dest[Source[Count]] = 1;
    }
}
