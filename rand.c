#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//排序，采用冒泡排序法
void Sort(int Dest[], int Count)
{
	int Inner_Count = 0;
	int Out_Count = 0;
	int tmp = 0;
	int ExChange = 0;   //交换标记，为0表示未发生交换，为1表示发生交换，默认为0，表示未发生交换

	for(Out_Count = 0; Out_Count < Count - 1; Out_Count++)
	{
		ExChange = 0;
		for (Inner_Count = 0; Inner_Count < Count - 1 - Out_Count; Inner_Count++)
		{
			if (Dest[Inner_Count] > Dest[Inner_Count + 1])
			{
				tmp = Dest[Inner_Count + 1];
				Dest[Inner_Count + 1] = Dest[Inner_Count];
				Dest[Inner_Count] = tmp;
				ExChange = 1;
			}
		}
		if(ExChange == 0)
		{
			break;
		}
	}
}

//去重
int Del_Repeat(int Dest[], int Count)
{
	int Inner_Count = 0;
	int Out_Count = 0;
	int After_Count = Count;
	int Repeat_Count = 0;
	int Repeat_Number[] = {0};
	int Mid_Count = 0;

	printf("重复的数字有：");
	for(Out_Count = 0; Out_Count < Count - 1; Out_Count++)
	{
		for(Inner_Count = Out_Count + 1; Inner_Count < Count - 1 - Out_Count; Inner_Count++)
		{
			if (Dest[Inner_Count] == Dest[Out_Count])
			{
				printf("%d\t", Dest[Inner_Count]);
				Mid_Count = Inner_Count;
				for (Mid_Count; Mid_Count < Count - 1; Mid_Count++)
				{
					Dest[Mid_Count] = Dest[Mid_Count + 1];
				}
				After_Count--;
			}
		}
	}

	printf("\n");

	return After_Count;
}

int main()
{
	srand((unsigned)time(NULL));
	int Array_Element_Number = 0;
	int *Array = NULL;
	int Count = 0;
	int Array_Count = 0;

	printf("请输入要生成的随机数个数：");
	scanf("%d", &Array_Element_Number);
	printf("\n");

	Array = (int*)malloc(Array_Element_Number * sizeof(int));
	if (!Array)
	{
		printf("内存分配失败，程序异常退出！");
		return -1;
	}

	for(Count = 0; Count < Array_Element_Number; Count++)
	{
		*(Array + Count) = rand() % 1000 + 1;;
	}

	printf("输出原数组：\n");
	for (Count = 0; Count < Array_Element_Number;)
	{
		printf("%d\t", *(Array + Count));
		Count++;
		if (Count % 10 == 0)
			printf("\n");
	}
	printf("\n");

	Sort(Array, Array_Element_Number);
	printf("输出排序后的数组：\n");
	for (Count = 0; Count < Array_Element_Number;)
	{
		printf("%d\t", *(Array + Count));
		Count++;
		if (Count % 10 == 0)
			printf("\n");
	}
	printf("\n");

	Array_Count = Del_Repeat(Array, Array_Element_Number);
	printf("输出排序去重后的数组：\n");
	for(Count = 0; Count < Array_Count;)
	{
		printf("%d\t", *(Array + Count));
		Count++;
		if (Count % 10 == 0)
			printf("\n");
	}

	printf("\n");

	return 0;
}
