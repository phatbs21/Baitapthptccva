#include <bits/stdc++.h>
int main()
{
    int n;
    std::cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = n; i >= 1; i--)
    {
        if (a[i] == n)
            n--;
    }
    std::cout << n;
}