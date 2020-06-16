#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a[256], b[256];
    int n, v;
    cin >> n;
    string s;
    int time;
    a['_'] = 10;
    b['_'] = 1;
    a['.'] = a[','] = a['?'] = a['!'] = 1;
    b['.'] = 1;
    b[','] = 2;
    b['?'] = 3;
    b['!'] = 4;

    for (int i = 97; i <= 111; i++)
    {
        a[i] = (i - 91) / 3;
        b[i] = ((i - 91) % 3 + 1);
    }
    for (int i = 112; i <= 122; i++)
    {

        if (i == 116 || i == 117 || i == 118)
        {
            a[i] = (i - 92) / 3;
            b[i] = ((i - 89) % 3 + 1);
        }
        else
        {
            a[i] = (i - 83) / 4;
            b[i] = ((i - 76) % 4 + 1);
        }
    }
    a['s'] = 7;
    b['w'] = 1;
    b['x'] = 2;
    b['y'] = 3;
    b['z'] = 4;
    for (int i = 48; i <= 57; i++)
    {
        a[i] = i - 48;
        if (i == 48)
        {
            a[i] = 10;
            b[i] = 2;
        }
        else if ((i > 48 && i < 55) || (i == 56))
        {
            b[i] = 4;
        }
        else
        {
            b[i] = 5;
        }
    }
b['1']=5;

    for (int q = 1; q <= n; q++)
    {
        time = 0;
        v = 1;
        cin >> s;
        for (int i = 0; i < s.length(); i++)
        {
            if (a[s[i]] != v)
            {
                time++;
                v = a[s[i]];
            }
            time += b[s[i]];
        }
        cout << time << endl;
    }
}