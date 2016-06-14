/*
    又错过一次，起来做一场虚拟赛。
    WA无数次。判断优先队列是否为空，最小值与当前值的大小比较。
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

template<typename T>inline void gn(T &xx){
	xx=0;T xf=1;char xch=getchar();
	while(!isdigit(xch)){if(xch=='-')xf=-1;xch=getchar();}
	while(isdigit(xch)){xx=xx*10+xch-'0';xch=getchar();}
	xx*=xf;
}

struct TT{
	int a;
	char ss[12];
};TT tt[300005];
int n,m,i,j,k,l,t,s,r,mmax,mmin,num,ans;
LL MOD=1e9+7;

priority_queue<int,vector<int>,greater<int> > q;

int main(){
//	FIN;FOUT;
    scanf("%I64d",&n);int cas=0;
    for(i=0;i<n;i++){
    	char aa[12];
    	scanf("%s",aa);
    	if(aa[0]=='i'){
    		scanf("%d",&m);
    		q.push(m);
    		strcpy(tt[cas].ss,aa);
    		tt[cas].a=m;
    		cas++;
		}
		else if(aa[0]=='r'){
			if(q.empty()) {
				strcpy(tt[cas].ss,"insert");
				tt[cas].a=1;
    		    cas++;
    		    q.push(1);
			}
			q.pop();
			strcpy(tt[cas].ss,aa);
    		cas++;
		}
		else if(aa[0]=='g'){
			scanf("%d",&m);
			
			while((!q.empty())&&(q.top()<m)){
				t++,q.pop();
				strcpy(tt[cas++].ss,"removeMin");
			}
			
			if(q.empty() || q.top()>m){
				strcpy(tt[cas].ss,"insert");
				tt[cas].a=m;
				cas++;
				q.push(m);
			}
			
			strcpy(tt[cas].ss,aa);
			tt[cas].a=m;
			cas++;
		}
	}
	
	printf("%d\n",cas);
    for(i=0;i<cas;i++){
    	if(tt[i].ss[0]=='i')printf("insert %d\n",tt[i].a);
    	else if(tt[i].ss[0]=='g')printf("getMin %d\n",tt[i].a);
    	else if(tt[i].ss[0]=='r')printf("%s\n",tt[i].ss);
	}
	return 0;
}
