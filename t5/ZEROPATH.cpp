#include <bits/stdc++.h>
using namespace std;
bool ngto[100000];
void sangnguyento(long long int n)
{
    memset(ngto, true, n + 1);
    ngto[0] = ngto[1] = false;
    for (long long int p = 2; p * p <= n; p++)
    {
        if (ngto[p] == true)
        {
            for (long long int i = p * p; i <= n; i += p)
                ngto[i] = false;
        }
    }
}
int main()
{
    struct ZEROPATH
    {
        int a, b;
    };
    set<int> myset;
    set<int>::iterator it;
    ZEROPATH a[10000 + 2];
    int n;
    bool d[1000000];
    memset(d, false, sizeof(d));
    cin >> n;
    sangnguyento(n);
quaylai:
    int b[100000];
    int j = 1;
    int dem = 0;
    for (int i = 1; i <= n / 2 + 1; i++)
    {
        if (n % i == 0)
        {
            a[j].a = i;
            j++;
            dem++;
        }
    }
    j = 1;
    for (int i = 1; i <= dem; i++)
    {

        a[i].b = n / a[i].a;
        b[j] = (a[i].a - 1) * (a[i].b + 1);
        myset.insert(it, b[j]);
        d[b[j]] = true;
        j++;
    }
    sort( b + 1, b + dem + 1);
    if (dem <= 1)
    {
        while (ngto[b[dem]] == true && d[b[dem]] != true)
        {
            dem--;
        }
        if (dem !=0)
        {
        n = b[dem];
        goto quaylai;
    }
    cout << myset.size();
    for (auto qit = myset.begin(); qit != myset.end(); ++qit)
        cout << ' ' << *qit;
}