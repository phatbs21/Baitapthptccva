#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int tong = a + b + c + d;
    if (b == tong - b)
        cout << "Yes";
    else if (a == tong - a)
        cout << "Yes";
    else if (c == tong - c)
        cout << "Yes";
    else if (d == tong - d)
        cout << "Yes";
    else if (a + b == tong - a - b)
        cout << "Yes";
    else if (a + c == tong - a - c)
        cout << "Yes";
    else if (a + d == tong - a - d)
        cout << "Yes";
    else if (b + c == tong - b - c)
        cout << "Yes";
    else if (b + d == tong - b - d)
        cout << "Yes";
    else if (c + d == tong - c - d)
        cout << "Yes";
    else
        cout << "No";
}