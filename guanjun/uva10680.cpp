/* ***********************************************
Author        :guanjun
Created Time  :2016/7/11 18:33:33
File Name     :uva10680.cpp
************************************************ */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <list>
#include <deque>
#include <stack>
#define ull unsigned long long
#define ll long long
#define mod 90001
#define INF 0x3f3f3f3f
#define maxn 1000010
#define cle(a) memset(a,0,sizeof(a))
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;

bool cmp(int a,int b){
    return a>b;
}
int used[maxn];
int prime[100000];
int p=0;
void Set(){
	cle(used);
	p=0;
	for(int i=2;i*i<=maxn;i++){
		if(used[i]==0){
			prime[++p]=i;
			for(int j=i;j<=maxn;j+=i){
				used[j]=1;
			}
		}
	}
	for(int i=7;i<=maxn;i+=2){
		if(!used[i])prime[++p]=i;
	}
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
	int n;
	Set();
	while(cin>>n&&n){
		int cnt2=0,cnt5=0;
		for(int i=2;i<=n;i*=2)cnt2++;
		for(int i=5;i<=n;i*=5)cnt5++;
		int ans=1;
		for(int i=1;i<=cnt2-cnt5;i++){
			ans=(ans*2)%10;
		}
		for(int i=1;i<=p;i++){
			int x=prime[i];
			if(x>n)break;
			//cout<<x<<endl;
			if(x==2||x==5)continue;
			for(ll j=x;j<=n;j*=x){
				ans=(ans*x)%10;
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}
