#include <bits/stdc++.h>
using namespace std;
#define NAME "Chronicle"

ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");
int main()
{
    int a, n;
    fi >> a >> n;
    int ans = a + n;
    if (a * ans <= 0)
        if (n < 0)
            --ans;
        else
            ++ans;
    fo << ans;
    cout << "Time " << clock() / (double)1000 << " sec";
}