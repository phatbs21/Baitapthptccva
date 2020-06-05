#include <bits/stdc++.h>
using namespace std;
int dem = 0, x;
int n, m, k;
bool stop = false;
string s;
int vitri[501];
string xau[501];
void print()
{
    dem++;
    if (dem == x)
    {
        stop = true;
        cout << s;
    }
    return;
}
void kt(int i)
{
    //chua hoan thanh
    if (stop == true)
        return;
    if (i > m)
    {
        print();
        return;
    }
    for (int j = 1; j <= m; j++)
    {
        s.replace(vitri[j], vitri[j], xau[j], i, i);
        kt(i + 1);
    }
}
int main()
{

    cin >> n >> m >> k >> x;
    cin >> s;

    for (int i = 1; i <= m; i++)
    {
        cin >> xau[i];
        sort(xau[i].begin(), xau[i].end());
    }

    string si = s;
    for (int i = 1; i <= n; i++)
    {
        int z = si.find("#");
        vitri[i] = z;
        si.replace(z, z, "*", 0, 0);
    }
    kt(0);
}