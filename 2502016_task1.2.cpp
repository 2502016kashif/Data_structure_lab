#include<iostream>
using namespace std;
int main()
{
	int marks_of_students[8];
	int total=0;
	int average;
	int higest;
	int lowest;
	for(int i = 0;i<=7;i++)
	{
		cout<<"entre marks of student no "<<i+1<<" :";
		cin>>marks_of_students[i];
	}
	higest=marks_of_students[0];
	lowest=marks_of_students[0];
	for(int i = 0;i<=7;i++)
	{
		total+=marks_of_students[i];
	if(higest<marks_of_students[i])
	{
		higest=marks_of_students[i];
	}
	if(lowest>marks_of_students[i])
	{
		lowest=marks_of_students[i];
	}
	}
	average = total/8;
	cout<<"the total of 8 student is :"<<total<<endl;
	cout<<"the average of 8 student is :"<<average<<endl;
	cout<<"the higest of 8 student is :"<<higest<<endl;
	cout<<"the lowest of 8 student is :"<<lowest<<endl;
	return 0;
}
