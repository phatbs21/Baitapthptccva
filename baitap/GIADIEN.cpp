//lenguyentanphat
#include <bits/stdc++.h>
using namespace std;
int main()
{
  freopen("GIADIEN.INP", "r", stdin);
  freopen("GIADIEN.OUT", "w", stdout);
  long long int n;
  cin >> n;
  long long int a[n + 20];
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  long long int x = 0;
  long long int d;
  for (long long int i = 1; i <= n; i++)
  {
    d = 0;
    x = 0;
    if (a[i] <= 50) //bac1
    {
      x = 1678 * a[i];
    }
    if (a[i] <= 100 && a[i] > 50) //bac2
    {
      x = 1734 * (a[i] % 50) + 1678 * 50;
    }
    if (a[i] <= 200 && a[i] > 100) //bac3
    {
      x = 2014 * (a[i] % 100) + 1734 * 50 + 1678 * 50;
    }
    if (a[i] <= 300 && a[i] > 200) //bac 4
    {
      x = 2536 * (a[i] % 200) + 2014 * 100 + 1734 * 50 + 1678 * 50;
    }
    if (a[i] <= 400 && a[i] > 300) //bac5
    {
      x = 2834 * (a[i] % 300) + 2536 * 100 + 2014 * 100 + 1734 * 50 + 1678 * 50;
    }
    if (a[i] > 400) //bac6
    {
      x = 2927 * (a[i] % 400) + 2834 * 100 + 2536 * 100 + 2014 * 100 + 1734 * 50 + 1678 * 50;
    }
    if (x % 10 > 5)
      d = 1;
    x += x / 10 + d;
    cout << x << endl;
  }
  return 0;
}
