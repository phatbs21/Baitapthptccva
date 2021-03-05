#include <iostream>
#include <cstdio>
using namespace std;
int a[100][100];
int T[100];
int n, s, t;
bool d[100];
void write()
{
    int p[100], k = 1;
    int i = t;
    while (i != s)
    {
        p[k] = i;
        k++;
        i = T[i];
    }
    p[k] = s;
    //k++;
    for (i = k; i >= 1; i--)
        cout << p[i] << " ";
    cout << endl;
}
void visit(int u)
{
    //cout<<u<<". \n";
    if (u == t)
    {
        cout << "tim thay\n";
        write();
        return;
    }
    d[u] = true;
    for (int v = 1; v <= n; v++)
    {
        if (a[u][v] > 0 && d[v] == false)
        {
            T[v] = u;
            visit(v);
        }
    }
}
int main()
{
    freopen("duongdi.inp", "r", stdin);
    int i, j;
    cin >> n >> s >> t;
    //cout<<n<<" "<<s<<" "<<t<<endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    for (i = 1; i <= n; i++)
        d[i] = false;
    visit(s);
}
