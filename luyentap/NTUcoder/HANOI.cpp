#include <iostream>
using namespace std;
int k;
void Tower(int n, int &a, int &b, int &c)
{
    if (k == 0)
        return;
    if (n == 1)
    {
        a--;
        b++;
        k--;
    }
    else
    {
        Tower(n - 1, a, c, b);
        Tower(1, a, b, c);
        Tower(n - 1, c, b, a);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n >> k;
    int a = n;
    int b = 0;
    int c = 0;
    Tower(n, a, b, c);
    cout << a << " " << b << " " << c;
}