#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    int tong = accumulate(a.begin(), a.begin(), 0);
    vector<int> q;
    for (int i = 0; i < n; i++)
    {
        q.push_back(a[i]);
        int *x = min_element(q.begin(), q.end());
    }
}