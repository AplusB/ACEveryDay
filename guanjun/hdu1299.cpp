/* ***********************************************
Author        :guanjun
Created Time  :2016/10/9 18:38:22
File Name     :hdu1299.cpp
************************************************ */
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 90001
#define INF 0x3f3f3f3f
#define maxn 10010
#define cle(a) memset(a,0,sizeof(a))
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;
priority_queue<int,vector<int>,greater<int> >pq;
struct Node{
	int x,y;
};
struct cmp{
    bool operator()(Node a,Node b){
        if(a.x==b.x) return a.y> b.y;
        return a.x>b.x;
	}
};

bool cmp(int a,int b){
    return a>b;
}
int n;
int prime[100000];
int vis[100000];
int num;
void init(){
	num=0;
	memset(vis,0,sizeof vis);
	int x=sqrt(1000000000)+1;
	for(int i=2;i<=x;i++){
		if(!vis[i]){
			prime[++num]=i;
			for(int j=i;j<=x;j+=i)vis[j]=1;
		}
	}
}
int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
	init();
	int t;
	cin>>t;
	for(int k=1;k<=t;k++){
		scanf("%d",&n);
		ll ans=1;
		int p,cnt;
		for(int i=1;i<=num;i++){
			p=prime[i];
			cnt=0;
			if(p*p>n)break;
			while(n%p==0){
				cnt++;
				n/=p;
			}
			ans*=(2*cnt+1);
		}
		if(n>1)ans*=3;
		printf("Scenario #%d:\n",k);
		printf("%lld\n\n",(ans+1)/2);
	}
    return 0;
}
