#include <bits/stdc++.h>
using namespace std;
bool ngto[100000000];
void sangnguyento(long long int n)
{
    if (n > 10000000)
        n = 10000000;
    memset(ngto, true, n + 1);
    ngto[0] = ngto[1] = false;
    for (long long int p = 2; p * p <= n; p++)
    {
        if (ngto[p] == true)
        {
            for (long long int i = p * p; i <= n; i += p)
                ngto[i] = false;
        }
    }
}

long long int oneDigit(long long int num)
{
    return (num >= 0 && num < 10);
}
bool isPalUtil(long long int num, long long int *dupNum)
{
    if (oneDigit(num))
        return (num == (*dupNum) % 10);
    if (!isPalUtil(num / 10, dupNum))
        return false;
    *dupNum /= 10;
    return (num % 10 == (*dupNum) % 10);
}
long long int isPal(long long int num)
{
    if (num < 0)
        num = -num;
    long long int *dupNum = new long long int(num);
    return isPalUtil(num, dupNum);
}

int main()
{
    freopen("AUCTION.INP", "r", stdin);
    freopen("AUCTION.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int a,b;
    cin >> a >> b;
    sangnguyento(b);
    long long int dem = 0;
    for (long long int i = a; i <= b; i++)
    {
        if (i > 10000000)
            break;
        if (ngto[i])
        {
            if (isPal(i))
            {
                dem++;
            }
        }
    }
    cout << dem;
}
