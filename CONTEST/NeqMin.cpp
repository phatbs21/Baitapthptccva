#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i <= 200000; i++)
    s.insert(i);
    for(int i=0;i<n;i++)
    {
        s.erase(p[i]);
        auto ok=s.begin();
        cout<<*ok<<"\n";
    }
}