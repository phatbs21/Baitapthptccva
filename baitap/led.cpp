#include <bits/stdc++.h> //172.69.135.180
using namespace std;
const int sovach[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int danhso[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
void reset()
{
    for (int i = 0; i <= 9; i++)
    {
        danhso[i] = 0;
    }
}
int danhdau(long long int n)
{
    n = n % 10;
    int so = sovach[n];
    for (int i = 0; i <= 9; i++)
    {
        if (i == n)
            continue;
        if (so < sovach[i])
        {
            danhso[i]++;
        }
    }
}
int dem(long long int n)
{
    int so = 0;
    do
    {
        so++;
        n /= 10;
    } while (n > 0);
    return so;
}
long long demsovach(int n)
{
    long long so = 0;
    do
    {
        so += sovach[n % 10];
        n = n / 10;
    } while (n > 0);
    return so;  
}
int timsolonhon(int n)
{
    int demso = 0;
    for (int i = 1; i <= dem(n); i++)
    {
        int so = n % 10;
        n = n / 10;
    }
    return demso;
}

int main()
{
    int v;
    long long int n;
    cin >> v >> n;
    if (v == 1)
    {
        cout << demsovach(n);
    }
    else if (v == 2)
    {
        cout << timsolonhon(n);
    }
}