#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

bool isPrime(int num)
{
	if (num < 2)
		return false;
	if (num == 2)
		return true;
	if (num % 2 == 0)
		return false;
	for (int i = 3; i <= (int)sqrt((double)num); i += 2)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	while (cin >> n)
	{
		if (n < 0)
			break;
		int d;
		cin >> d;
		
		vector<int> num;
		bool flag = isPrime(n);
		while (n != 0)
		{
			int t = n % d;
			num.push_back(t);
			n = n / d;
		}
		int rev=0;
		reverse(num.begin(), num.end());
		int itr = 1;
		for (int i = 0; i < num.size(); i++)
		{
			rev += itr * num[i];
			itr *= d;
		}
		if (flag && isPrime(rev))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}