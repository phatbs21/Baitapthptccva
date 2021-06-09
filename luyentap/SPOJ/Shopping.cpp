//https://vn.spoj.com/PTIT/problems/P163PROI/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a, b, c;
    cin >> a >> b >> c;
    cout << min(min(min(a * 2 + b * 2, a + c + b), a + a + c + c), b + b + c + c);
}