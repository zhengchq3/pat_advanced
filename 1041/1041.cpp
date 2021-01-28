#include <iostream>
using namespace std;
#include <vector>

int hash1[10001] = { 0 };
int main()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
		hash1[nums[i]]++;
	}
	int res = -1;
	for (int i = 0; i < n; i++)
	{
		if (hash1[nums[i]] == 1)
		{
			res = nums[i];
			break;
		}
	}
	if (res == -1)
	{
		cout << "None";
	}
	else
	{
		cout << res;
	}
	return 0;
}