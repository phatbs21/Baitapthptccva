#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    if (n < k)
        cout << "10";
    else
    {
        if ((n * 2) % k == 0)
            cout << ((n * 2) / k) * 5;
        else
            cout << ((n * 2) / k + 1) * 5;
    }
}