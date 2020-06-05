#include <bits/stdc++.h>
using namespace std;
int n;
string s1, s2;
map<string, bool> q;
int Gien(int i, string s)
{
    if (i != n)
    {
        Gien(i + 1, s + s1[i]);
        if (s1[i] != s2[i])
        {
            Gien(i + 1, s + s2[i]);
        }
    }
    else
    {
        q[s] = true;
    }
    return 0;
}
int main()
{
    cin >> n >> s1 >> s2;
    Gien(0, "");
    cout << q.size() << endl;
    for (map<string, bool>::iterator i = q.begin(); i != q.end(); i++)
    {
        cout << i->first << endl;
    }
    return 0;
}
