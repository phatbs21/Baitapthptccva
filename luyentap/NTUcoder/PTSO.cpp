#include <iostream>
#include <cmath>
#define mod 1000007



using namespace std;

int main()
{
	long long n;
    long long a=0,b=0;
    long long c=1;
    cin >> n;
    for (int i =1 ; i<n ; i++)
    {
    	a=b;
    	b=c;
    	c=(a+b)%mod;
	}
    cout << c;
	return 0;
}
    