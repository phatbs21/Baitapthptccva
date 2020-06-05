#include <iostream>
#include <cstdio>
using namespace std;
char info[5][5];
void read()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
            cin >> info[i][j];
    }
}
int arr[25];
int coins[5][5];
int _1Dto2D()
{
    int k = 1;
    int count = 0;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            coins[i][j] = arr[k];
            if (arr[k] == 1)
                count++;
            k++;
        }
    }
    return count;
}

char bk[5][5];
int x_xq[] = {+1, +0, -1, +0};
int y_xq[] = {+0, -1, +0, +1};
void latxu()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
            bk[i][j] = info[i][j];
    }
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (coins[i][j] == 1)
            {
                if (bk[i][j] == 'b')
                    bk[i][j] = 'w';
                else
                    bk[i][j] = 'b';
                for (int k = 0; k < 4; k++)
                {
                    int X = j + x_xq[k];
                    int Y = i + y_xq[k];
                    if (X >= 1 && X <= 4 && Y >= 1 && Y <= 4)
                    {
                        if (bk[Y][X] == 'b')
                            bk[Y][X] = 'w';
                        else
                            bk[Y][X] = 'b';
                    }
                }
            }
        }
    }
}

int check()
{
    char init = bk[1][1];
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (bk[i][j] != init)
                return 0;
        }
    }
    return 1;
}
int Ans = 25;

void sinhNP(int u)
{
    if (u > 16)
    {
        int x = _1Dto2D();
        latxu();
        if (check() == 1)
            Ans = min(Ans, x);
    }
    else
    {
        for (int z = 0; z <= 1; z++)
        {
            arr[u] = z;
            sinhNP(u + 1);
        }
    }
}
int main()
{
    freopen("COINT.inp", "r", stdin);
    read();
    sinhNP(1);
    if (Ans != 25)
        cout << Ans;
    else
        cout << "Impossible";
    return 0;
}
