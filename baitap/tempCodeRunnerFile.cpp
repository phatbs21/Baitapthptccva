#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    swap(b, b > c ? c : b);
    if (b == c || (b * 2 + c) % 3 == 0 || (a != 0 || b != 0))
        cout << "YES";
    else
        cout << "NO";
}