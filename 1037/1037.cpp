#include <iostream>
using namespace std;
#include<vector>
#include <algorithm>

bool cmp1(int n1, int n2)
{
	return n1 > n2;
}

bool cmp2(int n1, int n2)
{
	return n1 < n2;
}

int main()
{
	int n1, n2;
	cin >> n1;
	vector<int> nums1, nums2, nums3, nums4;
	for (int i = 0; i < n1; i++)
	{
		int t;
		cin >> t;
		if (t > 0)
		{
			nums1.push_back(t);
		}
		else if (t < 0)
		{
			nums2.push_back(t);
		}
	}
	cin >> n2;
	for (int i = 0; i < n2; i++)
	{
		int t;
		cin >> t;
		if (t > 0)
		{
			nums3.push_back(t);
		}
		else if (t < 0)
		{
			nums4.push_back(t);
		}
	}

	sort(nums1.begin(), nums1.end(), cmp1);
	sort(nums3.begin(), nums3.end(), cmp1);
	sort(nums2.begin(), nums2.end(), cmp2);
	sort(nums4.begin(), nums4.end(), cmp2);

	long long res = 0;
	int i = 0;
	while (i < nums1.size() && i < nums3.size())
	{
		res += nums1[i] * nums3[i];
		i++;
	}
	i = 0;
	while (i < nums2.size() && i < nums4.size())
	{
		res += nums2[i] * nums4[i];
		i++;
	}

	cout << res;
	return 0;
}