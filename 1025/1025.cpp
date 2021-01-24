#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class testee
{
public:
	string regis;
	int score;
	int location;
	int local_rank;
	int final_rank;
};

bool cmp(testee t1, testee t2)
{
	if (t1.score != t2.score)
	{
		return t1.score > t2.score;
	}
	else
	{
		return t1.regis < t2.regis;
	}
}
int main()
{
	int n;
	cin >> n;
	vector<testee> total;
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		vector<testee> local;
		for (int j = 0; j < k; j++)
		{
			string t;
			int score;
			cin >> t >> score;
			testee test;
			test.regis = t;
			test.score = score;
			test.location = i;
			local.push_back(test);
		}
		sort(local.begin(),local.end(),cmp);
		local[0].local_rank = 1;
		for (int j = 1; j < k; j++)
		{
			local[j].local_rank = j + 1;
			if (local[j].score == local[j - 1].score)
				local[j].local_rank = local[j - 1].local_rank;
		}
		for (int j = 0; j < k; j++)
		{
			total.push_back(local[j]);
		}
	}
	sort(total.begin(), total.end(), cmp);
	total[0].final_rank = 1;
	for (int i = 1; i < total.size(); i++)
	{
		total[i].final_rank = i + 1;
		if (total[i].score == total[i - 1].score)
			total[i].final_rank = total[i - 1].final_rank;
	}
	cout << total.size() << endl;
	for (int i = 0; i < total.size(); i++)
	{
		cout << total[i].regis << " " << total[i].final_rank << " ";
		cout << total[i].location << " " << total[i].local_rank << endl;
	}
	return 0;
}