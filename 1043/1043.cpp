#include <iostream>
using namespace std;
#include <vector>

vector<int> res;
void dfs(vector<int> a)
{
	if (a.empty())
		return;
	vector<int> left, right;
	int index = 1;
	for (int i = 1; i < a.size(); i++)
	{
		if (a[i] < a[0])
		{
			left.push_back(a[i]);
			index = i + 1;
		}
		else
		{
			index = i;
			break;
		}
	}
	for (int j = index; j < a.size(); j++)
	{
		if (a[j] >= a[0])
		{
			right.push_back(a[j]);
		}
		else
		{
			break;
		}
	}
	dfs(left);
	dfs(right);
	res.push_back(a[0]);
}

void dfs1(vector<int> a)
{
	if (a.empty())
		return;
	vector<int> left, right;
	int index = 1;
	for (int i = 1; i < a.size(); i++)
	{
		if (a[i] >= a[0])
		{
			left.push_back(a[i]);
			index = i + 1;
		}
		else
		{
			index = i;
			break;
		}
	}
	for (int j = index; j < a.size(); j++)
	{
		if (a[j] < a[0])
		{
			right.push_back(a[j]);
		}
		else
		{
			break;
		}
	}
	dfs1(left);
	dfs1(right);
	res.push_back(a[0]);
}
int main()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	dfs(nums);
	if (res.size() == n)
	{
		cout << "YES" << endl;
		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i];
			if (i != res.size() - 1)
				cout << " ";
		}
	}
	else
	{
		res.clear();
		dfs1(nums);
		if (res.size() == n)
		{
			cout << "YES" << endl;
			for (int i = 0; i < res.size(); i++)
			{
				cout << res[i];
				if (i != res.size() - 1)
					cout << " ";
			}
		}
		else
		{
			cout << "NO";
		}
	}
	return 0;
}