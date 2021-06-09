#include <bits/stdc++.h>
using namespace std;
int main()
{
    string x;
    cin >> x;
    int n = x.length();
    vector<int> a(n);
    for (int i = 0; i < x.length(); i++)
    {
        a[i] = (x[i]-48);
    }
    int y = INT_MAX;
    int as = a[0];
    for (int i = 1; i < x.length(); i++)
    {
        as *= 10;
        as += a[i];
    }
    sort(a.begin(), a.end());
    do
    {
        int tong = a[0];
        for (int i = 1; i < x.length(); i++)
        {
            tong *= 10;
            tong += a[i];
        }
        //cout << tong << " ";
        if (tong < y && tong > as)
            y = tong;
    } while (next_permutation(a.begin(), a.end()));
    if(y!=INT_MAX)
    cout << y;
    else cout<<0;
}