#include <bits\stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int r = n & (-n);
    int a = n + r;
    int b = a ^ n;
    b = b / r;
    b=b>>2;
    cout<<(a | b);
}