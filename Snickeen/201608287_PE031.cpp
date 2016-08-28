#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
typedef long long LL;

const LL N=100000+5,M=700000+5;
LL MOD=1e9+7;
LL t,n,ans;
LL dp[10][N],a[11]={0,1,2,5,10,20,50,100,200},b[11],c[11];

int main()
{
//	freopen("PE031.out","w",stdout);
	LL i,j,k,l,ans=0;
	for(i=1;i<9;i++)dp[i][a[i]]=1;
	for(i=1;i<N;i++)dp[1][i]=1;
	for(i=2;i<9;i++){
		for(j=a[i];j<N;j++){
			for(k=1;k<=i;k++){
				dp[i][j]+=dp[k][j-a[i]];
				dp[i][j]%=MOD;
			}
		}
	}
	for(i=1;i<N;i++){
		for(j=1;j<=8;j++){
			dp[0][i]+=dp[j][i];
		}
		dp[0][i]%=MOD;
	}
	
	cin>>t;
	while(t--){
		cin>>n;
		cout<<dp[0][n]<<endl;
	}
	return 0;
}
