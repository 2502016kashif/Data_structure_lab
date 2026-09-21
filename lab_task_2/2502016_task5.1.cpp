#include <iostream>
using namespace std;
int main()
{
	int arr[10];
	int n, position, value;
	
	cout << "Enter number of elements: ";
	cin >> n;
	cout << "Enter " << n << " elements:" << endl;
	for (int i = 0; i < n; i++)
	{
	cin >> arr[i];
	}
	cout << "Enter insertion position (0 to " << n << "): ";
	cin >> position;
	cout << "Enter value to insert: ";
	cin >> value;
	if (position < 0 || position > n)
	{
		cout << "Invalid position!" << endl;
	}
	else
	{
		for (int i = n; i > position; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[position] = value;
		n++;
		cout << "\nArray after insertion:" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
	}
	return 0;
}
