#include <iostream>
using namespace std;

int a[20], kt;
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i <= 13; i++)
    {
        cin >> s;
        if (s[0] == 'T')
            a[8]++;
        else if (s[0] == 'J')
            a[9]++;
        else if (s[0] == 'Q')
            a[10]++;
        else if (s[0] == 'K')
            a[11]++;
        else if (s[0] == 'A')
            a[12]++; 
        else if (s[0] == '2')
            a[13]++;
        else
            a[int(s[0] - '2')]++;
    }  

    kt = 0;
    for (int i = 1; i <= 13; i++)
    {
        if (a[i] != 1)
        {
            kt = 1;
            break;
        }
    }
    if (kt == 0)
    {
        cout << "YES";
        return 0;
    }

    if (a[13] == 4)
    {
        cout << "YES";
        return 0;
    }

    for (int i = 1; i <= 13; i++)
    {
        kt = 0;
        for (int j = 0; j < 5; j++)
        {
            if (a[j + i] < 2)
            {
                kt = 1;
                break;
            }
        }
        if (kt == 0)
        {
            cout << "YES";
            return 0;
        }
    }

    kt = 0;
    for (int i = 1; i <= 13; i++)
    {
        if (a[i] >= 2)
            kt += a[i] / 2;
    }
    if (kt == 6)
    {
        cout << "YES";
        return 0;
    }

    cout << "NO";
    return 0;
}
