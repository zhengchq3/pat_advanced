/*建立二叉树，广度优先搜索*/
/*
#include <iostream>
using namespace std;
#include <vector>
#include <queue>
class node
{
public:
	int var;
	node* left;
	node* right;
	node(int t)
	{
		var = t;
		left = NULL;
		right = NULL;
	}
};


node* dfs(vector<int> post,vector<int> in)
{
	if (post.empty() || in.empty())
		return NULL;
	int temp = post[post.size() - 1];
	node* root = new node(temp);
	int index=0;
	for (int i = 0; i < in.size(); i++)
	{
		if (temp == in[i])
		{
			index = i;
			break;
		}
	}
	vector<int> leftIn(in.begin(), in.begin() + index);
	vector<int> rightIn(in.begin() + index + 1, in.end());
	vector<int> leftPost(post.begin(), post.begin() + index);
	vector<int> rightPost(post.begin() + index, post.end() - 1);
	root->left = dfs(leftPost, leftIn);
	root->right = dfs(rightPost, rightIn);
	
	return root;
}
int main()
{
	int n;
	cin >> n;
	vector<int> postorder(n), inorder(n);
	for (int i = 0; i < n; i++)
	{
		cin >> postorder[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> inorder[i];
	}
	node* root = dfs(postorder,inorder);
	queue<node*> level;
	level.push(root);
	vector<int> res;
	while (!level.empty())
	{
		node* r = level.front();
		level.pop();
		res.push_back(r->var);
		//cout << r->var << " ";
		if (r->left != NULL)
			level.push(r->left);
		if (r->right != NULL)
			level.push(r->right);

	}

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
		if (i != res.size() - 1)
			cout << " ";
	}
	return 0;
}
*/
/*深度优先搜索，改进求先序遍历的算法*/
#include <iostream>
using namespace std;
#include <map>
#include <vector>

int n;
int post[30] = { 0 };
int in[30] = { 0 };
map<int, int> hash1;
void dfs1(int root,int start,int end,int index)
{
	if (start > end)
		return;
	hash1[index] = post[root];
	int i=0;
	for (; i < n; i++)
	{
		if (post[root] == in[i])
		{
			break;
		}
	}
	dfs1(root-(end-i)-1, start, i - 1, 2 * index + 1);
	dfs1(root-1,i+1,end,2*index+2);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> post[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> in[i];
	}
	dfs1(n - 1, 0, n - 1, 0);
	
	auto itr = hash1.begin();
	vector<int> res;
	while (itr != hash1.end())
	{
		res.push_back(itr->second);
		itr++;
	}
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
		if (i != res.size() - 1)
		{
			cout << " ";
		}
	}
}