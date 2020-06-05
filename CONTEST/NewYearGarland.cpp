#include <bits/stdc++.h>
using namespace std;
bool kt(int r, int g, int b)
{
    if (r > g + b + 1)
        return false;
    if (g >r + b + 1)
        return false;
    if (b > r + g + 1)
        return false;
    return true;
}
int main()
{
    int t;
    cin >> t;
    int r, g, b;
    for (int i = 1; i <= t; i++)
    {
        cin >> r >> g >> b;
        if (kt(r, g, b) == false)
        {
            cout << "No";
        }
        else
        {
            cout << "Yes";
        }
        cout << endl;
    }
}