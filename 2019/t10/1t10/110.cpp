#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, k, s = 0;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        for (int j = i; j <= n; j++)
        {
            s = 0;
            for (int z = i; z <= j; z++)
            {
                s = s + a[z];
            }
            if (s == k)
            {
                cout << i + 1 << " " << j + 1;
                return 0;
            }
            if (s > k)
                break;
        }
    cout << "không tìm thhaays";
    return 0;
}