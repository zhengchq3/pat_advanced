#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int main()
{
	int n, b;
	cin >> n >> b;
	if (n == 0)
	{
		cout << "Yes\n0";
		return 0;
	}
	vector<int> nums;
	while (n != 0)
	{
		int t = n % b;
		nums.push_back(t);
		n /= b;
	}
	vector<int> temp(nums);
	reverse(nums.begin(), nums.end());
	int flag = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != temp[i])
			flag = 1;
	}
	if (flag == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i];
		if(i!=nums.size()-1)
			cout<< " ";
	}
	return 0;
}