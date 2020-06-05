#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char a[5] = {'h', 'e', 'l', 'l', 'o'};
    int check = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        if (a[check] == s[i])
        {
            check++;
        }
    if (check == 5)
        cout << "YES";
    else
        cout << "NO";
}