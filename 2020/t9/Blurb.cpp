#include <bits/stdc++.h>
using namespace std;
#define NAME "Blurb"

ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");

int main()
{
    int n, x;
    set<int> s;
    fi >> n;
    for (int i = 0; i < n; i++)
    {
        fi >> x;
        if (s.insert(x).second)
            fo << "0 ";
        else
            fo << "1 ";
    }
}