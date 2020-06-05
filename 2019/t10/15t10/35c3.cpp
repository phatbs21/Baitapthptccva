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
    vector<ps> b;
    int n, k = 0;
    cin >> n;

    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            if (__gcd(i, j) == 1)
            {
                b.push_back({j,i});
                k++;
            }
    sort(b.begin(),b.end());
    for (int i = 0; i < b.size(); i++)
    {
                cout << b[i].a << " " << b[i].b << endl;
    }
}