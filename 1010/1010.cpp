#include <iostream>
using namespace std;

long long getSum(int radix, string s)
{
	long long num = 0;
	long long itr = 1;
	for (int i = 0; i < s.length(); i++)
	{
		int t;
		if (s[s.length() - 1 - i] >= '0' && s[s.length() - 1 - i] <= '9')
		{
			t = s[s.length() - 1 - i] - '0';
		}
		else
		{
			t = s[s.length() - 1 - i] - 'a' + 10;
		}
		num += t * itr;
		itr *= radix;
		if (num < 0 || itr < 0)
			return -1;
	}
	return num;
}

long long findLo(string s)
{
	long long max = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			if (s[i] - '0' > max)
			{
				max = s[i] - '0';
			}
		}
		else
		{
			if (s[i] - 'a' + 10 > max)
			{
				max = s[i] - 'a' + 10;
			}
		}
	}
	return max + 1;
}

int main()
{
	string n1, n2;
	int tag, radix;
	cin >> n1 >> n2 >> tag >> radix;

	//raidx是n1的基数
	if (tag == 2)
	{
		string temp = n1;
		n1 = n2;
		n2 = temp;
	}

	long long num = getSum(radix, n1);

	int rad1 = 2;
	bool flag = false;

	long long lo = findLo(n2), hi = max(num, lo);
	while (lo <= hi)
	{
		long long temp = getSum((lo + hi) / 2, n2);
		if (temp == num)
		{
			flag = true;
			rad1 = (lo + hi) / 2;
			break;
		}
		else if (temp<0 || temp>num)
		{
			hi = (lo + hi) / 2 - 1;
		}
		else
		{
			lo = (lo + hi) / 2 + 1;
		}

	}
	if (flag)
		cout << rad1;
	else
		cout << "Impossible";
	return 0;
}