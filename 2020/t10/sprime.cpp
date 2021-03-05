#include <bits/stdc++.h>
using namespace std;
int l, r, s, t;
bool check[3000005];
vector<int> ans;
bool tong(int a)
{
    int s = 0;
    while (a > 0)
    {
        s += a % 10;
        a /= 10;
    }
    if (s % 5 == 0)
        return true;
    else
        return false;
}
void kt(int b)
{
    for (int i = 1; i <= b; i++)
        check[i] = false;
    check[0] = check[1] = true;
    for (int i = 2; i <= b; ++i)
    {
        if (check[i] == false)
        {
            for (int k = 2 * i; k <= b; k += i)
                check[k] = true;
        }
    }
}

int main()
{
    freopen("sprime.inp", "r", stdin);
    freopen("sprime.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        int dem = 0;
        cin >> l >> r;
        kt(r);
        for (int i = l; i <= r; ++i)
        {
            if (check[i] == false)
            {
                if (tong(i) == true)
                    dem++;
            }
        }
        ans.push_back(dem);
    }
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << "\n";
}
