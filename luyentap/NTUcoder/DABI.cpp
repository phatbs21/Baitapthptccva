#include <iostream>
using namespace std;
int main()

{
    long long int n, m;
    cin >> n;
    m = n;
    int t = 0;
    while (n > 0)
    {
        t += n % 10;
        n = n / 10;
    }
    if (m % t == 0)
        cout << 1;
    else
        cout << 0;
}