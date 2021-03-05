#include <bits/stdc++.h>
using namespace std;
ifstream fi("fairplay.inp");
ofstream fo("fairplay.out");
int main()
{
    int k, res1 = 0, res2 = 0;
    fi >> k;
    int m = k;
    int a = 2;
    if (k == 1)
    {
        fo << "1\n0";
        return 0;
    }
    int b;
    while (a * a <= k)
    {
        if (k % a == 0)
        {
            k /= a;
            b = 0;
            break;
        }
        else
            a++;
    }
    if (b == 0)
    {
        b=a+1;
        while (b * b <= k)
        {
            if (k % b == 0)
            {
                k /= b;
                res1 = 1;
            }
            else
                b++;
        }
        res2 = a * b;
        if (res2 == m
        {
            res1 = 2;
        }
        else
            res1 = 1;
    }
    else
    {
        
    }
    
    fo << res1 << "\n"
       << res2;
}