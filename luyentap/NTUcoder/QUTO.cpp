#include<iostream> 
using namespace std;

int main()
{
int x,y;
string a[5]={"A", "B", "C", "D", "E"};
cin >>x >>y;
if ((x<=3) | ((x==4)&(y%2==1)))
	{
		cout << -1;
		return 0;
		}
else
	if (y%2==0)
		cout << x-3; 
	else
		cout << x-2;
	cout << endl;
	cout << a[y/2];
	return 0;	
}