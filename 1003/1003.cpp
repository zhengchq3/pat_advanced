#include <iostream>
using namespace std;
#include <vector>
#include <map>

int num[500] = { 0 };
int w[500] = { 0 };
int edge[500][500] = { 0 };
int point[500] = { 0 };

int main()
{
	int n,m,c1,c2;
	cin >> n >> m >> c1 >> c2;
	
	for (int i = 0; i < n; i++)
	{
		cin >> point[i];
	}

	for (int i = 0; i < m; i++)
	{
		int t1, t2, l;
		cin >> t1 >> t2 >> l;
		edge[t1][t2] = l;
		edge[t2][t1] = l;
	}
	


	vector<int> dis(n, 100000);
	int count = 1;
	map<int, int> hash1;
	hash1[c1] = 1;
	dis[c1] = 0;
	w[c1] = point[c1];
	num[c1] = 1;

	int itr = c1;
	while (count < n)
	{
		for (int i = 0; i < n; i++)
		{
			if (edge[itr][i] != 0)
			{
				if (dis[itr] + edge[itr][i] < dis[i])
				{
					dis[i] = dis[itr] + edge[itr][i];
					num[i] = num[itr];
					w[i] = w[itr]+point[i];
				}else if (dis[itr] + edge[itr][i] == dis[i])
				{
					num[i] += num[itr];
					if (w[itr] + point[i] > w[i])
						w[i] = w[itr] + point[i];
				}
			}
		}

		int minn = 100000;
		for (int i = 0; i < n; i++)
		{
			if (hash1[i] == 0 && minn > dis[i])
			{
				minn = dis[i];
				itr = i;
			}
		}
		hash1[itr] = 1;
		count++;
		//cout << itr << " " << num[c2] << endl;
	}
	cout << num[c2] << " " << w[c2];
	return 0;
}