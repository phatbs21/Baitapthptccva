#include <iostream>
#include <algorithm>
using namespace std;
int max1(int a, int b, int c)
{
    return max(a, max(b, c));
}
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("test.inp", "r", stdin);
    int n;
    cin >> n;
    int a[n + 10], b[n + 10], c[n + 10];
    int A[n + 1], B[n + 1], C[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    A[1] = a[1];
    B[1] = b[1];
    C[1] = c[1];

    for (int i = 2; i <= n; i++)
    {
        A[i] = max(B[i - 1], C[i - 1]) + a[i];
        B[i] = max(C[i - 1], A[i - 1]) + b[i];
        C[i] = max(B[i - 1], A[i - 1]) + c[i];
    }
    cout << max1(A[n],B[n], C[n]) << endl;
}