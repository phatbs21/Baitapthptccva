#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    istringstream iss(s);
    int val, j;
    while (iss >> val)
    {
        j++;
    }
    cout << j - 1;
}