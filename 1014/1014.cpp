#include <iostream>
using namespace std;
#include <queue>
#include <vector>
class node
{
public:
	int poptime;
	int endtime;
	queue<int> line;
	node()
	{
		poptime = 0;
		endtime = 0;
	}
};
int main()
{
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	vector<int> time(k+1);
	for (int i = 1; i <= k; i++)
	{
		cin >> time[i];
	}
	int index = 1;
	vector<node> windows(n);
	vector<int> result(k + 1);
	vector<int> sorry(k + 1);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (index <= k)
			{
				if (i == 0)
					windows[j].poptime = time[index];
				windows[j].line.push(index);
				if (windows[j].endtime >= 540)
					sorry[index] = 1;
				windows[j].endtime += time[index];
				result[index] = windows[j].endtime;
				index++;
			}
		}
	}

	while (index <= k)
	{
		int mint = windows[0].poptime;
		int j=0;
		for (int i = 1; i < n; i++)
		{
			if (windows[i].poptime < mint)
			{
				mint = windows[i].poptime;
				j = i;
			}
		}
		if (windows[j].endtime >= 540)
		{
			sorry[index] = 1;
		}
		else {
			windows[j].line.pop();
			windows[j].poptime += time[windows[j].line.front()];
			windows[j].endtime += time[index];
			result[index] = windows[j].endtime;
			windows[j].line.push(index);
		}
		index++;
	}

	for (int i = 0; i < q; i++)
	{
		int t;
		cin >> t;
		if (sorry[t])
		{
			cout << "Sorry" << endl;
		}
		else
		{
			int hour = result[t] / 60+8;
			int minute = result[t] % 60;
			printf("%02d:%02d\n", hour, minute);
		}
	}
	return 0;
}