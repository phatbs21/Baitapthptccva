#include <bits/stdc++.h>
using namespace std;
#define A 0
#define C 1
#define G 2
#define T 3
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(4, 0);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
            a[A]++;
        if (s[i] == 'C')
            a[C]++;
        if (s[i] == 'G')
            a[G]++;
        if (s[i] == 'T')
            a[T]++;
    }

    int dem = 0;
    int tb = n / 4;

    while (a[A] != a[G] && a[G] != a[C] && a[C] != a[T])
    {
        
    }
    cout << dem;
}