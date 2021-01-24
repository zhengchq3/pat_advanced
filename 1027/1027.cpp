#include <iostream>
using namespace std;

char mars[13] = { '0','1','2','3','4','5','6','7','8','9','A','B','C' };

int main()
{
	int red, green, blue;
	cin >> red >> green >> blue;
	cout << "#";
	int n1, n2;
	n1 = red / 13;
	n2 = red % 13;
	cout << mars[n1] << mars[n2];
	n1 = green / 13;
	n2 = green % 13;
	cout << mars[n1] << mars[n2];
	n1 = blue / 13;
	n2 = blue % 13;
	cout << mars[n1] << mars[n2];
	return 0;
}