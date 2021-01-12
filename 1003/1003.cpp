#include <iostream>
using namespace std;

#include <vector>
#include <set>

int main()
{
	int n, m, c1, c2;
	cin >> n >> m >> c1 >> c2;
	vector<int> nums(n,0);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	vector< vector <int>> roads(n,vector<int>(n));

	for (int i = 0; i < m; i++)
	{
		int t1, t2, l;
		cin >> t1 >> t2 >> l;
		roads[t1][t2] = l;
		roads[t2][t1] = l;
	}
	vector<int> u(n,100000);
	set<int> s;

	u[c1] = 0;
	s.insert(c1);
	int t = c1;;
	while (s.size() != n)
	{
		for (int i = 0; i < n; i++)
		{
			if (roads[t][i] > 0 && u[t] + roads[t][i] < u[i])
			{
				u[i] = u[t] + roads[t][i];
			}
		}
		int min1 = 100000;
		int t1;
		for (int i = 0; i < n; i++)
		{
			if (s.count(i) == 0)
			{
				if (u[i] < min1)
				{
					min1 = u[i];
					t1 = i;
				}
			}
		}

		s.insert(t1);
		t = t1;
	}
	//cout << u[c2] << endl;

	vector<int> res(n,0);
	res[c1] = nums[c1];

	int count = 0;
	vector<int> u1(n, 100000);
	set<int> s1;

	u1[c1] = 0;
	s1.insert(c1);
	t = c1;
	while (s1.size() != n)
	{
		for (int i = 0; i < n; i++)
		{
			if (roads[t][i] > 0 && u1[t] + roads[t][i] <= u1[i])
			{
				u1[i] = u1[t] + roads[t][i];
				if (res[t] + nums[i] > res[i])
					res[i] = res[t] + nums[i];
				if (i == c2 && u1[i] == u[c2])
				{
					count++;
				}
			}
		}
		int min1 = 100000;
		int t1;
		for (int i = 0; i < n; i++)
		{
			if (s1.count(i) == 0)
			{
				if (u1[i] < min1)
				{
					min1 = u1[i];
					t1 = i;
				}
			}
		}

		s1.insert(t1);
		t = t1;
	}
	cout << count << " " << res[c2] << endl;
	return 0;
}