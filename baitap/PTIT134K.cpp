#include <bits/stdc++.h>
#define quick                    \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
using namespace std;
int t, n = 1;
char x[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
string s = "";

int main()
{
    quick while (n != 0)
    {
        cin >> n;
        if (n == 0)
            exit(0);
        for (int i = 1; i <= n; i++)
        {
            string temp;
            cin >> temp;
            s += temp + " ";
        }

        string ans = "a";
        while (s.find(ans) != -1)
        {
            bool kt = true;
            for (int i = 0; i <= ans.length() - 1; i++)
                if (ans[i] != 'z')
                {
                    kt = false;
                    break;
                }
            if (kt == true)
            {
                for (int i = 0; i <= ans.length() - 1; i++)
                    ans[i] = 'a';
                ans += 'a';
            }
            else
            {
                int t = ans.length() - 1;
                if (ans[t] == 'z')
                {
                    ans[t] = 'a';
                    ans[t - 1] = x[(ans[t - 1] + 1 - 97) % 26];
                }
                if (ans.find("zz") != -1)
                    while (ans.find("zz"))
                    {
                        int vt;
                        vt = ans.find("zz");
                        ans[vt + 1] = 'a';
                        ans[vt] = 'a';
                        ans[vt - 1] = x[(ans[vt - 1] + 1 - 97) % 26];
                    }
                else
                    ans[t] = x[((int)(ans[t]) + 1 - 97) % 26];
            }
        }
        cout << ans << endl;
    }
}
