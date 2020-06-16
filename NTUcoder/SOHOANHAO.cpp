#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;	int z=0;
	cin>>n;
	for(int i=1;i<n;i++){
	
		if(n%i==0) z+=i;
		
	}
	if(z==n) cout<<"YES";
	else cout<<"NO";
	return 0;
}