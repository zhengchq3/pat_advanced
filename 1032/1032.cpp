#include <iostream>
#include <cstdio>
using namespace std;
#include <set>

int next1[100000] = { 0 };
char data1[100000] = { 0 };
int main()
{
	int s1, s2, n;
	cin >> s1 >> s2 >> n;
	for (int i = 0; i < n; i++)
	{
		int t1, t2;
		char c;
		cin >> t1 >> c >> t2;
		//scanf_s("%d %c %d", &t1, &c, &t2);
		data1[t1] = c;
		next1[t1] = t2;
	}
	/*方法一：双指针法*/
	/*int i = s1, j = s2;
	while (true)
	{
		if (i == j)
			break;
		else if (i == -1)
		{
			i = s2;
			j = next1[j];
		}
		else if (j == -1)
		{
			j = s1;
		}
		else
		{
			i = next1[i];
			j = next1[j];
		}
	}
	//cout << i;
	if (i == -1)
		cout << i;
	else
		printf("%05d", i);*/

	/*方法二，set集合*/
	set<int> hash1;
	int i = s1;
	while (i != -1)
	{
		hash1.insert(i);
		i = next1[i];
	}
	int flag = 0;
	int j = s2;
	while (j != -1)
	{
		if (hash1.find(j) != hash1.end())
		{
			flag = 1;
			break;
		}
		j = next1[j];
	}
	if (flag == 0)
	{
		cout << "-1";
	}
	else
	{
		printf("%05d", j);
	}
	return 0;
}