#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 5000

//��ȡ����
int Read(char Dest[])
{
	int Count = 0;

	while (Count < MAX_LEN && (Dest[Count] = getchar()) != EOF)
	{
		Count++;
	}

	return Count - 1;
}

//�������һ�����ʳ���
int Cal_Length_Of_Last_Word(char Source[], int Max)
{
	int Count = Max;

	while (Count > 0)
	{
		Count--;
		if (Source[Count] == ' ' || Source[Count] == '\n' || Source[Count] == '\t')
		{
			return Max - Count - 1;
		}
	}

	return Max;
}

int main()
{
	char Source[MAX_LEN] = { 0 };
	int Read_Number = 0;
	int Last_Word_Length = 0;

	Read_Number = Read(Source);
	Last_Word_Length = Cal_Length_Of_Last_Word(Source, Read_Number);
	printf("%d\n", Last_Word_Length);

	return 0;
}