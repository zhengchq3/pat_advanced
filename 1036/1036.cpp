#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string male="", female="";
	string id1 = "", id2 = "";
	int grade1 = 101,grade2 = -1;
	for (int i = 0; i < n; i++)
	{
		string name, id;
		char gender;
		int grade;
		cin >> name >> gender >> id >> grade;
		if (gender == 'M')
		{
			if (grade < grade1)
			{
				grade1 = grade;
				male = name;
				id1 = id;
			}
		}
		else
		{
			if (grade > grade2)
			{
				grade2 = grade;
				female = name;
				id2 = id;
			}
		}
	}

	if (grade1 == 101&&grade2==-1)
	{
		cout << "Absent" << endl;
		cout << "Absent" << endl;
		cout << "NA" << endl;
	}
	else if (grade1 != 101 && grade2 == -1)
	{
		cout << "Absent" << endl;
		cout << male <<" "<< id1 << endl;
		cout << "NA" << endl;
	}
	else if (grade1 == 101 && grade2 != -1)
	{
		cout << female <<" "<< id2 << endl;
		cout << "Absent" << endl;
		cout << "NA" << endl;
	}
	else
	{
		cout << female <<" "<< id2 << endl;
		cout << male << " "<<id1 << endl;
		cout << grade2 - grade1 << endl;

	}
	return 0;
}