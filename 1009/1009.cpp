#include <iostream>
using namespace std;
#include <vector>

//柳神代码
int main()
{
	int n1, n2, cnt=0,a;
	double b, arr[2001] = { 0 }, ans[2001] = { 0 };
	cin >> n1;
	for (int i = 0; i < n1; i++)
	{
		cin >> a >> b;
		arr[a] = b;
	}
	cin >> n2;
	for (int i = 0; i < n2; i++)
	{
		cin >> a >> b;
		for (int j = 0; j < 2001; j++)
		{
			if (arr[j] != 0)
			{
				ans[a + j] += arr[j] * b;
			}
		}
	}
	for (int i = 0; i < 2001; i++)
	{
		if (ans[i] != 0)
			cnt++;
	}
	cout << cnt;
	for (int i = 2000; i >= 0; i--)
	{
		if (ans[i] != 0)
		{
			printf(" %d %.1f", i, ans[i]);
		}
	}
	return 0;
}
//我的做法
/*
double hash1[2001] = { 0 };
class poly
{
public:
	int n;
	double an;
};
int main()
{
	int k1,k2;
	cin >> k1;
	
	vector<poly> a,b;

	for (int i = 0; i < k1; i++)
	{
		poly t;
		cin >> t.n >> t.an;
		a.push_back(t);
	}

	cin >> k2;
	for (int i = 0; i < k2; i++)
	{
		poly t;
		cin >> t.n >> t.an;
		b.push_back(t);
	}
	for (int i = 0; i < k1; i++)
	{
		for (int j = 0; j < k2; j++)
		{
			hash1[a[i].n + b[j].n] += a[i].an*b[j].an;
		}
	}
	int count = 0;
	for (int i = 0; i < 2001; i++)
	{
		if (hash1[i] != 0)
			count++;
	}
	cout << count << " ";
	for (int i = 2000; i >= 0; i--)
	{
		if (hash1[i] != 0)
		{
			cout << i<<" ";
			printf("%.1f", hash1[i]);
			count--;
			if (count > 0)
				cout << " ";
		}
	}
	return 0;
}
*/