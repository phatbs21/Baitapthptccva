#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Og")
#pragma GCC push_options
#pragma GCC pop_options
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    static long long cnt[19][19];
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        if (i % 10 != 0)
        {
            string tmp = to_string(i);
            cnt[tmp[0] - '0'][tmp.back() - '0']++;
        }
    }
    long long int ans = 0;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            ans += cnt[i][j] * cnt[j][i];
        }
    }
    cout << ans << endl;

    return 0;
}