//http://bt10.thptccva.edu.vn/bai.php?ma=xaudx1
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    vector<int> a(27, 0);
    for (int i = 0; i < s.length(); i++)
    {
        int temp = s[i] - 'a';
        a[temp]++;
    }
    int dem = 0;
    for (int i = 0; i < 27; i++)
    {
        if (a[i] % 2 != 0)
            dem++;
    }
    if (dem % 2 != 0)
        cout << dem - 1;
    else
        cout << dem;
}