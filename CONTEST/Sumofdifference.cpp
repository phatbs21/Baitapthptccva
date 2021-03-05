#include <bits/stdc++.h>
using namespace std;
long long int sum(long long int arr[], long long int n)
{
    long long int sum = 0;
    for (long long int i = n - 1; i >= 0; i--)
        sum += i * arr[i] - (n - 1 - i) * arr[i];
    return sum;
}
int main()
{
    long long int n;
    cin >> n;
    long long int arr[n + 1];
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cout << sum(arr, n);
}
