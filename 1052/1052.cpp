#include <iostream>
using namespace std;
#include <map>
#include <vector>
#include <algorithm>

//有可能有无效的节点
//最后一个测试点：如果所有节点都无效，要输出0 -1

int data1[100000] = { 0 };
int next1[100000] = { 0 };
int main()
{
	int n, start;
	cin >> n >> start;
	map<int, int> hash1;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		data1[a] = b;
		next1[a] = c;
		hash1[b] = a;
	}
	vector<int> keys;
	while (start != -1)
	{
		keys.push_back(data1[start]);
		start = next1[start];
	}
	sort(keys.begin(), keys.end());
	if (keys.size() == 0)
	{
		cout << "0 -1";
		return 0;
	}
	printf("%d %05d\n", keys.size(), hash1[keys[0]]);
	for (int i = 0; i < keys.size(); i++)
	{
		printf("%05d %d ", hash1[keys[i]], keys[i]);
		if (i != keys.size() - 1)
		{
			printf("%05d\n", hash1[keys[i + 1]]);
		}
		else
			printf("-1");
	}
	return 0;
}