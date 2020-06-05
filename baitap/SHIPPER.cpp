
//lenguyentanphat
#include <bits/stdc++.h>
using namespace std;
long long int n, T, a[1000001];
int main()
{
  freopen("SHIPPER.INP", "r", stdin);
  freopen("SHIPPER.OUT", "w", stdout);
  cin >> n >> T;
  for (long long int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  if (n == 1)
  {
    cout << 1;
    return 0;
  }
  long long int max1, max2, S1, S2;
  if (a[1] > a[2])
  {
    max1 = 1;
    max2 = 2;
  }
  else
  {
    max1 = 2;
    max2 = 1;
  }
  long long int i = 1, time = 0;
  while (i <= n)
  {
    time += a[i];
    if (a[i] > a[max1])
    {
      max2 = max1;
      max1 = i;
    }
    else if (a[i] > a[max2] && a[i] < a[max1])
      max2 = i;
    if (time - a[max1] - a[max2] <= T)
    {
      S1 = max1;
      S2 = max2;
    }
    else
      break;
    i++;
  }
  cout << min(S1, S2) << " " << max(S1, S2);
  return 0;
}
