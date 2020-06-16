#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    int kq = 0, a = 0, dem;
    cin >> s;
    if (s.length() < 2)
    {
        cout << s.length() << endl;
        return 0;
    }
    for (int i = 0; i < s.length(); i++)
    {
        dem = 1;
        for (int j = i - 1; j >= a; j--)
        {
            if (s[j] == s[i])
            {
                a = j + 1;
                break;
            }
            dem++;
        }
        kq = max(kq, dem);
    }
    cout << kq;
}
