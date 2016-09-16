#include <bits/stdc++.h>
using namespace std;

int main(){
	int r=0,a[3],i,x,y,t;cin>>x>>y;
	a[0]=a[1]=a[2]=y;
	while(1){
		sort(a,a+3);if(a[0]==x)break;
		t= min(a[1]+a[2]-1,x);
		++r;a[0]=t;
	}
	cout<<r<<endl;
}
