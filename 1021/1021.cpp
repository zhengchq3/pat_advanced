#include <iostream>
using namespace std;
#include <vector>
#include <set>

int n;
//vector<vector<int> > edge(n + 1, vector<int>(n + 1, 0));
int edge[10001][10001] = { 0 };
int hash1[10001] = { 0 };
int count1;


void dfs(int node)
{
	hash1[node] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (hash1[i] == 0 && edge[node][i] == 1)
		{
			dfs(i);
		}
	}
}

int hash2[10001] = { 0 };
int maxDepth = 0;
vector<int> temp;
set<int> res;
void dfs1(int node,int depth)
{
	hash2[node] = 1;
	depth++;
	if (depth > maxDepth)
	{
		maxDepth = depth;
		temp.clear();
		temp.push_back(node);
	}
	else if (depth == maxDepth)
	{
		temp.push_back(node);
	}
	for (int i = 1; i <= n; i++)
	{
		if (hash2[i] == 0 && edge[node][i] == 1)
		{
			dfs1(i,depth);
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		edge[t1][t2] = 1;
		edge[t2][t1] = 1;
	}
	count1 = 0;
	for (int i = 1; i <= n; i++)
	{
		if (hash1[i] == 0)
		{
			dfs(i);
			count1++;
		}
	}
	if (count1 > 1)
	{
		cout << "Error: " << count1 << " components";
	}
	else
	{
		dfs1(1, 0);
		for (int i = 0; i < temp.size(); i++)
		{
			res.insert(temp[i]);
		}
		maxDepth = 0;
		for (int i = 1; i <= n; i++)
		{
			hash2[i] = 0;
		}
		int t = temp[0];
		temp.clear();
		dfs1(t, 0);
		for (int i = 0; i < temp.size(); i++)
		{
			res.insert(temp[i]);
		}
		
		auto itr = res.begin();
		while (itr != res.end())
		{
			printf("%d\n", *itr);
			itr++;
		}
	}
	return 0;
}