#include <bits/stdc++.h>
using namespace std;
ifstream fi("pruf_dec.inp");
ofstream fo("pruf_dec.out");
int n, a;
vector<pair<int, int>> prufer_decode_linear(const vector<int> &prufer_code)
{
    n += 2;
    vector<int> degree(n, 1);
    for (int i = 0; i < n - 2; ++i)
        ++degree[prufer_code[i]];
    int ptr = 0;
    while (ptr < n && degree[ptr] != 1)
        ++ptr;
    int leaf = ptr;
    vector<pair<int, int>> result;
    for (int i = 0; i < n - 2; ++i)
    {
        int v = prufer_code[i];
        result.push_back(make_pair(leaf, v));
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
    for (int v = 0; v < n - 1; ++v)
        if (degree[v] == 1)
            result.push_back({v, n - 1});
    return result;
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
    vector<pair<int, int>> ans;
    ans = prufer_decode_linear(pruf_code);
    fo << n << '\n';
    for (int i = 0; i < n - 1; ++i)
        fo << ans[i].first + 1 << ' '
           << ans[i].second + 1 << '\n';
}
