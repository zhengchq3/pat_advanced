#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>
int main()
{
	int n, k;
	cin >> n >> k;
	map<string, vector<int> > hash1;
	for (int i = 0; i < k; i++)
	{
		int index, num;
		cin >> index >> num;
		for (int j = 0; j < num; j++)
		{
			string name;
			cin >> name;
			if (hash1.find(name) != hash1.end())
			{
				hash1[name].push_back(index);
			}
			else
			{
				vector<int> temp;
				temp.push_back(index);
				hash1[name] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		cout << name<<" ";
		if (hash1.find(name) == hash1.end())
		{
			cout << "0" << endl;;
		}
		else
		{
			cout << hash1[name].size();
			sort(hash1[name].begin(), hash1[name].end());
			for (int j = 0; j < hash1[name].size(); j++)
			{
				//cout << " " << hash1[name][j];
				printf(" %d", hash1[name][j]);
			}
			cout << endl;
		}
	}
	return 0; 
}