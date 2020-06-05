#include <bits\stdc++.h>
using namespace std;
int main()
{
    freopen("phanso.inp","r",stdin);
    freopen("phanso.out","w",stdout);
    int m, n;
    cin >> m >> n;
    cout << "phan so toi gian:" << m / __gcd(m, n) << "/" << n / __gcd(m, n);
}