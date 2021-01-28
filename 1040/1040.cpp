#include <iostream>
using namespace std;
#include <string>
int main()
{
	string s;
	getline(cin, s);

	int len = s.length();
	int maxLen = 1;
	for (int i = 0; i < s.length(); i++)
	{
		int j = i + 1;
		if (j == s.length())
			break;
		if (s[i] == s[j])
		{
			int temp = 0;
			for (int k = 1; k < s.length(); k++)
			{
				if (j + k > s.length() - 1 || i - k < 0)
					break;
				if (s[i - k] == s[j + k])
				{
					if (j - i + 1 + 2 * k > maxLen)
						maxLen = j - i + 1 + 2 * k;
				}
				else
				{
					break;
				}
			}

		}
		else
		{
			if (j != s.length() - 1)
			{
				j++;
				if (s[i] == s[j])
				{
					int temp = 0;
					for (int k = 1; k < s.length(); k++)
					{
						if (j + k > s.length() - 1 || i - k < 0)
							break;
						if (s[i - k] == s[j + k])
						{
							if (j - i + 1 + 2 * k > maxLen)
								maxLen = j - i + 1 + 2 * k;
						}
						else
						{
							break;
						}
					}
				}
			}
		}
	}
	cout << maxLen;
	return 0;
}