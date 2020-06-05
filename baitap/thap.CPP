#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("thap.inp", "r", stdin);
  freopen("thap.out", "w", stdout);
  string s;
  cin >> s;
  int n = s.length();
  for (int i = 0; i < n - 1; i++)
  {
    string xau;
    for (int j = 0; j < n - i - 1; j++)
    {
      if (s[j] == s[j + 1])
      {
        xau += s[j];
      }
      else if ((s[j] == 'T' && s[j + 1] == 'B') || (s[j + 1] == 'T' && s[j] == 'B'))
      {
        xau += 'D';
      }
      else if ((s[j] == 'T' && s[j + 1] == 'D') || (s[j + 1] == 'T' && s[j] == 'D'))
      {
        xau += 'B';
      }
      else
      {
        xau += 'T';
      }
    }
    s = xau;
  }
  cout << s;
}