#include <bits/stdc++.h>
using namespace std;
int main()
{
    string n;
    cin >> n;
    if (n[2] == '7' or n[1] == '7' or n[0] == '7')
        cout << "Yes";
    else
        cout << "No";
}