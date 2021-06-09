#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000000 + 7;
long long int n, a[100005], k = 1, kq = 0;
int main()
{
    cin >> n;
    a[k] = n;
    bool flag;
    long long int i, j, r, s;
    flag = false;
    while (flag == false)
    {
        kq %= MAX;
        bool kt = true;
        for (long long i = 1; i <= k; i++)
            if (a[i] == a[i - 1] - 1 || a[i] == a[i - 1])
            {
                kt = false;
                break;
            }
        if (kt == true)
        {
            kq++;
        }
        i = k;
        while (i > 0 && a[i] == 1)
            i--;
        if (i > 0)
        {
            a[i] = a[i] - 1;
            r = (k - i + 1) / a[i];
            s = (k - i + 1) % a[i];
            k = i;
            if (r > 0)
            {
                for (j = i + 1; j <= i + r; j++)
                    a[j] = a[i];
                k += r;
            }
            if (s > 0)
            {
                k += 1;
                a[k] = s;
            }
        }
        else
            flag = true;
    }
    cout << kq;
}