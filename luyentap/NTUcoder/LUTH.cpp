#include <bits/stdc++.h>
using namespace std;
long long int lt(int a, long long int b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return lt(a, b / 2) * lt(a, b / 2) % 10000;
    else
        return a * lt(a, b - 1) % 10000;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int b;
    int a;
    cin >> a >> b;
    cout << lt(a, b);
}