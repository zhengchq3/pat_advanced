#include <iostream>
using namespace std;
#include <vector>

int main()
{
	int n, m;
	cin >> n;
	vector<int> dis(n + 2);
	int sum = 0;
	for (int i = 2; i <= n+1; i++)
	{
		int t;
		cin >> t;
		sum += t;
		dis[i] = sum;
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		if (t1 > t2)
		{
			int t = t1;
			t1 = t2;
			t2 = t;
		}
		int res = dis[t2] - dis[t1];
		if (2 * res > dis[n + 1])
		{
			res = dis[n + 1] - res;
		}
		cout << res << endl;
	}
	return 0;
}