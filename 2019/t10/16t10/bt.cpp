#include <bits\stdc++.h>
using namespace std;
int main()
{
    int y, m, d;
    cin >> y >> m >> d;
    int c = y / 100;
    y = y % 100;
    int w = d + 13 * (m + 1) / 5 + y + y / 4 + c / 4 - 2 * c;
    cout << "So du: " << w % 7;
}