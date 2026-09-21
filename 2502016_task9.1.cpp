#include <iostream>
using namespace std;
int main()
{
	int matrix[3][3];
	cout << "Enter elements of 3 x 3 matrix:" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> matrix[i][j];
		}
	}
	cout << "\nMatrix:" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	return 0;
}
