#include <iostream>
using namespace std;

int main()
{
	double res = 1;
	char r[3] = { 'W','T','L' };
	double max = 0;
	int index = 0;
	for (int i = 0; i < 3; i++)
	{
		double t;
		cin >> t;
		if (t > max)
		{
			max = t;
			index = i;
		}
	}
	res *= max;
	printf("%c ", r[index]);
	//cout << r[index] << " ";

	max = 0;
	for (int i = 0; i < 3; i++)
	{
		double t;
		cin >> t;
		if (t > max)
		{
			max = t;
			index = i;
		}
	}
	res *= max;
	printf("%c ", r[index]);
	//cout << r[index] << " ";

	max = 0;
	for (int i = 0; i < 3; i++)
	{
		double t;
		cin >> t;
		if (t > max)
		{
			max = t;
			index = i;
		}
	}
	res *= max;
	printf("%c ", r[index]);
	//cout << r[index] << " ";

	res *= 0.65;
	res--;
	res *= 2;
	printf("%.2f", res);

	return 0;
}