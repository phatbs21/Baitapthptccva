#include <bits/stdc++.h>
int main()
{
    int n, k;
    std::cin >> n >> k;
    std::cout << ((n % (k + 1) > 0) ? "Alice will win" : "Bob will win");
}
