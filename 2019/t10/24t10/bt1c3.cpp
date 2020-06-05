#include <iostream>

using namespace std;

int main()
{
    int n,j,k;
    cin >> n;
    int a[n];
    for ( int i = 0; i < n ; i++ )
    {
        cin >> a[i];
    }
    unsigned char d[(n/8) + 1];
    for ( int i = 0; i <= (n/8); i++ )
    {
        d[i] = 0;
    }
    for ( int i = 0; i<= n-1; i++ )
    {
        d[a[i]/8] |= (1 <<(a[i]&7) );
    }
    for ( int i = 0 ; i <= (n/8); i++ )
    {
        if(d[i]!=255)
        {
            for (j = 0; j <= 7; j++ )
            {
                if((d[i] & (1 << j)) == 0)
                    break;
            }
            k = i*8+j;
            cout << k;
            return 0;
        }
    }
    return 0;
}
