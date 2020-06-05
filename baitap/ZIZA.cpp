#include <bits/stdc++.h>
using namespace std;
int a[53][53];
int n, i = 1, j = 1, buoc=1, den = 1;

void diquaphai() //buoc 1
{
    if (j < n)
    {
        j++;
        den++;
        a[i][j] = den;
        buoc = 2;
    }
    else
    {
        buoc = 3;
    }
    return;
}
void cheoxuong() //buoc 2
{
    while (j > 1 && i < n)
    {
        i++;
        j--;
        den++;
        a[i][j] = den;
        buoc = 3;
    }
    if (buoc != 3)
        buoc = 4;
    return;
}
void dixuong() // buoc 3
{
    if (i < n)
    {
        i++;
        den++;
        a[i][j] = den;
        buoc = 4;
    }
    else
    {
        buoc = 1;
    }
    return;
}
void cheolen() //buoc 4
{
    while (i > 1 && j < n)
    {
        i--;
        j++;
        den++;
        a[i][j] = den;
        buoc = 1;
    }
    if (buoc != 1)
        buoc = 2;
    return;
}
int main()
{
    a[1][1] = 1;
    cin >> n;
    while (i != n or j != n)
    {
        if (buoc == 1)
            diquaphai();
        if (buoc == 2)
            cheoxuong();
        if (buoc == 3)
            dixuong();
        if (buoc == 4)
            cheolen();
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}