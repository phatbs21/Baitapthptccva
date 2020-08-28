#include <bits/stdc++.h>
using namespace std;
#define bignum string
bignum nhan1(bignum s, int a)
{
    string k;
    int nho = 0, c;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        c = a * (s[i] - 48) + nho;
        nho = c / 10;
        c = c % 10;
        k = char(c + 48) + k;
    }
    while (nho > 0)
    {
        k = char(nho % 10 + 48) + k;
        nho /= 10;
    }
    return k;
}
void kq(int n)
{
    bignum q = "1";
    for (int i = 1; i <= n; i++)
    {
        q = nhan1(q, i);
    }
    if (q.length() > 7)
    {
        for (int i = 0; i < 7; i++)
        {
            cout << q[i];
        }
        cout << endl;
    }
    else
    {
        cout << q << endl;
    }
    int dem = 0, z = 1;
    for (int i = 1; i <= 4; i++)
    {
        z = z * 5;
        dem += n / z;
    }
    cout << dem << endl;
}
int main()
{
    auto start = chrono::steady_clock::now();

    int n=100;
    //cin >> n;
    kq(n);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << endl
         << "Runtime: " << chrono::duration<double>(diff).count() << " seconds" << endl;
}