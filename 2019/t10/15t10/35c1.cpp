#include <bits\stdc++.h>
using namespace std;
struct ps
{
    int a, b;
};
bool operator<(ps x, ps y)
{
    return (x.a * y.b - x.b * y.a) * ((x.b) * (y.b)) < 0;
}
int main()
{
    int n, k = 0;
    cin >> n;
    ps a[n + 1];
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            if (__gcd(j, i) == 1)
            {
                a[k] = {j, i};
                k++;
            }
    sort(a, a + k);
    for (int i = 0; i < k; i++)
    {
        cout << a[i].a << " " << a[i].b << endl;
    }
}