#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int phai = 0, trai = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            trai++;
        else
            phai++;
    }
    if (trai != phai)
    {
        cout << -1;
        return 0;
    }
    trai = 0, phai = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            trai++;
        else if (s[i] == ')')
            trai--;
        if (trai < 0)
        {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}
