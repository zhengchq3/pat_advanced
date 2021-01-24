#include <iostream>
using namespace std;

bool judge(string n)
{
	if (n.length() == 1)
		return true;
	for (int i = 0; i < (int)n.length() / 2; i++)
	{
		if (n[i] != n[n.length() - 1 - i])
			return false;
	}
	return true;
}

string reverse(string n)
{
	string res = n;
	for (int i = 0; i < n.length(); i++)
	{
		res[n.length() - 1 - i] = n[i];
	}
	return res;
}

string addStr(string n1, string n2)
{
	string res = n1;
	int c = 0;
	for (int i = 0; i < n1.length(); i++)
	{
		int temp = n1[n1.length() - 1 - i] - '0' + n2[n2.length() - 1 - i] - '0' + c;
		res[n1.length() - 1 - i] = '0' + temp % 10;
		c = temp / 10;
	}
	if (c > 0)
	{
		string t = "0";
		t[0] += c;
		res = t + res;
	}
	return res;
}
int main()
{
	string n;
	int k;
	cin >> n >> k;
	int flag = 0;
	for (int i = 0; i < k; i++)
	{
		if (judge(n))
		{
			flag = i;
			break;
		}
		string rev = reverse(n);
		n = addStr(rev, n);
		if (judge(n))
		{
			flag = i+1;
			break;
		}
	}
	if (judge(n))
	{
		cout << n << endl;
		cout << flag << endl;;
	}
	else
	{
		cout << n << endl;
		cout << k << endl;
	}
	return 0;
}