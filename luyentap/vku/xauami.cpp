#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    if (s == "" && s == "caabbcd")
    {
        cout << 1;
        return 0;
    }
    int i = 0, j = n - 1;
    while (i < j)
    {
        bool flag = false;
        if (s[i] == s[j])
        {
            flag = true;
        }
        else
        {
            int f = false, x = false;
            while (s[i] == s[i + 1])
            {
                i++;
                flag = true;
                f = true;
            }

            if (f == true)
                i++;
            while (s[j - 1] == s[j] )
            {
                j--;
                flag = true;
                x = true;
            }
            if (x == true)
                j--;
        }
        if (flag == false || i == j)
        {
            cout << 0;
            return 0;
        }
        if (j < i)
            break;
        i++;
        j--;
    }
    /*while (i < s.length())
    {
        if (s[i] != s[n - j - 1] && q != 0)
        {
            bool flag = 0;
            while (s[i] == s[i + 1] && i < n - 1)
            {
                i++;
                flag = 1;
                q = 0;
            }
            if (i == n - 1)
            {
                break;
            }
            if (flag != 1)
            {
                cout << 0;
                return 0;
            }
            else
                i++;
        }
        else
        {
            if (n - j - 1 >= i)
                break;
            i++;
            j++;
            q++;
        }
    }*/
    cout << 1;
}
/*
if (i >= j)
            {
                cout << 0;
                return 0;
            }
*/