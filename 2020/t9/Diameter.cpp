#include <bits/stdc++.h>
using namespace std;
ifstream fi("Diameter.inp");
ofstream fo("Diameter.out");
int n, a, res;
vector<int> dist;
int prufer_decode_linear(const vector<int> &prufer_code)
{
    n += 2;
    vector<int> degree(n, 1);
    for (int i = 0; i < n - 2; ++i)
        ++degree[prufer_code[i]];
    int ptr = 0;
    while (ptr < n && degree[ptr] != 1)
        ++ptr;
    int leaf = ptr;
    for (int i = 0; i < n - 2; ++i)
    {
        int v = prufer_code[i];
        dist[v] = max(dist[v], dist[leaf] + 1);
        --degree[leaf];
        if (--degree[v] == 1 && v < ptr)
            leaf = v;
        else
        {
            ++ptr;
            while (ptr < n && degree[ptr] != 1)
                ++ptr;
            leaf = ptr;
        }
    }
    res = dist[n - 1] + dist[leaf] + 1;
    return res;
}
int main()
{
    fi >> n;
    vector<int> pruf_code(n);
    for (int i = 0; i < n; ++i)
    {
        fi >> a;
        pruf_code[i] = --a;
    }
    dist.assign(n + 2, 0);
    fo << prufer_decode_linear(pruf_code);
}
