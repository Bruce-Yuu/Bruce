#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
	int Row, Col;
	int Count;
	int Array[11][11];
	
	Count = 11;
	Array[11][11] = { 0 };

	for (Row = 1; Row < Count; Row++)
	{
		for (Col = 1; Col <= Row; Col++)
		{
			if (Col == 1 || Row == Col)
				Array[Row][Col] = 1;
			else
				Array[Row][Col] = Array[Row - 1][Col] + Array[Row - 1][Col - 1];
		}
	}

	for (Row = 1; Row < Count; Row++)
	{
		for (Col = 1; Col <= Row; Col++)
		{
			cout << Array[Row][Col] << "\t";
		}
		cout << endl;
	}

	cout << endl;
	return 0;
}
