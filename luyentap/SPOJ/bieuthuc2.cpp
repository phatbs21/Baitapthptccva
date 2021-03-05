#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10001], x[100001];
int checknhancong(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*')
        return 2;
    return 0;
}
int checkop(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    }
}
int tinh(string s)
{
    //tinh gia tri bieu thuc trong xau
    int i;
    stack<int> giatri;
    stack<char> ops;
    for (i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
            continue;
        else if (isdigit(s[i]))
        {
            int val = 0;
            while (i < s.length() &&
                   isdigit(s[i]))
            {
                val = (val * 10) + (s[i] - '0');
                i++;
            }
            giatri.push(val);
            i--;
        }
        else
        {
            while (!ops.empty() && checknhancong(ops.top()) >= checknhancong(s[i]))
            {
                int val2 = giatri.top();
                giatri.pop();

                int val1 = giatri.top();
                giatri.pop();

                char op = ops.top();
                ops.pop();

                giatri.push(checkop(val1, val2, op));
            }
            ops.push(s[i]);
        }
    }
    while (!ops.empty())
    {
        int temp1 = giatri.top();
        giatri.pop();

        int temp2 = giatri.top();
        giatri.pop();
        char op = ops.top();
        ops.pop();
        giatri.push(checkop(temp2, temp1, op));
    }
    return giatri.top();
}
void ghi()
{
    cout << a[1];
    for (int i = 2; i <= n; i++)
    {
        if (x[i] == 1)
            cout << "+" << a[i];
        if (x[i] == 0)
            cout << "-" << a[i];
        if (x[i] == 2)
            cout << "*" << a[i];
    }
    cout << endl;
}
bool kt()
{
    string tong = to_string(a[1]);
    for (int i = 2; i <= n; i++)
    {
        if (x[i] == 1)
        {
            tong = tong + " + " + to_string(a[i]);
        }
        if (x[i] == 0)
        {
            tong = tong + " - " + to_string(a[i]);
        }
        if (x[i] == 2)
        {
            tong = tong + " * " + to_string(a[i]);
        }
        //  cout << x[i] << " ";
    }
    // cout << tong << endl;
    return (tinh(tong) == m);
}
void thu(int i)
{

    if (i > n)
    {
        if (kt() == true)
            ghi();
        return;
    }
    for (int j = 2; j >= 0; j--)
    {
        x[i] = j;
        thu(i + 1);
    }
}
int main()
{
    //freopen("bieuthuc2", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    thu(2);
}
/*
5 0
4 1 2 3 10
*/