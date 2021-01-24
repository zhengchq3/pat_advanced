#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>


vector<string> getKeywords(string s)
{
	vector<string> res;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ')
		{
			int len = 0;
			int start = i;
			for (int j = i; j < s.length(); j++)
			{
				if (s[j] != ' ')
				{
					len++;
					if (j == s.length() - 1)
					{
						i = j;
						break;
					}
				}else{
					i = j;
					break;
				}
			}
			string temp=s.substr(start,len);
			res.push_back(temp);
		}
		
	}
	return res;
}
int main()
{
	int n;
	cin >> n;
	string t;
	getline(cin, t);
	int id[10000] = { 0 };
	map<string, vector<int> > title;
	map<string, vector<int> > author;
	map<string, vector<int> > keyword;
	map<string, vector<int> > publisher;
	map<string, vector<int> > year;
	for (int i = 0; i < n; i++)
	{
		
		getline(cin, t);
		stringstream ss;
		ss << t;
		ss >> id[i];
		ss.clear();

		getline(cin, t);
		if (title.find(t) == title.end())
		{
			vector<int> index;
			index.push_back(i);
			title[t] = index;
		}
		else
		{
			title[t].push_back(i);
		}

		getline(cin, t);
		if (author.find(t) == author.end())
		{
			vector<int> index;
			index.push_back(i);
			author[t] = index;
		}
		else
		{
			author[t].push_back(i);
		}

		getline(cin, t);
		vector<string> keywords = getKeywords(t);
		for (int j = 0; j < keywords.size(); j++)
		{
			//cout << keywords[j] << endl;
			if (keyword.find(keywords[j]) == keyword.end())
			{
				vector<int> index;
				index.push_back(i);
				keyword[keywords[j]] = index;
			}
			else
			{
				keyword[keywords[j]].push_back(i);
			}
		}
		getline(cin, t);
		if (publisher.find(t) == publisher.end())
		{
			vector<int> index;
			index.push_back(i);
			publisher[t] = index;
		}
		else
		{
			publisher[t].push_back(i);
		}
		getline(cin, t);
		if (year.find(t) == year.end())
		{
			vector<int> index;
			index.push_back(i);
			year[t] = index;
		}
		else
		{
			year[t].push_back(i);
		}
	}
	int m;
	cin >> m;
	getline(cin, t);
	for (int i = 0; i < m; i++)
	{
		vector<int> res;
		getline(cin, t);
		cout << t << endl;
		string query;
		if (t[0] == '1')
		{
			query = t.substr(3, t.length() - 3);
			if (title.find(query) == title.end())
			{
				cout << "Not Found" << endl;
			}
			else
			{
				for (int j = 0; j < title[query].size(); j++)
				{
					res.push_back(id[title[query][j]]);
				}
			}
			sort(res.begin(), res.end());
			for (int j = 0; j < res.size(); j++)
			{
				//cout << res[j] << endl;
				printf("%07d\n", res[j]);
			}
		}
		else if (t[0] == '2')
		{
			query = t.substr(3, t.length() - 3);
			if (author.find(query) == author.end())
			{
				cout << "Not Found" << endl;
			}
			else
			{
				for (int j = 0; j < author[query].size(); j++)
				{
					res.push_back(id[author[query][j]]);
				}
			}
			sort(res.begin(), res.end());
			for (int j = 0; j < res.size(); j++)
			{
				printf("%07d\n", res[j]);
			}
		}
		else if (t[0] == '3')
		{
			query = t.substr(3, t.length() - 3);
			if (keyword.find(query) == keyword.end())
			{
				cout << "Not Found" << endl;
			}
			else
			{
				for (int j = 0; j < keyword[query].size(); j++)
				{
					res.push_back(id[keyword[query][j]]);
				}
			}
			sort(res.begin(), res.end());
			for (int j = 0; j < res.size(); j++)
			{
				printf("%07d\n", res[j]);
			}
		}
		else if (t[0] == '4')
		{
			query = t.substr(3, t.length() - 3);
			if (publisher.find(query) == publisher.end())
			{
				cout << "Not Found" << endl;
			}
			else
			{
				for (int j = 0; j < publisher[query].size(); j++)
				{
					res.push_back(id[publisher[query][j]]);
				}
			}
			sort(res.begin(), res.end());
			for (int j = 0; j < res.size(); j++)
			{
				printf("%07d\n", res[j]);
			}
		}
		else
		{
			query = t.substr(3, t.length() - 3);
			if (year.find(query) == year.end())
			{
				cout << "Not Found" << endl;
			}
			else
			{
				for (int j = 0; j < year[query].size(); j++)
				{
					res.push_back(id[year[query][j]]);
				}
			}
			sort(res.begin(), res.end());
			for (int j = 0; j < res.size(); j++)
			{
				printf("%07d\n", res[j]);
			}
		}

	}
	return 0;
}