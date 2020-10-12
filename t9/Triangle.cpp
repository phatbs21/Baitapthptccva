#include <bits/stdc++.h>
using namespace std;
#define NAME "Triangle"
#define tocdo cout << "Time " << clock() / (double)1000 << " sec"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");

int main()
{
    int a, b, c, ans = 0;
    fi >> a >> b >> c;
    if (a < b)
        swap(a, b);
    if (a < c)
        swap(a, c);
    if (a >= b + c)
        ans = a - b - c + 1;
    fo << ans;
}