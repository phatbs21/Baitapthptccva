#include <bits/stdc++.h>
using namespace std;
int n, dt;
int dem = 0;
int a[10000];
/** 
chuaw xong
 (*≧︶≦))(￣▽￣* )ゞ
 * **/
int xuli()
{
    deque<int> qmax,qmin;
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && abs(a[q.front()] - a[i]) > dt)
        {
            q.pop_front();
        }
        q.push_back(i);
        if (q.size() > dem)
            dem = q.size();
    }
    cout << dem;
    return 0;
}
int main()
{
    cin >> n >> dt;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    xuli();
}