#include <iostream>
using namespace std;
int x[100], m, n;
string s;
void ghi()
{
    for (int i = 0; i < n; i++)
    {
        if (x[i] == 1)
        {
            cout << "+";
        }
        else if (x[i] == 2)
        {
            cout << "-";
        }
    }
    cout << endl;
}
bool kt()
{
    int tong = 0, so = 0, dau = 1;

    for (int i = 0; i < n; i++)
    {
        if (x[i] == 0)
        {
            so = so * 10 + s[i] - 48;
        }
        else if (x[i] == 1)
        {
            tong = tong + dau * so;
            so = s[i] - 48;
            dau = 1;
        }
        else
        {
            tong = tong + dau * so;
            so = s[i] - 48;
            dau = -1;
        }
    }
    tong = tong + dau * so;
    return (tong == m);
}
void duyet(const int i)
{

    if (x[0] == 1)
    {
        return;
    }

    if (i >= n)
    {
        if (kt() == true)
        {
            ghi();
        }
        return;
    }

    for (int j = 0; j <= 2; j++)
    {
        x[i] = j;
        duyet(i + 1);
    }
}
int main()
{
    freopen("chenxauso.out", "w", stdout);
    freopen("chenxauso.out", "w", stdout);
    cin >> m;
    cin >> s;
    n = s.length();
    duyet(0);
    //fclose(stdout);
}
