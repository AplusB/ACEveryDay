//CF670E - Correct Bracket Sequence Editor
#include<bits/stdc++.h>
#define LL long long
using namespace std;
char s[500010],t[500010];
int n, m, now;
int stk[500010],top,h[500010];
int pre[500010],nxt[500010];
int main(){
	cin >> n >> m >> now;
	scanf("%s%s", s + 1,t+1);
	for(int i = 1; i <= n; i ++){
		nxt[i] = i + 1;
		pre[i] = i - 1;
	}
	nxt[0] = 1;
	pre[n + 1] = 0;
	for(int i = 1; i <= n; i++){
		if(s[i]=='(')stk[++top]=i;
		else h[i]=stk[top--],h[h[i]]=i;
	}
	for(int T = 1; T <= m; T ++){
		if(t[T]=='L')now=pre[now];
		if(t[T]=='R')now=nxt[now];
		if(t[T]=='D'){
			int x=now,y=h[now];
			if(x>y)swap(x,y);
			x=pre[x],y=nxt[y];
			nxt[x]=y,pre[y]=x;
			now=y;
		}
		if(now==n+1)now=pre[n+1];
	}
	for(int i=nxt[0];i<=n;i=nxt[i])putchar(s[i]);
}
