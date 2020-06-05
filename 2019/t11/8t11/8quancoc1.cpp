#include <iostream>
using namespace std;
int n, x[10];
bool d[10];
int vebanco()
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cout << (x[i] == j ? "H" : "0");
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
int thu(int i)
{
	int k, j, trong;
	if (i > n)
	{
		vebanco();
		return 0;
		for (i = 1; i <= n; i++)
		{
			cout << x[i] << " ";
		}
		cout << endl;
		return 0;
	}
	for (k = 1; k <= n; k++)
	{
		if (d[k] == false)
		{
			trong = true;
			for (j = 1; j <= i - 1; j++)
			{
				if ((j - x[j]) == (i - k) or (j + x[j]) == (i + k))
				{
					trong = false;
				}
			}
			if (trong == true)
			{
				x[i] = k;
				d[k] = true;
				thu(i + 1);
				d[k] = false;
			}
		}
	}
	return 0;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		d[i] = false;
	}
	thu(1);
}
