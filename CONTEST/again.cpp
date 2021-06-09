#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> b;
vector<int> a;
string s;
int n;

bool k(char a)
{
    if (a == '<')
        return false;
    else
        return true;
}
bool kt2(int u)
{
    for (int j = 0; j <= n; j++)
    {
        int sum = 0;
        for (int i = u; i >= 0; i--)
        {
            sum += b[i][j];
        }
        if (sum != a[u])
            return false;
    }
    return true;
}
bool kt(int u)
{
    for (int j = 0; j <= n; j++)
    {
        int sum = 0;
        for (int i = u; i >= 0; i--)
        {
            sum += b[i][j];
        }
        if (sum > a[u])
            return false;
    }
    return true;
}
bool check(int u)
{
    for (int i = 0; i < u; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((k(s[j]) == false && b[i][j] < b[i][j + 1]) || (k(s[j]) == true && b[i][j] > b[i][j + 1]))
                return false;
        }
    }
    return true;
}
int main()
{
    cin >> n >> s;
    a.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
    }
    b.assign(105, vector<int>(105, 0));
    int dem = -1;
    for (int i = 0; i <= n; i++)
        b[i][0] = 1;
    do
    {
        dem++;
        for (int i = 1; i <= n; i++)
        {
            if (k(s[i]) != true)
                b[dem][i] = b[dem][i - 1] - 1;
            else
                b[dem][i] = b[dem][i - 1] + 1;
        }
    } while (kt2(dem) == false && check(dem) == false);
}