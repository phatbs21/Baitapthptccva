#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double a, b;
    cin >> a >> b;
    long long s = 0, a1 = a, b1 = b;
    if (a1 < a)
        a1++;
    for (int i = a1; i <= b1; i++)
    {
        s += i;
    }
    cout << s;
}
