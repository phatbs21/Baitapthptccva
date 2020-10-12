#include <bits/stdc++.h>
using namespace std;
#define NAME "CubesSorting"
#define tocdo cout << "Time " << clock() / (double)1000 << " sec"
//ifstream fi(NAME ".inp");
//ofstream fo(NAME ".out");
//#define cin fi
//#define cout fo
#define lli int64_t
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<lli> a(n + 1);
        for (lli i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        bool check = false;
        for (lli i = 2; i <= n; i++)
        {
            if (a[i] >= a[i - 1])
            {
                check = true;
            }
        }
        if (check == true)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}