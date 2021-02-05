#include <iostream>
using namespace std;

int num[15] = { 0 };
int main()
{
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		num[i] = s[i] - '0'+1;
	}
	int res = 0;
	for (int i = s.length()-1; i >=0 ; i--)
	{
		int itr = 1;
		for (int j = s.length() - 1; j >= 0; j--)
		{
			if (j != i)
			{
				itr *= num[j];
			}
		}
		res += itr;
		num[i]--;
	}
	cout << res;
	return 0;
}