#include <iostream>
using namespace std;
int main()
{
	int arr[10];
	int n, position;
	cout << "Enter number of elements: ";
	cin >> n;
	cout << "Enter " << n << " elements:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << "Enter deletion position (0 to "<< n - 1 << "): ";
	cin >> position;
	if (position < 0 || position >= n)
	{
		cout << "Invalid position!" << endl;
	}
	else
	{
		for (int i = position; i < n - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		n--;
		cout << "\nArray after deletion:" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
	}
	return 0;
}
