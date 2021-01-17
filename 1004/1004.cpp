#include <iostream>
using namespace std;

#include <vector>
#include <map>

int main()
{
	int n, m;
	cin >> n >> m;
	map<int, vector<int>> hash1;
	for (int i = 0; i < m; i++)
	{
		int id, k;
		cin >> id >> k;
		vector<int> temp(k);
		for (int j = 0; j < k; j++)
		{
			cin >> temp[j];
		}
		hash1[id] = temp;
	}

	vector<int> itr;
	itr.push_back(1);
	vector<int> res;
	while (itr.size() != 0)
	{
		int count = 0;
		vector<int> temp;
		for (int i = 0; i < itr.size(); i++)
		{
			if (hash1.find(itr[i])==hash1.end())//(hash1.count(itr[i]) == 0)//用find会大大减少时间
			{
				count++;
			}
			else
			{
				for (int j = 0; j < hash1[itr[i]].size(); j++)
				{
					temp.push_back(hash1[itr[i]][j]);
				}
			}
		}
		itr = temp;
		res.push_back(count);
	}
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
		if (i != res.size() - 1)
			cout << " ";
	}
	return 0;
}