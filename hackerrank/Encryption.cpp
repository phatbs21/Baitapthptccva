#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "chillout";
    //getline(cin, s);
    int l = sqrt(s.length());
    int r = l + 1;
    vector<string> xau(r);
    int dem = -1;
    for (int i = 0; i < s.length(); i++)
    {

        if (i % r == 0)
            dem++;
        xau[dem] += s[i];
    }

    if (s.length() % r != 0)
        for (int i = 0; i <= xau[0].length() - xau[r - 1].length(); i++)
        {
            xau[r - 1] += '*';
        }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < l; j++)
        {
            if (xau[j][i] != '*')
                cout << xau[j][i];
        }
        cout << " ";
    }
}