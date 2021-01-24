#include <iostream>
using namespace std;
#include <vector>

int main()
{
	int n1, n2;
	cin >> n1;
	vector<int> s1(n1, 0);
	for (int i = 0; i < n1; i++)
	{
		cin >> s1[i];
	}
	cin >> n2;
	vector<int> s2(n2, 0);
	for (int i = 0; i < n2; i++)
	{
		cin >> s2[i];
	}
	int i = 0, j = 0;
	int stop = n1 + n2;
	if (stop % 2 == 0)
	{
		stop /= 2;
	}
	else
	{
		stop++;
		stop /= 2;
	}
	int res;
	while (i + j < stop)
	{
		if (i < n1 && j < n2 && s1[i] < s2[j])
		{
			res = s1[i];
			i++;
		}
		else if (i < n1 && j<n2 && s1[i]>s2[j])
		{
			res = s2[j];
			j++;
		}
		else if (i >= n1)
		{
			res = s2[stop - n1 - 1];
			break;
		}
		else
		{
			res = s1[stop - n2 - 1];
			break;
		}
	}
	cout << res << endl;
	return 0;
}