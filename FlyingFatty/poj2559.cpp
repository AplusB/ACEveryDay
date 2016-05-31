#include<map>
#include<set>
#include<math.h>
#include<time.h>
#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<stdio.h>
#include<cstring>
#include<string.h>
#include<algorithm>
#include<cstdlib>
using namespace std;

#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
#define ll rt<<1
#define rr rt<<1|1
#define LL long long
#define ULL unsigned long long
#define maxn 105000
#define eps 1e-6
#define input freopen("input.txt","r",stdin)
#define output freopen("output.txt","w",stdout)

int n,top;
struct node{
	LL h;
	int pos;
}s[maxn];

LL a[maxn],ans,tmp;

int main(){
	input;
	while(scanf("%d",&n),n){
		ans=0;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		a[n+1]=0;
		top=1;
		s[top].pos=1;
		s[top].h=a[1];
		for(int i=2;i<=n+1;i++)
			if (a[i]>=s[top].h){
				top++;
				s[top].pos=i;
				s[top].h=a[i];
			}
			else{
				while(a[i]<s[top].h){
					tmp=(i-1-s[top].pos+1)*s[top].h;
					if (ans<tmp) ans=tmp;
					top--;
				}
				top++;
				//s[top].pos=i;
				s[top].h=a[i];
			}
		printf("%lld\n",ans);
	}
	return 0;
}
