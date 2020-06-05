#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n + 1], b[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i]; // nam
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i]; // nữ
    }
    vector<int> a1, a2, b1, b2;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > 0)
            a1.push_back(a[i]);
        else
            a2.push_back(-a[i]);

        if (b[i] > 0)
            b1.push_back(b[i]);
        else
            b2.push_back(-b[i]);
    }
    n = 0;
    sort(a1.begin(), a1.end(), greater<int>()); // nam cao
    sort(a2.begin(), a2.end(), greater<int>()); //nam lun
    sort(b1.begin(), b1.end(), greater<int>()); //nu cao
    sort(b2.begin(), b2.end(), greater<int>()); //nu lun

    int i = 0, j = 0;

    while (i < a1.size() && j < b2.size())
    {
        if (a1.at(i) < b2.at(j))
        {
            j++;
            n++;
        }
        i++;
    }
    i = 0;
    j = 0;
    while (i < a2.size() && j < b1.size())
    {
        if (a2.at(i) > b1.at(j))
        {
            i++;
            n++;
        }
        j++;
    }
    cout << n;
}