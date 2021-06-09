//https://codeforces.com/group/FLVn1Sc504/contest/274493/problem/J
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        priority_queue<long long int, vector<long long int>, greater<long long int>> a;
        long long int l = 0;
        for (long long int i = 0; i < n; i++)
        {
            long long int temp;
            cin >> temp;
            a.push(temp);
        }
        long long int kq = 0;
        while (a.size() > 1)
        {
            long long int x = a.top();
            a.pop();
            long long int y = a.top();
            a.pop();
            a.push(x + y);
            kq += x + y;
        }
        cout << kq << "\n";
    }
}