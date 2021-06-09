#include <iostream>
using namespace std;
int n, h, k, i, j;
int d[1000][1001];
int loang1[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
int main()
{
	cin >> n;

	d[i][j] = 0;

	for (i = 1; i <= n; i++)
	{

		d[0][i] = 1;
		d[n + 1][i] = 1;
		d[i][0] = 1;
		d[i][n + 1] = 1;
	}
	k = 1;
	i = j = 1;
	h = 0;
	while (k <= n * n)
	{
		d[i][j] = k;
		k++;
		if (d[i + loang1[h]][j + dj[h]] > 0)
		{
			h = (h + 1) % 4;
		}
		i = i + loang1[h];
		j = j + dj[h];
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (j!=n)
			cout << d[i][j] << " ";
			else cout<<d[i][j];
		}
		cout << endl;
	}
}
