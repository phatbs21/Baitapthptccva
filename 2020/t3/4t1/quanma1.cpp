#include <iostream>
#include <queue>

using namespace std;

int d[100][100] = {0};
bool kt = false;
int k = 0;
int n;
pair<int, int> kq[100];
int x0, y0;
int b;

void lannguoc()
{
    int x = x0, y = y0;
    while (x > 0 && y > 0)
    {
        b = d[x][y] - 1;
        kq[k] = make_pair(x, y);
        ++k;
        if (d[x - 1][y - 2] == b)
        {
            x -= 1;
            y -= 2;
            continue;
        }
        if (d[x - 1][y + 2] == b)
        {
            x -= 1;
            y += 2;
            continue;
        }
        if (d[x + 1][y - 2] == b)
        {
            x += 1;
            y -= 2;
            continue;
        }
        if (d[x + 1][y + 2] == b)
        {
            x += 1;
            y += 2;
            continue;
        }
        if (d[x - 2][y - 1] == b)
        {
            x -= 2;
            y -= 1;
            continue;
        }
        if (d[x - 2][y + 1] == b)
        {
            x -= 2;
            y += 1;
            continue;
        }
        if (d[x + 2][y - 1] == b)
        {
            x += 2;
            y -= 1;
            continue;
        }
        if (d[x + 2][y + 1] == b)
        {
            x += 2;
            y += 1;
            continue;
        }
    }
    --k;
    while (k >= 0)
    {
        cout << kq[k].first << " " << kq[k].second << endl;
        --k;
    }
}
void den(int x, int y, int k)
{

    d[x][y] = k;
    if (k == n * n)
    {
        x0 = x;
        y0 = y;
        lannguoc();
        kt = true;
        return;
    }
    if (kt == true)
        return;
    if (d[x - 1][y - 2] == 0 && x > 1 && y > 2)
    {
        den(x - 1, y - 2, k + 1);
        d[x - 1][y - 2] = 0;
    }
    if (d[x - 1][y + 2] == 0 && x > 1 && y + 2 <= n)
    {
        den(x - 1, y + 2, k + 1);
        d[x - 1][y + 2] = 0;
    }
    if (d[x + 1][y - 2] == 0 && y > 2 && y + 1 <= n)
    {
        den(x + 1, y - 2, k + 1);
        d[x + 1][y - 2] = 0;
    }
    if (d[x + 1][y + 2] == 0 && x + 1 <= n && y + 2 <= n)
    {
        den(x + 1, y + 2, k + 1);
        d[x + 1][y + 2] = 0;
    }
    if (d[x - 2][y - 1] == 0 && x > 2 && y > 1)
    {
        den(x - 2, y - 1, k + 1);
        d[x - 2][y - 1] = 0;
    }
    if (d[x - 2][y + 1] == 0 && x > 2 && y + 1 <= n)
    {
        den(x - 2, y + 1, k + 1);
        d[x - 2][y + 1] = 0;
    }
    if (d[x + 2][y - 1] == 0 && y > 1 && x + 2 <= n)
    {
        den(x + 2, y - 1, k + 1);
        d[x + 2][y - 1] = 0;
    }
    if (d[x + 2][y + 1] == 0 && x + 2 <= n && y + 1 <= n)
    {
        den(x + 2, y + 1, k + 1);
        d[x + 2][y + 1] = 0;
    }
}

int main()
{
    cin >> n;
    d[1][1] = 0;
    int b;
    pair<int, int> u;
    queue<pair<int, int>> q;
    q.push(make_pair(1, 1));
    den(1, 1, 1);
    return 0;
}
