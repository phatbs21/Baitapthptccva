#include <bits/stdc++.h>
using namespace std;int main(){int n, kq = 0;cin >> n;long int a[n];for (int i = 0; i < n; i++){cin >> a[i];}sort(a, a + n);for (int i = 0; i < n; i++){(a[i] == kq * kq) ? kq++ : 0;}cout << kq * kq;}
// BLACKBULLET :3 Hina_Imamura :3 Parrottos :3  I love you :3
