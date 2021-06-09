
#include <bits/stdc++.h>
using namespace std;
bool check(string s1, string s2)
{
    vector<int> a(26, 0), b(26, 0);
    for (int i = 0; i < s1.length(); i++)
    {
        // dem cac ki tu trong xau 1
        a[s1[i] - 97]++;
    }
    for (int i = 0; i < s2.length(); i++)
    {
        //dem cac ki tu trong xau 2
        b[s2[i] - 97]++;
    }
    for (int i = 0; i < 26; i++)
    {
        cout << char(i + 97) << " " << a[i] << " " << b[i] << "\n";
    }
    for (int i = 0; i < 26; i++)
    {
        // neu ki tu xuat hien trong xau nay ma khong xuat hien trong xau kia thi tra ve gia tri false
        if ((a[i] == 0 && b[i] > 0) || (a[i] > 0 && b[i] == 0))
            return false;
    }
    return true;
}
int main()
{
    int so = 2;
    vector<string> s(so);
    for (auto &i : s)
        cin >> i;
    for (int i = 0; i < so; i += 2)
    {
        if (check(s[i], s[i + 1]) == true)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}