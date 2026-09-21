#include<iostream>
using namespace std;
int main()
{
	int arr[10];
	cout<<"entre 10 number :"<<endl;
	for(int i = 0;i<=9;i++)
	{
		cout<<"entre number "<<i+1<<" :";
		cin>>arr[i];
	}
	for(int i = 0;i<=9;i++)
	{
		if(arr[i]%2==0)
		{
			cout<<"index no  "<<i<<" is even :"<<arr[i]<<endl;
		}
		else{
		cout<<"index no  "<<i<<" of array is odd :"<<arr[i]<<endl;
	}
	}
	return 0;
}
