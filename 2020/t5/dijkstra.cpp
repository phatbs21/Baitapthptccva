#include <bits/stdc++.h>
//https://vjudge.net/problem/CodeForces-1302D
using namespace std;
#define pii pair<int, int>
#define TRUE 1
#define FALSE 0
int chuaxet[10000];
int a[1000][1000];
int d[1000];
int truoc[1000];
int main()
{

    int n, m;
    cin >> n >> m;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    vector<pair<int, int>> b[100001];
    int u, v, w;
    for (long long i = 0; i < m; i++)
    {
        long long x, y, z;
        cin >> x >> y >> z;
        b[u].push_back(pii(v, w));
        b[u].push_back(pii(u, w));
    }
    q.push(pii(0, s));
}