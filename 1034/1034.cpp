#include <iostream>
using namespace std;
#include <set>
#include <vector>
#include <map>
#include <algorithm>
class phone
{
public:
	string name1;
	string name2;
	int length;
};

int count1 = 0;
int id[2000] = { 0 };
int visit[2000] = { 0 };
int num = 0;
int edge[2000][2000] = { 0 };

void dfs(int node)
{
	visit[node] = 1;
	id[node] = count1;
	for (int i = 0; i < num; i++)
	{
		if (visit[i] == 0 && edge[node][i] > 0)
		{
			dfs(i);
		}
	}
}
class gang
{
public:
	int boss;
	string name;
	vector<int> members;
};

bool cmp(gang g1, gang g2)
{
	return g1.name < g2.name;
}
int main()
{
	int n, k;
	cin >> n >> k;
	vector<phone> phones(n);
	set<string> names;
	for (int i = 0; i < n; i++)
	{
		cin >> phones[i].name1 >> phones[i].name2>>phones[i].length;
		names.insert(phones[i].name1);
		names.insert(phones[i].name2);
	}
	auto it = names.begin();
	vector<string> names1;
	while (it != names.end())
	{
		names1.push_back(*it);
		it++;
	}

	map<string, int> hash1;
	for (int i = 0; i < names1.size(); i++)
	{
		hash1[names1[i]] = i;
	}

	
	for (int i = 0; i < phones.size(); i++)
	{
		int t1 = hash1[phones[i].name1];
		int t2 = hash1[phones[i].name2];
		edge[t1][t2] += phones[i].length;
		edge[t2][t1] += phones[i].length;
	}
	num = names1.size();
	for (int i = 0; i < num; i++)
	{
		if (visit[i] == 0)
		{
			dfs(i);
			count1++;
		}
	}
	vector<int> res1;
	for (int i = 0; i < count1; i++)
	{
		int temp = 0;
		for (int j = 0; j < num; j++)
		{
			if (id[j] == i)
				temp++;
		}
		if (temp > 2)
			res1.push_back(i);
	}
	vector<int> res2;
	for (int i = 0; i < res1.size(); i++)
	{
		int sum = 0;
		for (int j = 0; j < num; j++)
		{
			if (id[j] == res1[i])
			{
				for (int k = 0; k < num; k++)
				{
					sum += edge[j][k];
				}
			}
		}
		sum /= 2;
		if (sum > k)
			res2.push_back(res1[i]);
	}
	cout << res2.size() << endl;
	vector<gang> gangs;
	for (int i = 0; i < res2.size(); i++)
	{
		vector<int> temp;
		gang g;
		for (int j = 0; j < num; j++)
		{
			if (id[j] == res2[i])
			{
				temp.push_back(j);
			}
		}
		int max = 0;
		for (int j = 0; j < temp.size(); j++)
		{
			int sum = 0;
			for (int k = 0; k < num; k++)
			{
				sum += edge[temp[j]][k];
			}
			if (sum > max)
				max = sum;
		}

		for (int j = 0; j < temp.size(); j++)
		{
			int sum = 0;
			for (int k = 0; k < num; k++)
			{
				sum += edge[temp[j]][k];
			}
			if (sum == max)
			{
				g.boss = temp[j];
				break;
			}
		}

		g.members = temp;
		g.name = names1[g.boss];
		gangs.push_back(g);
	}
	sort(gangs.begin(), gangs.end(), cmp);
	for (int i = 0; i < gangs.size(); i++)
	{
		cout << gangs[i].name << " " << gangs[i].members.size() << endl;
	}
	return 0;
}