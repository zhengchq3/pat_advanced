#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <map>

int weight[1000] = { 0 };
int order[1000] = { 0 };
int rank1[1000] = { 0 };
int res[1000] = { 0 };
int np, ng;
int count1 = 0;
map<int, int> hash1;

bool cmp(int a, int b)
{
	return a > b;
}
void dfs(vector<int> a)
{
	count1++;
	if (a.size() <= ng)
	{
		if(a.size()==1)
			rank1[hash1[a[0]]] = count1;
		else
		{
			sort(a.begin(), a.end(), cmp);
			for (int i = 1; i < a.size(); i++)
			{
				rank1[hash1[a[i]]] = count1;
			}
			count1++;
			rank1[hash1[a[0]]] = count1;
		}
		return;
	}
	vector<int> winners;
	
	int itr = 0;
	while (itr < a.size())
	{
		vector<int> temp;
		for (int i = itr; i < itr + ng&&i<a.size(); i++)
		{
			temp.push_back(a[i]);
		}
		sort(temp.begin(), temp.end(), cmp);
		winners.push_back(temp[0]);
		for (int i = 1; i < temp.size(); i++)
		{
			rank1[hash1[temp[i]]] = count1;
		}
		itr += ng;
	}
	dfs(winners);
}

int main()
{
	cin >> np >> ng;
	for (int i = 0; i < np; i++)
	{
		cin >> weight[i];
		hash1[weight[i]] = i;
	}
	for (int i = 0; i < np; i++)
	{
		cin >> order[i];
	}
	vector<int> first;
	for (int i = 0; i < np; i++)
	{
		first.push_back(weight[order[i]]);
	}
	dfs(first);
	
	int flag = 1;
	for (int i = count1; i > 0; i--)
	{
		int t = 0;
		for (int j = 0; j < np; j++)
		{
			if (rank1[j] == i)
			{
				t++;
				res[j] = flag;
			}
		}
		flag += t;
	}
	for (int i = 0; i < np; i++)
	{
		cout << res[i];
		if (i != np - 1)
			cout << " ";
	}
	return 0;
}