#include <bits/stdc++.h>
using namespace std;
#define bignum string
bool cmp2(bignum a, bignum b)
{
    return a+b>b+a;
}
int main()
{
    bignum a[101];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, cmp2);
    for (int i = 1; i <= n; i++)
    {
        cout<< a[i]<<" ";
    }
    cout << endl;
}