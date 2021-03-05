#include <bits/stdc++.h>
using namespace std;
ifstream fi("Merge_seg.inp");
ofstream fo("Merge_seg.out");
#define ss second
#define ff first 
typedef pair<int, bool> pib;
int n, a, b, c = 1, ans = 0;
int main()
{
    fi >> n;
    vector<pib> x(2 * n);
    for (int i = 0; i < n; ++i)
    {
        fi >> a >> b;
        x[2 * i] = {a, 0};
        x[2 * i + 1] = {b, 1};
    }
    sort(x.begin(), x.end());
    for (int i = 1; i <= 2 * n; ++i)
    {
        if (c)
            ans += x[i].ff - x[i - 1].ff;
        if (x[i].ss)
            --c;
        else
            ++c;
    }
    fo<<ans;
    cout<<"Time: "<<clock()/(double)1000<<" sec";
}