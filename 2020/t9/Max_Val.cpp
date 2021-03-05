#include <bits/stdc++.h>
using namespace std;
#define NAME "Max_Val"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");
int n, p, q;
char p_m;
string s, s_item;
void get_operand()
{
    if (q > 0)
        p_m = s[q - 1];
    while (q < n && s[q] > 45)
        ++q;
    s_item = s.substr(p, q - p);
    p = ++q;
}
int New_Neg(string x)
{
    int l = x.size();
    int m = l - 1;
    for (int i = 0; i < l - 1; i++)
    {
        if (x[i] > x[i + 1])
        {
            m = i;
            break;
        }
    }
    x.erase(m, 1);
    return stoi(x);
}

int main()
{
    fi >> s;
    n = s.size();
    vector<char> op(n);
    vector<string> a(n);
    vector<int> val(n), pw(10);
    pw[0] = 1;
    for (int i = 1; i < 10; i++)
    {
        pw[i] = pw[i - 1] * 10;
    }
    p_m = '+';
    int k = 0;
    p = 0, q = p;
    while (p < n)
    {
        get_operand();
        a[k] = s_item;
        val[k] = stoi(s_item);
        op[k++] = p_m;
        q = p;
    }
    int64_t c = 0;
    for (int i = 0; i < k; i++)
    {
        if (op[i] == '+')
            c += val[i];
        else
            c -= val[i];
    }
    int64_t ans = c;
    for (int i = 1; i < k; i++)
    {
        if (op[i] == '-' && op[i - 1] == '-')
        {
            int r = New_Neg(a[i]);
            int64_t rn = c + val[i] - r;
            if (ans < rn)
                ans = rn;
        }
        else if (op[i - 1] == '+')
        {
            int m = a[i].size();
            int64_t tg = (int64_t)val[i - 1] * (pw[m] - 1) + val[i];
            if (op[i] == '-')
                tg += c + val[i];
            else
                tg += c - val[i];
            if (ans < tg)
                ans = tg;
        }
    }
    fo << ans;
    cout << "Time:" << clock() / (double)1000 << " sec";
}