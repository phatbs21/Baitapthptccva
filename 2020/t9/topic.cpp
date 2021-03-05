#include <bits/stdc++.h>
using namespace std;
ifstream fi("topic.inp");
ofstream fo("topic.out");
int main()
{
    int n, t, k = 0;
    fi >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        fi >> t;
        k += t;
        if (k)
        {
            s += "*";
            --k;
        }
        else
            s += "-";
    }
    while (k)
        s += "*", --k;
    fo << s;
}