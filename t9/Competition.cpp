#include <bits/stdc++.h>
using namespace std;
#define NAME "Competition"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");
int main()
{
    int n, m, a, b, tg = 0;
    fi >> n >> m >> a >> b;
    fo << n / m * min(a, b * m) + min(a, (n % m) * b) + n;
}