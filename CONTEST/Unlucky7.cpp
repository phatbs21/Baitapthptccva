#include <bits/stdc++.h>
using namespace std;
int decToOctal(int n)
{
    int octalNum[300001];
    int i = 0;
    while (n != 0)
    {
        octalNum[i] = n % 8;
        n = n / 8;
        i++;
    }
    int a = 0;
    for (int j = i - 1; j >= 0; j--)
        a = a * 10 + octalNum[j];
    return a;
}

bool check(int n)
{
    string s = to_string(n);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '7')
            return false;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    int dem = 0;
    for (int i = 1; i <= n; i++)
    {
        if (check(decToOctal(i)) == true && check(i) == true)
            dem++;
    }
    cout << dem;
}