#include <iostream>
using namespace std;
#include <vector>

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> chain(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> chain[i];
		//scanf("%d", &chain[i]);
	}

	int count = 0;
	int minn = -1;
	vector<vector<int> > res;
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		int j = i;
		for (; j <= n; j++)
		{
			sum += chain[j];
			if (sum >= m)
				break;
		}
		if (sum == m)
		{
			cout << i << "-" << j << endl;
			//printf("%d-%d\n", i, j);
			count++;
		}
		if (sum > m)
		{
			if (minn == -1)
			{ 
				minn = sum;
				vector<int> temp;
				temp.push_back(i);
				temp.push_back(j);
				res.push_back(temp);
			}
			else
			{
				if (sum < minn)
				{
					minn = sum;
					res.clear();
					vector<int> temp;
					temp.push_back(i);
					temp.push_back(j);
					res.push_back(temp);
				}
				else if (sum==minn)
				{
					vector<int> temp;
					temp.push_back(i);
					temp.push_back(j);
					res.push_back(temp);
				}
			}
		}
	}
	if (count == 0)
	{
		/*for (int i = 1; i <= n; i++)
		{
			int sum = 0;
			int j = i;
			for (; j <= n; j++)
			{
				sum += chain[j];
				if (sum >= minn)
					break;
			}
			if (sum == minn)
			{
				//cout << i << "-" << j << endl;
				printf("%d-%d\n", i, j);
			}
		}*/
		for (int i = 0; i < res.size(); i++)
		{
			//printf("%d-%d\n", res[i][0], res[i][1]);
			cout << res[i][0]<<"-" << res[i][1] << endl;
		}
	}
	return 0;
}