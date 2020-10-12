#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    int m;
    cin >> m;
    vector<int> b(n);
    for (auto &i : b)
        cin >> i;
    int test = 0;
    int Max = *max_element(a.begin(), a.end());
    int j = 0;
    bool check = false;
    for (int i = 0; i < n; i++)
    {

        if (check == true)
        {
            int vt, Min = INT_MAX;
            for (int k = j; k < n; k++)
            {
                if (Min > b[i])
                {
                    Min = b[i];
                    vt = k;
                }
            }
            j = vt;
            a[i] += Min;
        }
        else
            for (int k = j; k < n; k++)
            {
                if (a[i] + b[k] <= Max)
                {
                    a[i] += b[k];
                    j = k;
                    check = false;
                }
                else
                    check = true;
            }
    }
    cout << *min_element(a.begin(), a.end());
}