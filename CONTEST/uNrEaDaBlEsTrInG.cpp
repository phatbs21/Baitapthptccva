#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (i % 2 == 0 && s[i] < 91)
        {
            cout << "No";
            return 0;
        }
        if (i % 2 == 1 && s[i] > 97)
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}