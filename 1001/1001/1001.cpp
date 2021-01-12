#include <iostream>
using namespace std;

#include <sstream>
#include <string>
int main()
{
	int a, b;
	cin >> a >> b;
	a += b;
	stringstream ss;
	ss << a;
	string res;
	ss >> res;
	//cout << res << endl;
	string temp = "";
	for (int i = 1; i <= res.length(); i++)
	{
		temp = res[res.length() - i] + temp;
		if (i % 3 == 0 && i != res.length() - 1 && i != res.length())
			temp = "," + temp;
		else if (i % 3 == 0 && i == res.length() - 1&&res[0]!='-')
		{
			temp = "," + temp;
		}
	}
	cout << temp;
	system("pause");
	return 0;
}