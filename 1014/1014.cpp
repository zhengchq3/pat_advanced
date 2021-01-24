#include <iostream>
using namespace std;
#include <queue>

int process[1001] = { 0 };
int done[1001] = { 0 };//第i个顾客业务完成需要多少分钟，从8点开始
queue <int> window[20];

int main()
{
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	for (int i = 1; i <= k; i++)
	{
		cin >> process[i];
	}

	int time = 0;
	while (true)
	{
		time++;

	}
	for (int i = 0; i < q; i++)
	{
		int c;
		cin >> c;

	}
	return 0;
}