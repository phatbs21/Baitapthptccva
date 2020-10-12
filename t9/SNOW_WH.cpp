#include <bits/stdc++.h>
using namespace std;
#define NAME "SNOW_WH"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");

#define ff first
#define ss second
typedef pair<int, int> pii;
typedef pair<int, bool> pib;

void dtr_bt()
{
    nt=(nh+1)/2;
    int u,v;
    for (int i=ns1;i<=ns2;++i)
    {
        u=i*2-nh+1;
        v=u+1;
        sm[i]=dtr_mn(p[u],p[v]);
        sx[i]=dtr_mx(p[u],p[v]);
    }
    sm[ns2+1]=sm[ns2],sx[ns2+1]=sx[ns2];
    for (int i=ns1-1;i>-1;--i)
    {
        u=i*2;v=u+1;sm[i]=dtr_mn(sm[u],sm[v]);
        sx[i]=dtr_mx(sx[u],sx[v])
    }
    // dep nghi bo, kho nhin vcl
    
}