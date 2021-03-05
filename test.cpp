#include <bits/stdc++.h>
using namespace std;
long long int p = 0, digit = 1;
void whichDigit(long long int *tmp, long long int *pos)
{
    *tmp /= pow(10, floor(log10(*tmp)) + 1 - *pos);
    cout << *tmp % 10;
}
void whichNum()
{
    if (p == 0)
        cout << 9;
    else
    {
        long long int num = p, pos = 1;
        if (digit != 1)
        {
            --p;
            num = pow(10, digit - 1) + (p / digit);
            pos = p % digit + 1;
        }
        whichDigit(&num, &pos);
    }
}
void trimNum()
{
    while (1)
    {
        long long int tmp = 9 * digit * pow(10, digit - 1);
        if (p - tmp < 0)
        {
            break;
        }
        p -= tmp;
        ++digit;
    }
    whichNum();
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> p;
    trimNum();
    return 0;
}
