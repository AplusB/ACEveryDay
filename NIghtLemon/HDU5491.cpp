#include<bits/stdc++.h>
using namespace std;

int N,l,r;
long long n,ans;
long long a[40];

void calc()
{
	n++;
	int i=0,tot=0;
	long long t =1;
	memset(a,0,sizeof(a));
	while(n){
		tot+=n%2;
		a[i++] = n %2;
		n/=2;
	}
	if(tot>r){
		for(int i=0;i<=31;i++) if(a[i]==1){
			if(tot>=r){
				a[i] = 0;
				tot--;
			}
			if(tot<r){
				int j=i+1;
				a[j] ++;
				tot++;
				while(a[j]>1){
					a[j] = 0;
					tot--;
					j++;
					a[j]++;
				}
				break;
			}
		}
	
	}
	i=0;
	while(tot<l){
		if(a[i]==0){
			a[i] = 1;
			tot++;
		}
		i++;
	}
	ans = 0;
	for(int i=0;i<=31;i++){
		ans+=t*a[i];
		t=t+t;
	}
	
}

int main()
{
	int T,NT = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&N,&l,&r);
		n=N;
		calc();
		printf("Case #%d: %I64d\n",++NT,ans);
	}
	return 0;
}
