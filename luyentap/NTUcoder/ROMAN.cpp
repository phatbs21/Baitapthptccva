#include <bits/stdc++.h>

using namespace std;
int main()
{
    string a[13] = {"CM","CD","XC","XL","IX","IV","M","D","C","L","X","V",  "I"};
    int gt[13] = {900,400,90,40,9,4,1000,500,100,50,10,5,1};
    string s;
    getline(cin,s);
    int i, kq = 0;
    size_t x;
    for (i = 0; i < 13; i++)
    {
        x = s.find(a[i]);
        while (x != string::npos)
        {
            kq += gt[i];
            s.erase(x,a[i].length());
            x = s.find(a[i]);
        }
    }
    cout<<kq;
    return 0;
}
    