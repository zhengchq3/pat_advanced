#include <iostream>
using namespace std;

#include <vector>
int main()
{
	int k;
	cin >> k;
	vector<int> nums(k);
	int flag = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> nums[i];
		if (nums[i] >= 0)
		{
			flag = 1;
		}
	}
	if (flag == 0)
	{
		cout << "0" << " " << nums[0] << " " << nums[k - 1];
		return 0;
	}
	vector<int> dp(nums);
	for (int i = 1; i < k; i++)
	{
		if (dp[i - 1] > 0)
			dp[i] += dp[i - 1];
	}
	int max = 0;
	for (int i = 0; i < k; i++)
	{
		if (dp[i] > max)
		{
			max = dp[i];
		}
	}
	int index = 0;
	for (int i = 0; i < k; i++)
	{
		if (dp[i] == max)
		{
			index = i;
			break;
		}
	}
	if (max == 0)
	{
		cout << "0 0 0";
		return 0;
	}
	int start = index - 1;
	int temp = max-nums[index];
	while (temp != 0)
	{
		if (start < 0)
			break;
		temp -= nums[start];
		start--;
	}
	start++;
	cout << max << " " << nums[start] << " " << nums[index];
	return 0;
}