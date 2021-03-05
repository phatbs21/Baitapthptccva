#include <bits/stdc++.h>
using namespace std;
#define NAME "archaeol"
#define tocdo cout << "Time " << clock() / (double)1000 << " sec"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");
#define ll int64_t
#define INFL 1000000000

ll all_tm(ll l, ll r)
{
    double tmp = (double)(r - l) * (l + r - 1) / 2;
    if (tmp < -INFL * 4)
        return -INFL * 2;

    ll ret = (r - l) * (l + r - 1) / 2;
    return ret;
}
int main()
{
    int n, t;
    fi >> n >> t;
    vector<ll> pref(n + 1);
    vector<int> h(n);
    int r = n - 1;
    int l = 0;
    while (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            r = mid - 1;
        if (arr[mid] < x)
            l = mid + 1;
    }
}
//Code chua xong phia tren
//code mau phia duoi
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll const INFL = (ll)1e18 + 1e6;
ll all_tm(ll l, ll r)
{
  double tmp = (double)(r - l) * (l + r - 1) / 2;
  if (tmp < -INFL * 4)
    return -INFL * 2;
  ll ret = (r - l) * (l + r - 1) / 2;
  return ret;
}
int main()
{
  ifstream cin("archaeol.inp");
  ofstream cout("archaeol.out");
  int n, a;
  ll t;
  cin >> n >> t;
  vector<int> h(n);
  vector<ll> pref(n + 1);
  pref[0] = 0;
  for (int i = 0; i < n; ++i)
  {
    cin >> a;
    h[i] = a;
    pref[i + 1] = pref[i] + a;
  }
  ll ans = *min_element(h.begin(), h.end());
  for (int i = 0; i < n; ++i)
  {
    ll lh = -t, rh = h[i];
    while (rh - lh > 1)
    {
      ll midh = (lh + rh) / 2;
      int llb = -1, rlb = i;
      while (rlb - llb > 1)
      {
        int midl = (llb + rlb) / 2;
        if (h[midl] <= midh + (i - midl))
          llb = midl;
        else
          rlb = midl;
      }
      int lrb = i, rrb = n;
      while (rrb - lrb > 1)
      {
        int midr = (lrb + rrb) / 2;
        if (h[midr] <= midh + (midr - i))
          rrb = midr;
        else
          lrb = midr;
      }
      ll sum = pref[lrb + 1] - pref[rlb];
      sum -= all_tm(midh, midh + (i - rlb) + 1) +
             all_tm(midh + 1, midh + (lrb - i) + 1);
      if (sum > t)
        lh = midh;
      else
        rh = midh;
    }
    ans = min(ans, rh);
  }
  cout << ans << "\n";
}
*/