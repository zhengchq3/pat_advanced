#include <iostream>
using namespace std;

#include <vector>
int main()
{
	int n;
	cin >> n;
	int sum = 0;
	sum += n * 5;
	vector<int> req(n);
	for (int i = 0; i < n; i++)
	{
		cin >> req[i];
	}

	sum+=req[0]*6;
	for (int i = 1; i < n; i++)
	{
		if (req[i] > req[i - 1])
		{
			sum += (req[i] - req[i - 1]) * 6;
		}
		else
		{
			sum += (req[i-1] - req[i]) * 4;
		}
	}
	cout << sum;
	return 0;
}