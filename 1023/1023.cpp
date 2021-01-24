#include <iostream>
using namespace std;
#include <vector>

int main()
{
	string num;
	cin >> num;
	int count1[10] = { 0 };
	for (int i = 0; i < num.size(); i++)
	{
		count1[num[i] - '0']++;
	}

	int count2[10] = { 0 };
	vector<int> res;
	int c = 0;//½øÎ»
	for (int i = 0; i < num.size(); i++)
	{
		int temp = num[num.size()-1-i] - '0';
		temp = 2*temp+c;
		res.push_back(temp%10);
		c = temp / 10;
	}
	if (c != 0)
		res.push_back(c);
	for (int i = 0; i < res.size(); i++)
	{
		count2[res[i]]++;
	}
	int flag = 0;
	for (int i = 0; i < 10; i++)
	{
		if (count1[i] != count2[i])
			flag = 1;
	}
	if (flag == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[res.size()-1-i];
	}
	return 0;
}