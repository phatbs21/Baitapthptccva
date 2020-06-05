#include <iostream>
using namespace std;
int n;
int x[10000];
int thu(int i)
{
    if (i > n)
    {
        for (int j = 1; j <= n; j++)
            cout << x[j];
        cout << endl;
        return 0;
    }
    for (int j = 0; j <= 1; j++)
    {
        x[i] = j;
        thu(i + 1);
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    thu(1);
    return 0;
}
