#include <iostream>
using namespace std;
#include <string>

int hash1[300] = { 0 };
int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	for (int i = 0; i < s2.length(); i++)
	{
		hash1[s2[i]]++;
	}
	for (int i = 0; i < s1.length(); i++)
	{
		if (hash1[s1[i]] == 0)
		{
			cout << s1[i];
		}
	}
	return 0;
}