#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class record
{
public:
	string id;
	string name;
	int grade;
};

bool cmp1(record t1, record t2)
{
	return t1.id < t2.id;
}

bool cmp2(record t1, record t2)
{
	if (t1.name != t2.name)
	{
		return t1.name < t2.name;
	}
	else
	{
		return t1.id < t2.id;
	}
}

bool cmp3(record t1, record t2)
{
	if (t1.grade != t2.grade)
	{
		return t1.grade < t2.grade;
	}
	else
	{
		return t1.id < t2.id;
	}
}

int main()
{
	int n, c;
	cin >> n >> c;
	vector<record> records;
	for (int i = 0; i < n; i++)
	{
		record temp;
		cin >> temp.id >> temp.name >> temp.grade;
		records.push_back(temp);
	}
	if (c == 1)
	{
		sort(records.begin(), records.end(), cmp1);
	}
	else if (c == 2)
	{
		sort(records.begin(), records.end(), cmp2);
	}
	else
	{
		sort(records.begin(), records.end(), cmp3);
	}
	for (int i = 0; i < n; i++)
	{
		cout << records[i].id << " " << records[i].name << " " << records[i].grade << endl;
	}
	return 0;
}