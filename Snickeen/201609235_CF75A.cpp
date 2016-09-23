#include<iostream>
using namespace std;
int g(int x){int t=0,k=1;while(x){t+=x%10*k;if(x%10)k*=10;x/=10;}return t;}
int main(){
	int n,m;
	cin>>n>>m;
	cout<<(g(n)+g(m)==g(n+m)?"YES":"NO")<<endl;
	return 0;
}
