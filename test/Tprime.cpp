#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n)
{
    if (n < 2)
        return 0;
    if (n <= 3)
        return 1;

    if (n % 2 == 0 || n % 3 == 0)
        return 0;

    for (long long i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;

    return 1;
}
int main()
{

    long long n;
    cin >> n;
    int count = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (isPrime(i))
            count++;
    }
    cout << count << endl;
}