#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <sstream>
class record
{
public:
	string name;
	string time;
	int flag;
};
double cost[24] = { 0 };
bool cmp(record r1, record r2)
{
	if (r1.name != r2.name)
	{
		return r1.name < r2.name;
	}
	else if(r1.time!=r2.time)
	{
		return r1.time < r2.time;
	}
	else
	{
		return r1.flag < r2.flag;
	}
}

int countMinute(string t1, string t2)
{
	int res = 0;
	string day1, day2, hour1, hour2, minute1, minute2;
	day1 = t1.substr(0, 2); day2 = t2.substr(0, 2);
	hour1 = t1.substr(3, 2); hour2 = t2.substr(3, 2);
	minute1 = t1.substr(6, 2); minute2 = t2.substr(6, 2);
	stringstream ss;
	int temp1, temp2;
	ss << minute1;
	ss >> temp1;
	ss.clear();
	ss << minute2;
	ss >> temp2;
	ss.clear();
	res += temp2 - temp1;
	ss << hour1; ss >> temp1; ss.clear();
	ss << hour2; ss >> temp2; ss.clear();
	res += (temp2 - temp1) * 60;
	ss << day1; ss >> temp1; ss.clear();
	ss << day2; ss >> temp2; ss.clear();
	res += (temp2 - temp1) * 24 * 60;
	return res;
}

double countMoney(string t1, string t2)
{
	string day1, day2, hour1, hour2, minute1, minute2;
	day1 = t1.substr(0, 2); day2 = t2.substr(0, 2);
	hour1 = t1.substr(3, 2); hour2 = t2.substr(3, 2);
	minute1 = t1.substr(6, 2); minute2 = t2.substr(6, 2);

	int d1, d2, h1, h2, m1, m2;		
	stringstream ss;
	ss << minute1;ss >> m1;	ss.clear();
	ss << minute2;ss >> m2;ss.clear();
	ss << hour1; ss >> h1; ss.clear();
	ss << hour2; ss >> h2; ss.clear();
	ss << day1; ss >> d1; ss.clear();
	ss << day2; ss >> d2; ss.clear();
	double res1=0, res2=0;
	res1 += m1 * cost[h1];
	for (int i = 0; i < h1; i++)
	{
		res1 += 60 * cost[i];
	}
	for (int i = 0; i < d1 - 1; i++)
	{
		for (int j = 0; j < 24; j++)
		{
			res1 += 60 * cost[j];
		}
	}
	res2 += m2 * cost[h2];
	for (int i = 0; i < h2; i++)
	{
		res2 += 60 * cost[i];
	}
	for (int i = 0; i < d2 - 1; i++)
	{
		for (int j = 0; j < 24; j++)
		{
			res2 += 60 * cost[j];
		}
	}
	double res = res2 - res1;
	return res;
}
int main()
{
	for (int i = 0; i < 24; i++)
	{
		double t;
		cin >> t;
		cost[i]=t/100;
	}
	int n;
	cin >> n;
	vector<record> records;
	for (int i = 0; i < n; i++)
	{
		string t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		record temp;
		temp.name = t1;
		temp.time = t2;
		if (t3 == "on-line")
			temp.flag = 0;
		else
			temp.flag = 1;
		records.push_back(temp);
	}
	sort(records.begin(), records.end(), cmp);
	int month = 0;
	string m = records[0].time.substr(0, 2);
	if (m[0] == '1')
		month += 10;
	month += m[1] - '0';
	for (int i = 0; i < n; i++)
	{
		records[i].time = records[i].time.substr(3, 8);
	}
	/*for (int i = 0; i < n; i++)
	{
		cout << records[i].name << " " << records[i].time << " " << records[i].flag << endl;
	}*/
	vector<int> index;
	//index.push_back(0);
	for (int i = 1; i < n; i++)
	{
		if (records[i - 1].name != records[i].name)
			index.push_back(i);
	}
	/*for (int i = 0; i < index.size(); i++)
	{
		cout << index[i] << endl;
	}*/
	vector<vector<record> > re1;
	int itr = 0;
	for (int i = 0; i < index.size(); i++)
	{
		vector<record> temp;
		for (int j = itr; j < index[i]; j++)
		{
			temp.push_back(records[j]);
		}
		re1.push_back(temp);
		itr = index[i];
	}
	vector<record> temp;
	for (int i = itr; i < n; i++)
	{
		temp.push_back(records[i]);
	}
	re1.push_back(temp);

	vector<int> judge;
	for (int i = 0; i < re1.size(); i++)
	{
		int flag = 0;
		for (int j = 0; j < re1[i].size() - 1; j++)
		{
			if (re1[i][j].flag == 0 && re1[i][j + 1].flag == 1)
			{
				flag = 1;
				j++;
			}
		}
		judge.push_back(flag);
	}

	for (int i = 0; i < re1.size(); i++)
	{
		if (judge[i] == 0)
			continue;
		printf("%s %02d\n", re1[i][0].name.c_str(), month);
		double total = 0;
		for (int j = 0; j < re1[i].size()-1; j++)
		{
			if (re1[i][j].flag == 0 && re1[i][j + 1].flag == 1)
			{
				cout << re1[i][j].time << " " << re1[i][j + 1].time << " ";
				int minutes = countMinute(re1[i][j].time, re1[i][j + 1].time);
				cout << minutes <<" $";
				double money=countMoney(re1[i][j].time, re1[i][j + 1].time);
				printf("%.2f\n", money);
				total += money;
				j++;
			}
		}
		printf("Total amount: $%.2f\n", total);
		//cout << endl;
	}
	return 0;
}