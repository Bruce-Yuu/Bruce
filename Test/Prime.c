/*
***作者：Bruce Yuu
***功能：输入一个整数N，按从小到大的顺序输出小于N的所有回文素数
***返回值：若存在这样的素数，则先输出满足条件的素数的个数再按从小到大的顺序输出满足条件的数，否则输出0
***日期：2020/9/14
*/
#include<stdio.h>
#include<stdlib.h>

#define YES 0
#define NO 1
#define OVERFLOW -1

int main()
{
	int Num;
	int *Ptr;
	int Count;	//计数变量
	int iCount;	//用于统计满足条件的数的个数

	int Is_Prime(int N);
	int Is_Palindrome(int N);

	iCount = 0;

	scanf("%d", &Num);
	Ptr = (int*)malloc(Num * sizeof(int));
	if(!Ptr)
		return OVERFLOW;	//动态分配内存不成功则直接返回
	
	for(Count = 0; Count < Num; Count++)
	{
		Ptr[Count] = 0;
	}

	for(Count = 2; Count < Num; Count++)
	{
		if(!(Is_Prime(Count)) && !(Is_Palindrome(Count)))
		{
			Ptr[Count] = 1;
			iCount++;
		}
	}
	/*
	***输出满足条件的数的个数
	*/
	printf("%d ", iCount);

	/*
	***按序输出满足条件的素数
	*/
	for(Count = 0; Count < Num; Count++)
	{
		if(Ptr[Count] == 1)
			printf("%d ", Count);
	}

	printf("\n");

	return 0;
	
}

/*
***作者：Bruce Yuu
***功能：判断一个数N是否为素数
***返回值：若N为素数，返回YES,否则返回NO
***日期：2020/9/14
*/
int Is_Prime(int N)
{
	int Tmp;

	if(N == 2)
		return YES;
	else
	{
		for(Tmp = 2; Tmp < N; Tmp++)
		{
			if(N % Tmp == 0)
				return NO;
			else
				continue;
		}

		return YES;
	}
}

/*
***作者：Bruce Yuu
***功能：判断一个数N是否为回文数（注：如果一个数从左往右读与从右往左读是一样，则为回文数）
***返回值：若N为回文数，返回YES,否则返回NO
***日期：2020/9/14
*/
int Is_Palindrome(int N)
{
	int Tmp = 0;
	int Temp;

	Temp = N;

	while(Temp)
	{
		Tmp = Tmp * 10 + Temp % 10;
		Temp /= 10;
	}

	if(Tmp == N)
		return YES;
	else 
		return NO;
}