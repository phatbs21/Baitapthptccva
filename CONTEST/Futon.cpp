#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h, w, dem = 0;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w - 1; j++)
        {
            if (s[i][j] == s[i][j + 1] && s[i][j] == '.')
                dem++;
        }
    }
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h - 1; j++)
        {
            if (s[j][i] == s[j + 1][i] && s[j][i] == '.')
                dem++;
        }
    }
    cout << dem;
}