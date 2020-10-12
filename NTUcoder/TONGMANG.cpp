#include <bits/stdc++.h>
using namespace std;
long long t, n, k;
int main()
{
    while (cin >> n)
    {
        t += n;
        k++;
    }
    cout << t - k + 1;
    return 0;
}
