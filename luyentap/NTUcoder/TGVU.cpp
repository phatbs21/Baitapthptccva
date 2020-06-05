#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a = n;
    for(int i = 0; i < a-1; ++i)
    {
        for(int d = 0; d < n; ++d)
        {
            cout << '*';
            if(d == n - 1)
                cout << endl;
        }
        n -= 1;
    }
    cout<<'*';
}