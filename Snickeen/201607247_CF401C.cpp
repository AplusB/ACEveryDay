#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long LL;

int t,n,m,mmax;

void solve2(){
	int i,j,k,l,r,s;
	if(n-1>m||2*n+2<m){
		puts("-1");
		return ;
	}
	if(m<=n){
		for(i=1;i<n;i++)printf("01");
		puts(m<n?"0":"01");
	}
	else{
		r=m-n-1;
		k=1;i=0;
		for(;i<r;i++){
		    if(k){
		    	printf("11");
		    	k=0;
			}
			else printf("011");
	    }
	    for(;i<=n;i++){
	    	if(k){
		    	printf("1");
		    	k=0;
			}
			else printf("01");
		}
	}
	
}

int main()
{
	int i,j,k,l;
	scanf("%d%d",&n,&m);
	solve2();
	return 0;
}
