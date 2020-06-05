#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long int k, t;
    string a;
    cin >> a >> k;
    for (int i = 0; i < a.size(); i++)
    {
        t = (a[i] - k);
        if (t < 97)
            t += 26;
        cout << char(t);
    }
}