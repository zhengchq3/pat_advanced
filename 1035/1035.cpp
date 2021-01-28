#include <iostream>
using namespace std;
#include <vector>

class user
{
public:
	string name;
	string password;
};
bool judge(string p)
{
	for (int i = 0; i < p.size(); i++)
	{
		if (p[i] == '1' || p[i] == 'l' || p[i] == '0' || p[i] == 'O')
			return true;
	}
	return false;
}

void change(string& p)
{
	for (int i = 0; i < p.size(); i++)
	{
		if (p[i] == '1')
		{
			p[i] = '@';
		}
		else if (p[i] == 'l')
		{
			p[i] = 'L';
		}
		else if (p[i] == '0')
		{
			p[i] = '%';
		}
		else if (p[i] == 'O')
		{
			p[i] = 'o';
		}
	}
}
int main()
{
	int n;
	cin >> n;
	vector<user> users;
	for (int i = 0; i < n; i++)
	{
		string name, password;
		cin >> name >> password;
		if (judge(password))
		{
			change(password);
			user temp;
			temp.name = name;
			temp.password = password;
			users.push_back(temp);
		}
	}
	if (users.empty() && n == 1)
	{
		cout << "There is 1 account and no account is modified";
	}
	else if (users.empty() && n != 1)
	{
		cout<<"There are "<<n<<" accounts and no account is modified";
	}
	else
	{
		cout << users.size() << endl;
		for (int i = 0; i < users.size(); i++)
		{
			cout << users[i].name << " " << users[i].password << endl;
		}
	}
	return 0;
}