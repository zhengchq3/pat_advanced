#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>

bool cmp(string s1, string s2)
{
	return s1 < s2;
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<string> names(n);
	map<int, vector<string> > hash1;
	for (int i = 0; i < n; i++)
	{
		cin >> names[i];
		int t;
		cin >> t;
		for (int j = 0; j < t; j++)
		{
			int c;
			cin >> c;
			if (hash1.find(c) == hash1.end())
			{
				vector<string> temp;
				temp.push_back(names[i]);
				hash1[c] = temp;
			}
			else
			{
				hash1[c].push_back(names[i]);
			}
		}
	}
	for (int i = 1; i <= k; i++)
	{
		cout << i << " ";
		if (hash1.find(i) == hash1.end())
		{
			cout<<"0"<<endl;
		}
		else
		{
			cout << hash1[i].size() << endl;
			sort(hash1[i].begin(), hash1[i].end(), cmp);
			for (int j = 0; j < hash1[i].size(); j++)
			{
				cout << hash1[i][j] << endl;
			}
		}
	}
	return 0;
}