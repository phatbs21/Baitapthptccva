#include <bits/stdc++.h>

using namespace std;
int a[1000], n, m, dem;
int main()
{
    cin >> n;
    if (n == 0)
    {
        cout << "0";
        return 0;
    }
    m = n;
    int i = 0;
    while (m != 0)
    {

        a[i] = m % 2;
        m /= 2;
        i++;
    }
    i = i - 1;
    for (int j = i; j >= 0; j--)

        cout << a[j];

    return 0;
}