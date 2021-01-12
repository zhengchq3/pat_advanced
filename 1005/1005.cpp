#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>
#include <sstream>

string eng[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
int main()
{
	string num;
	cin >> num;

	int sum = 0;
	for (int i = 0; i < num.length(); i++)
	{
		sum += num[i] - '0';
	}
	stringstream ss;
	string res;
	ss << sum;
	ss >> res;
	cout << eng[res[0] - '0'];
	for (int i = 1; i < res.size(); i++)
	{
		cout << " " << eng[res[i] - '0'];
	}
	/*if (sum == 0)
	{
		cout << "zero";
		return 0;
	}
	vector<string> res;
	while (sum != 0)
	{
		res.push_back(eng[sum % 10]);
		sum /= 10;
	}
	reverse(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
		if (i != res.size() - 1)
		{
			cout << " ";
		}
	}*/

	return 0;
}