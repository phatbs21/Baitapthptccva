#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, hello = "hello";
    auto dem = 0;
    cin >> s;
    for (auto i = 0; i < s.length(); i++)
        (s[i] == hello[dem]) ? dem++ : 0;
    cout << ((dem == hello.length()) ? "YES" : "NO");
}
