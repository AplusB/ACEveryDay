#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)
#define repd(i,a,b) for(i=a;i>=b;i--)
#define CC(a) memset(a,0,sizeof(a))

#define N 500000+7
int pre[N],last[N],cnt[N],n,m,t,s,r,i,j,k,l,pos;
char aa[N],op[N];
stack<int> q;

int main()
{
	scanf("%d%d%d%s%s",&n,&m,&k,aa+1,op+1);
	repu(i,1,n){
		if(aa[i]=='(')q.push(i);
		else {
			t=q.top();q.pop();
			cnt[t]=i;cnt[i]=t;
		}
	}
	repu(i,0,n)last[i]=i+1,pre[i]=i-1;
	pre[0]=last[n]=0;pos=k;
	repu(i,1,m){
		if(op[i]=='L'){pos=pre[pos];continue;}
		if(op[i]=='R'){pos=last[pos];continue;}
		
		if(aa[pos]=='('){
			t=cnt[pos];r=pre[pos];s=last[t];
			last[r]=s;pre[s]=r;
			if(s==0)pos=r;
			else pos=s;
		}
		else if(aa[pos]==')'){
			t=cnt[pos];r=pre[t];s=last[pos];
			last[r]=s;pre[s]=r;
			if(s==0)pos=r;
			else pos=s;
		}
	}
	for(i=0;i<=n&&last[i];){
		i=last[i];
		printf("%c",aa[i]);
	}puts("");
	return 0;
}
