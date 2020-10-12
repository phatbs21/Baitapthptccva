#include <bits/stdc++.h>
using namespace std;
ifstream fi("reflective.inp");
ofstream fo("reflective.out");
const int64_t one = 1;
int64_t f(int64_t x)
{
    int64_t sum = 0, t = 0, tl;
    for (int i = 63; i > 0; i--)
    {
        tl = x / (one << i) - t;
        sum += tl * i;
        t += tl;
    }
    return sum;
}
int main()
{
    int rf, lf;
    fi >> lf >> rf;
    fo << f(rf) - f(lf - 1);
    cout << "Time " << clock() / (double)1000 << " sec";
}