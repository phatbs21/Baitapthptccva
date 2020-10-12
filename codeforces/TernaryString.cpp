#include <bits/stdc++.h>
using namespace std;
bool check(string s)
{
    int a[4] = {0, 0, 0, 0};
    for (int i = 0; i < s.size(); i++)
    {
        a[s[i] - 48]++;
    }
    if (a[1] > 0 && a[2] > 0 && a[3] > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    /*
            int n = s.size();
        int Min = INT_MAX;
        bool kt = false;
        if (check(s) == false)
        {
            cout << 0 << "\n";
            continue;
        }
        for (int i = 3; i <= n; i++)
        {
            if (kt != true)
                for (int j = 0; j <= n - i; j++)
                {
                    string s1 = s.substr(j, i);
                    if (check(s1) == true)
                    {
                        cout << i << "\n";
                        kt = true;
                        break;
                    }
                }
            else
                break;
        }*/
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        long long int cnt = 0, cn = 0, ans = INT_MAX, sum = 0;
        cin >> s;
        int n = s.length();

        set<char> st, ss;
        for (int i = 0; i < n; i++)
            st.insert(s[i]);

        vector<pair<char, long long int>> v;
        if (st.size() == 3)
        {
            int k = 0;
            long long int one = 0, two = 0, thre = 0;

            long long int pos1 = 0, pos2 = 0, pos3 = 0;

            for (int i = 0; i < n; i++)
            {
                ss.insert(s[i]);
                if (s[i] == '1')
                    one++, pos1 = i;
                if (s[i] == '2')
                    two++, pos2 = i;
                if (s[i] == '3')
                    thre++, pos3 = i;
                if (ss.size() == 3)
                {
                    long long int mnpos = min({pos1, pos2, pos3});
                    long long int mxpos = max({pos1, pos2, pos3});
                    ans = min(ans, mxpos - mnpos);
                }
            }

            cout << ans + 1 << endl;
        }
        else
            cout << 0 << endl;
    }
}