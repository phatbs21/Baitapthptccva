#include <bits/stdc++.h>
using namespace std;
bool kt(string n, int l)
{
    if (l < 3)
    {
        if (stoi(n) % 8 == 0)
            return true;
        reverse(n.begin(), n.end());
        if (stoi(n) % 8 == 0)
            return true;
        return false;
    }
    int hash[10] = {0};
    for (int i = 0; i < l; i++)
        hash[n[i] - '0']++;
    for (int i = 104; i < 1000; i += 8)
    {
        int temp = i;
        int a[10] = {0};
        a[temp % 10]++;
        temp = temp / 10;
        a[temp % 10]++;
        temp = temp / 10;
        a[temp % 10]++;
        temp = i;
        if (a[temp % 10] > hash[temp % 10])
            continue;
        temp = temp / 10;
        if (a[temp % 10] > hash[temp % 10])
            continue;
        temp = temp / 10;
        if (a[temp % 10] > hash[temp % 10])
            continue;
        return true;
    }
    return false;
}

int main()
{
    string s;
    cin >> s;
    int l = s.length();
    if (kt(s, l))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}