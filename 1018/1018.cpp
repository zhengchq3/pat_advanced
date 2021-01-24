#include <iostream>
using namespace std;
#include <vector>
#include <stack>

int point[501] = { 0 };
int edge[501][501] = { 0 };
int w[501] = { 0 };
int main()
{
	int capacity, n, sp, m;
	cin >> capacity >> n >> sp >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> point[i];
	}
	for (int i = 0; i < m; i++)
	{
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		edge[t1][t2] = t3;
		edge[t2][t1] = t3;
	}
	vector<int> dict(n + 1, 1000000);
	vector<int> v;
	v.push_back(0);
	vector<int> hash1(n + 1, 0);
	hash1[0] = 1;
	dict[0] = 0;
	int itr = 0;
	
	while (v.size() != n+1)
	{
		for (int i = 0; i <= n; i++)
		{
			if (dict[itr] + edge[itr][i] < dict[i])
			{
				dict[i] = dict[itr] + edge[itr][i];
				w[i] = w[itr] + point[i] - capacity / 2;
			}
			else if (dict[itr] + edge[itr][i] == dict[i])
			{

			}
		}
		int minn=1000000, index;
		for (int i = 0; i <= n; i++)
		{
			if (hash1[i] == 0 && minn > dict[i])
			{
				minn = dict[i];
				index = i;
			}
		}
		hash1[index] = 1;
		itr = index;
		v.push_back(index);
	}
	cout << dict[sp] << endl;
	return 0;
}