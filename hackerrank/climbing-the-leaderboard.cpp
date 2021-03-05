#include <bits/stdc++.h>
using namespace std;
#define rank sad
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    int m;
    cin >> m;
    vector<int> b(m);
    for (auto &i : b)
        cin >> i;
    sort(a.begin(), a.end(), greater<int>());
    a.resize(distance(a.begin(), unique(a.begin(), a.end())));
    n = a.size();
    a.push_back(b[0]);
    int rank = 0;
    for (int i = 0; i < b.size(); i++)
    {
        for (int j = n - rank - 1; j >= 0; j--)
        {
            if (a[j] <= b[i])
            {
                rank++;
            }
            else
                break;
        }
        //a[n - rank] = b[i];
        cout << n - rank + 1 << "\n";
    }
}