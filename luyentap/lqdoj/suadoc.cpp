#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n, k;
        cin >> n >> k;
        long long int tong = n * 4 ;
        if (tong >= k)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}