#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <algorithm>
class person
{
public:
	string id;
	string signIn;
	string signOut;
};
bool cmp1(person p1, person p2)
{
	return p1.signIn < p2.signIn;
}
bool cmp2(person p1, person p2)
{
	return p1.signOut > p2.signOut;
}
int main()
{
	int m;
	cin >> m;
	vector<person> pers;
	for (int i = 0; i < m; i++)
	{
		person p;
		cin >> p.id>>p.signIn>>p.signOut;
		pers.push_back(p);
	}
	sort(pers.begin(), pers.end(), cmp1);
	cout << pers[0].id<<" ";
	sort(pers.begin(), pers.end(), cmp2);
	cout << pers[0].id  ;
	
	return 0;
}