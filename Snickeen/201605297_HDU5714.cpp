/*
    在WA了很多发以后，终于在赛后听了群巨的讲解和看懂排在15的大神的代码，然后自己理解后补题
    TAT
*/
//#include<bits/stdc++.h>

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<iomanip>
#include<algorithm> 
#include<stdlib.h>
#include<math.h> 
#include<queue>
#include<stack>
#include<map>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)
#define repd(i,a,b) for(i=a;i>=b;i--)
#define db double
#define ld long double
#define FIN  freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define CC(a) memset(a,0,sizeof(a))

template<typename T> inline void in(T &x){
    x = 0; T f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}

struct TT{
	int edge,d,flag;
};TT tt[20005];
int n,m,i,j,k,l,t,s,r,mmax,mmin,num,ans;
LL MOD=1e9+7;
char aa[11];

int cmp(TT a,TT b){
	if(a.edge!=b.edge)return a.edge<b.edge;
	return a.flag>b.flag;
}

int main(){
//	FIN;FOUT;
	int ca=0,a,b,c,d;
	in(t);
	while(t--){
		in(n);j=k=0;
		for(i=1;i<=n;i++){
			in(a);in(b);in(c);in(d);
			r=a+c;l=b-c;
			if(r<l)continue;
			tt[j].edge=l;tt[j].d=d;tt[j].flag=1;j++;
			tt[j].edge=r;tt[j].d=d;tt[j].flag=-1;j++;
		}
		sort(tt,tt+j,cmp);
		mmax=ans=r=l=0;
		for(i=0;i<j;i++){
			if(tt[i].d==-1)l+=tt[i].flag;
			else r+=tt[i].flag;
			mmax=max(mmax,r);
			ans=max(ans,mmax+l);
		}
		printf("Case #%d:\n%d\n",++ca,ans); 
	}
	return 0;
}
