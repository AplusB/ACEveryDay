/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.com
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=2048;
char s[100000+10];
int sum[100000+10];
int n,k;
int get(int st,int x) {
	int L=st,R=n,mid,ret=st;
	while(L<=R) {
		mid=(L+R)/2;
		if(sum[mid]>x) {
			R=mid-1;
		} else {
			ret=mid;
			L=mid+1;
		}
	}
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int ans;
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	sum[0]=0;
	ans=0;
	for(int i=1; i<=n; i++) {
		if(s[i-1]=='a') sum[i]=1+sum[i-1];
		else sum[i]=sum[i-1];
	}
	for(int i=1; i<=n; i++) {
		if(s[i-1]=='a')
			ans=max(ans,get(i,sum[i]+k-1)-i+1);
		else
			ans=max(ans,get(i,sum[i]+k)-i+1);
	}
	
	sum[0]=0;
	for(int i=1; i<=n; i++) {
		if(s[i-1]=='b') sum[i]=1+sum[i-1];
		else sum[i]=sum[i-1];
	}
	for(int i=1; i<=n; i++) {
		if(s[i-1]=='b')
			ans=max(ans,get(i,sum[i]+k-1)-i+1);
		else
			ans=max(ans,get(i,sum[i]+k)-i+1);
	}
	printf("%d\n",ans);
	return 0;
}
