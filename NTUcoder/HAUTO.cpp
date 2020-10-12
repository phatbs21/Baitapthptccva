#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    stack<long long int> a;
    getline(cin, s);
    int x, y, i = 0, n = s.size();
    while (i < n)
    {
        if (s[i] == ' ')
        {
            i++;
            continue;
        }
        if (s[i] <= '9' && s[i] >= '0')
        {
            x = (int)s[i] - 48;
            y = i + 1;
            while (s[y] >= '0' && s[y] <= '9')
            {
                x = x * 10 + (int)s[y] - 48;
                y++;
            }
            i = y;
            a.push(x);
        }
        else
        {
            x = a.top();
            a.pop();
            y = a.top();
            a.pop();
            if (s[i] == '+')
                a.push(x + y);
            else if (s[i] == '-')
                a.push(y - x);
            else
                a.push(x * y);
            i++;
        }
    }
    cout << a.top();
}
