#include <iostream>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int n1 = str.length() + 2;
	n1 /= 3;
	int n2 = str.length() + 2 - 2 * n1;
	for (int i = 0; i < n1-1; i++)
	{
		cout << str[i];
		for (int j = 0; j < n2 - 2; j++)
		{
			cout << " ";
		}
		cout << str[str.length() - 1 - i] << endl;
	}
	for (int i = n1 - 1; i < n1 + n2 - 1; i++)
	{
		cout << str[i];
	}
	return 0;
}