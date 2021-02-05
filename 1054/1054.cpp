#include <iostream>
using namespace std;
#include <map>

int main()
{
	int m, n;
	cin >> m >> n;
	map<int, int> hash1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int t;
			cin >> t;
			if (hash1.find(t) == hash1.end())
			{
				hash1[t] = 1;
			}
			else
			{
				hash1[t]++;
			}
		}
	}
	auto it = hash1.begin();
	while (it != hash1.end())
	{
		if (2 * it->second > m * n)
		{
			cout << it->first;
			break;
		}
		it++;
	}
	return 0;
}