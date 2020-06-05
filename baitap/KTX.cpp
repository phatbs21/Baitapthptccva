#include <iostream>
#include <cstring>
#include <cmath>
#define INF 0x3f3f3f3f
using namespace std;
inline long long min(long long a, long long b) { return a < b ? a : b; }
int N, M, K;
int building[120];
long long dp[120][520];
long long sum(int total, int times)
{
    times++;
    long long x = total / times;
    long long big = total % times;
    long long small = times - big;
    return x * (x + 1) / 2 * small + (x + 1) * (x + 2) / 2 * big;
}
long long recur(int index, int turn)
{
    if (dp[index][turn] != -1)
        return dp[index][turn];
    if (index == 1)
        return dp[index][turn] = sum(building[index], turn);
    long long ans = INF;
    for (int i = 0; i <= turn; i++)
        ans = min(ans, recur(index - 1, turn - i) + sum(building[index], i));
    return dp[index][turn] = ans;
}

int main()
{
    freopen("KTX.INP", "r ", stdin);
    freopen("KTX.OUT", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 0, a; i < N; i++)
    {
        cin >> a;
        building[a]++;
    }
    memset(dp, -1, sizeof dp);
    cout << recur(M, K) << endl;
}