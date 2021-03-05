#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, nua, a;
    cin >> n;   
    nua = n / 2;
    vector<string> str(1000001, "");
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> s;
        if (i < nua)
            str[a] += "- ";
        else
            str[a] += s + " ";
    }
    for (int i = 0; i < n; i++)
        cout << str[i];
}
