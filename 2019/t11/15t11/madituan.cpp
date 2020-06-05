#include <iostream>

using namespace std;
int dem = 1, n;
int A[1000][1000];
int X[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int Y[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int xuat()
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
void dichuyen(int x, int y, int dem)
{
    int a, b;
    A[x][y] = dem;
    if (dem == (n * n))
    {
        xuat();
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        a = x + X[i];
        b = y + Y[i];
        if ((a >= 0) && (a < n) && (b >= 0) && (b < n) && (A[a][b] == 0))
        {
            dichuyen(a, b, dem + 1);
        }
    }
    A[x][y] = 0;
}

int main()
{
    cin >> n;
    dichuyen(0, 0, 1);
    return 0;
}
