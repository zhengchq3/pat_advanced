#include <iostream>
using namespace std;

int edge[1000][1000] = { 0 };
int visit[1000] = { 0 };
int n, m, k;
void dfs(int node)
{
	visit[node] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == 0 && edge[node][i] == 1)
		{
			dfs(i);
		}
	}
}
int main()
{
	
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		edge[t1][t2] = 1;
		edge[t2][t1] = 1;
	}

	for (int i = 0; i < k; i++)
	{
		int city;
		cin >> city;

		int count = 0;
		for (int j = 1; j <= n; j++)
		{
			visit[j] = 0;
		}
		visit[city] = 1;
		for (int j = 1; j <= n; j++)
		{
			if (visit[j] == 0)
			{
				dfs(j);
				count++;
			}
		}
		printf("%d\n",count-1);
	}
	return 0;
}