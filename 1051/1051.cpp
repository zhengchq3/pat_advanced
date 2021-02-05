#include <iostream>
using namespace std;
#include <vector>
#include <stack>

int m, n, k;
int a[1000] = { 0 };
bool flag = false;
void judge()
{
	stack<int> b;
	int index = 0;
	for (int i = 1; i <= n; i++)
	{
		if (b.size() >= m)
			break;
		b.push(i);
		while (!b.empty()&&b.top() == a[index])
		{
			b.pop();
			index++;
		}
	}
	if (index == n)
		flag = true;
	else
		flag = false;
}
int main()
{
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[j];
		}
		judge();
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}