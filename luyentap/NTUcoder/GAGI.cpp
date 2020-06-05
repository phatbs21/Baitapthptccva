#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int dem = 0;
    while (a < b)
    {
        dem++;
        a = a * 2;
    }
    if (a > b)
        dem--;
    cout << dem;
}
