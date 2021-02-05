#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*Ë«Ö¸Õë·¨*/
/*
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	int i = 0, j = n - 1;
	while (i < j)
	{
		if (nums[i] + nums[j] == m)
			break;
		else if (nums[i] + nums[j] < m)
		{
			i++;
		}
		else
		{
			j--;
		}
	}
	if (i!=j&&nums[i] + nums[j] == m)
	{
		cout << nums[i] << " "<<nums[j];
	}
	else
	{
		cout << "No Solution";
	}
	return 0;
}
*/

/*¹þÏ£·¨*/
int hash1[1001] = { 0 };
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		hash1[t]++;
	}
	int flag = 0;
	for (int i = 1; i < m; i++)
	{
		if (hash1[i])
		{
			hash1[i]--;
			if (hash1[m - i])
			{
				cout << i << " " << m - i;
				flag++;
				break;
			}
		}
	}
	if (flag == 0)
	{
		cout << "No Solution";
	}
	return 0;
}