#include <bits/stdc++.h>
using namespace std;
int main()

{
    int n;
    cin>>n;
    n%=10;
    if (n==6 or n==0 or n==1 or n==8)
    {
        cout<<"pon";
    }
    else if (n==3)
    {
        cout<<"bon";
    }
    else
    {
        cout<<"hon";
    }
    
}