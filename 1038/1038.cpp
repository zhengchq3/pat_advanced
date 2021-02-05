#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

bool cmp(string s1, string s2)
{
	return s1 + s2 < s2 + s1;
}

int main()
{
	int n;
	cin >> n;
	vector<string> segs(n);
	for (int i = 0; i < n; i++)
	{
		cin >> segs[i];
	}

	sort(segs.begin(), segs.end(), cmp);
	string res = "";
	for (int i = 0; i < n; i++)
	{
		res += segs[i];
	}
	int count = 0;
	for (int i = 0; i < res.length(); i++)
	{
		if (res[i] == '0')
		{
			count++;
		}
		else
		{
			break;
		}
	}
	if (count == res.length())
	{
		cout << "0";
	}
	else if (count == 0)
	{
		cout << res;
	}
	else
	{
		res = res.substr(count, res.length() - count);
		cout << res;
	}
	return 0;
}