#include<iostream>
using namespace std;
int main() {
	int n,k,i,j,x[1000];
	cin>>n;
	for(i=0; i<=n; i++) {
		x[i]=i;
	}
	while(1==1) {
		for  (int h=1; h<=n; h++) {
		cout<<x[h];
	}
	cout<<endl;
		k=n-1;
		while(x[k]>x[k+1]) {
			k--;
		}
		if(k<1) break;
		j=n;
		while(x[k]>x[j]) {
			j--;
		}
		swap(x[k],x[j]);
		i=k+1;
		j=n;
		while(i<j) {
			swap(x[i],x[j]);
			i++;
			j--;
		}
	}
    
}
