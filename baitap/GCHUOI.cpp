#include <bits/stdc++.h>
int main()
{
    int t, a[4];
    std::cin >> t;
    for (int i = 1; i <= t; i++)
    {
        std::cin >> a[0] >> a[1] >> a[2];
        std::sort(a, a + 3);
        std::cout << ((a[1] == a[2]) ? a[1] * 2 : a[1] * 2 + 1) << std::endl;
    }
}
// BLACKBULLET :3 Hina_Imamura :3 Parrottos :3  I love you :3
