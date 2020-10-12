#include <bits/stdc++.h>
using namespace std;
#define NAME "gloves"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");

int main()
{
    int n;
    fi >> n;
    if(n==0)
    {
        fo<<0;
        return 0;
    }
    fo<<2*n-1;
}
