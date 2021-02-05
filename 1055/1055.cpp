#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class person
{
public:
	string name;
	int age;
	int worth;
};

bool cmp(person p1, person p2)
{
	if (p1.worth != p2.worth)
	{
		return p1.worth > p2.worth;
	}
	else if (p1.age != p2.age)
	{
		return p1.age < p2.age;
	}
	else
	{
		return p1.name < p2.name;
	}
}

int hash1[201] = { 0 };
int main()
{
	int n, k;
	cin >> n >> k;
	vector<person> persons(n),p;
	for (int i = 0; i < n; i++)
	{
		cin >> persons[i].name >> persons[i].age >> persons[i].worth;
	}
	sort(persons.begin(), persons.end(), cmp);

	for (int i = 0; i < n; i++)
	{
		if (hash1[persons[i].age] < 100)
		{
			p.push_back(persons[i]);
			hash1[persons[i].age]++;
		}
	}


	for (int i = 1; i <= k; i++)
	{
		int m, minn, maxx;
		cin >> m >> minn >> maxx;
		cout << "Case #" << i << ":" << endl;
		int flag = 0;
		for (int j = 0; j < p.size(); j++)
		{
			if (p[j].age >= minn && p[j].age <= maxx && flag < m)
			{
				cout << p[j].name << " " << p[j].age << " " << p[j].worth << endl;
				flag++;
			}
		}
		if (flag == 0)
		{
			cout << "None" << endl;
		}
	}
	return 0;
}