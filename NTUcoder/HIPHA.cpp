#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int x = 1;
    for (int i = 1; i < n; i++)
    {
        if (A[i] == A[0])
            x++;
        else
            x--;
    }
    cout << abs(x);
    return 0;
}
