#include <bits/stdc++.h>
using namespace std;
#define bignum string
void print_solution(__int128 n)
{
    string S;
    while (n != 0)
    {
        int digit = n % 10;
        n /= 10;
        S += to_string(digit);
    }
    reverse(S.begin(), S.end());
    cout << S << endl;
}

int main()
{
    int a, b, N;
    __int128 A, B;
    cin >> a >> b;
    A = a;
    B = b;
    __int128 tong = 0;

    for (int i = 2; i <= b; i++)
    {
        A *= a;
    }
    for (int i = 2; i <= a; i++)
    {
        B *= b;
    }
    if (A >= B)
        print_solution(A - B);
    else
    {
        cout << "-";
        print_solution(B - A);
    }
    return 0;
}
