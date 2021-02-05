#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class person
{
public:
	int come;
	int process;
};

bool cmp(person p1, person p2)
{
	return p1.come < p2.come;
}
int main()
{
	int n, k;
	cin >> n >> k;
	vector<person> persons;
	for (int i = 0; i < n; i++)
	{
		int hour, min, sec, t;
		scanf("%d:%d:%d %d", &hour, &min, &sec, &t);
		if (hour > 17 || (hour == 17 && min > 0) || (hour == 17 && sec > 0))
			continue;
		person p;
		p.come = hour * 3600 + min * 60 + sec;
		p.process = t * 60;
		persons.push_back(p);
	}

	sort(persons.begin(), persons.end(), cmp);
	vector<int> windows;
	for (int i = 0; i < k; i++)
	{
		windows.push_back(28800);
	}
	int sum = 0;
	for (int i = 0; i < persons.size(); i++)
	{
		sort(windows.begin(), windows.end());
		if (windows[0] > 61200)
		{
			sum += 61200 - persons[i].come;
		}
		else
		{
			if (persons[i].come < windows[0])
			{
				sum += windows[0] - persons[i].come;
				windows[0] += persons[i].process;
			}
			else
			{
				windows[0] = persons[i].come + persons[i].process;
			}
		}
	}
	double res = sum * 1.0 / (persons.size() * 60);
	printf("%.1f", res);
	return 0;
}