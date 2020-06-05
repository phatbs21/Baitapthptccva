#include <iostream>

using namespace std;

int main()
{
    string s;
    int i, tong = 0;
    cin >> s;
    for (i = 0; i <= s.length()-1; i++) tong += s[i] - 48;
    cout << tong;
    return 0;
}
    