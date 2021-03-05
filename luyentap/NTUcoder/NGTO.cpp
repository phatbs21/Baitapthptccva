#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	long long int n, dem = 0;
	cin >> n;
	if (n < 2) 
	{
		cout << "NO";
	}
	else {
		for (int i = 2; i <= sqrt(n); i++)
			if (n % i == 0)
				dem += 1;
		if (dem == 0)
			cout << "YES";
		else
			cout << "NO";
	}
}
    