#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <map>


//柳神版本：
struct node
{
	int id, best;
	int score[4], rank[4];
} stu[2001];
int exist[1000000] = { 0 },flag=-1;

bool cmp(node n1, node n2)
{
	return n1.score[flag] > n2.score[flag];
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> stu[i].id >> stu[i].score[1] >> stu[i].score[2] >> stu[i].score[3];
		stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) * 1.0 / 3 + 0.5;
	}
	for (flag = 0; flag < 4; flag++)
	{
		sort(stu, stu + n, cmp);
		for (int i = 0; i < n; i++)
		{
			stu[i].rank[flag] = i + 1;
			if (i > 0 && stu[i].score[flag] == stu[i - 1].score[flag])
			{
				stu[i].rank[flag] = stu[i - 1].rank[flag];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		stu[i].best = 0;
		int minn = stu[i].rank[0];
		for (int j = 1; j < 4; j++)
		{
			if (minn > stu[i].rank[j])
			{
				minn = stu[i].rank[j];
				stu[i].best = j;
			}
				
		}
		exist[stu[i].id] = i + 1;
	}
	char c[4] = { 'A','C','M','E' };

	for(int i = 0; i < m; i++)
	{
		int t;
		cin >> t;
		if (exist[t] == 0)
		{
			cout << "N/A" << endl;
		}
		else
		{
			cout << stu[exist[t] - 1].rank[stu[exist[t] - 1].best] << " " << c[stu[exist[t] - 1].best] << endl;
		}
	}
	return 0;
}
/*
class stu
{
public:
	string id;
	int c, m, e, a;
	int rc, rm, re, ra;
};

int getAverage(stu s)
{
	double temp = (s.c + s.m + s.e) * 1.0 / 3;
	//四舍五入
	int  res = temp + 0.5;
	return res;
}

bool cmpC(stu s1, stu s2)
{
	return s1.c > s2.c;
}

bool cmpM(stu s1, stu s2)
{
	return s1.m > s2.m;
}

bool cmpE(stu s1, stu s2)
{
	return s1.e > s2.e;
}
bool cmpA(stu s1, stu s2)
{
	return s1.a > s2.a;
}

void getBest(stu s)
{
	char course[4] = { 'A','C','M','E' };
	int min = s.ra;
	if (min > s.rc)
		min = s.rc;
	if (min > s.rm)
		min = s.rm;
	if (min > s.re)
	{
		min = s.re;
	}

	int index = 0;
	if (min == s.re)
		index = 3;
	if (min == s.rm)
		index = 2;
	if (min == s.rc)
		index = 1;
	if (min == s.ra)
		index = 0;
	cout << min << " " << course[index] << endl;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<stu> stus;
	map<string, int> hash1;
	for (int i = 0; i < n; i++)
	{
		stu temp;
		cin >> temp.id >> temp.c >> temp.m >> temp.e;
		hash1[temp.id] = 1;
		stus.push_back(temp);
	}
	//求平均分
	for (int i = 0; i < n; i++)
	{
		stus[i].a = getAverage(stus[i]);
	}

	sort(stus.begin(), stus.end(), cmpC);
	for (int i = 0; i < n; i++)
	{
		if (i > 0 && stus[i].c == stus[i - 1].c)
		{
			stus[i].rc = stus[i - 1].rc;
		}
		else
		{
			stus[i].rc = i + 1;
		}
	}


	sort(stus.begin(), stus.end(), cmpM);
	for (int i = 0; i < n; i++)
	{
		if (i > 0 && stus[i].m == stus[i - 1].m)
		{
			stus[i].rm = stus[i - 1].rm;
		}
		else
		{
			stus[i].rm = i + 1;
		}
	}


	sort(stus.begin(), stus.end(), cmpE);
	for (int i = 0; i < n; i++)
	{
		if (i > 0 && stus[i].e == stus[i - 1].e)
		{
			stus[i].re = stus[i - 1].re;
		}
		else
		{
			stus[i].re = i + 1;
		}
	}


	sort(stus.begin(), stus.end(), cmpA);
	for (int i = 0; i < n; i++)
	{
		if (i > 0 && stus[i].a == stus[i - 1].a)
		{
			stus[i].ra = stus[i - 1].ra;
		}
		else
		{
			stus[i].ra = i + 1;
		}
	}


	map<string, stu> hash2;
	for (int i = 0; i < stus.size(); i++)
	{
		hash2[stus[i].id] = stus[i];
	}


	for (int i = 0; i < m; i++)
	{
		string t;
		cin >> t;
		if (hash1[t] == 0)
		{
			cout << "N/A" << endl;
		}
		else
		{
			getBest(hash2[t]);
		}
	}
	return 0;
}
*/