#include <bits/stdc++.h>
using namespace std;
int d[1000];
int DFS(int u)
{
    d[u] = true;
    for (int v = 1; v <= u; v++)
    {
        if (d[v] == false)
        {
            DFS(v);
        }
    }
}
int main()
{
    memset(d, true, sizeof(d));
    //nhap dữ liệu
}