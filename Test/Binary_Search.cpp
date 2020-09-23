/*
***Auther:Bruce yuu
***Function:binnary search, not recursion
***date: 2020/9/23
*/
#include<iostream>
using namespace std;

int main()
{
	int Array[15];
	int Count;
	int Mid, Left, Right;
	int Element;

	cout << "Please input 15 integer numbers: ";
	for (Count = 0; Count < 15; Count++)
		cin >> Array[Count];
	cout << "Please input the element which is waiting for find: ";
	cin >> Element;

	Left = 0;
	Right = 14;
	Mid = (Left + Right) / 2;

	for (; Array[Mid] != Element && Left < Right;)
	{
		if (Array[Mid] < Element)
		{
			Right = Mid - 1;
		}
		if (Array[Mid] > Element)
		{
			Left = Mid + 1;
		}
		Mid = (Left + Right) / 2;
	}

	if (Array[Mid] == Element)
		cout << Element << " 's serial number is " << Mid + 1 << ".";
	else
		cout << "Sorry, the element you input is not found";

	cout << endl;
	return 0;
}
