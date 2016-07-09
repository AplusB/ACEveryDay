//poj3616
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm> 
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <time.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double pi = acos(-1.0);
#define eps 1e-7
//#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PII pair<int,int>
vector<PII>s[1000010];
int dp[1000010];
bool cmp(PII a,PII b){
	return a.se<b.se;
}
int main()
{
	int n,m,k,l,r,v;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>l>>r>>v;
		l=max(0,l-k);
		s[r].pb(mp(l,v));
	}
	for(int i=1;i<=n;i++){
		sort(s[i].begin(),s[i].end(),cmp);
		dp[i]=max(dp[i],dp[i-1]);
		for(int j=0;j<s[i].size();j++){
			dp[i]=max(dp[i],dp[s[i][j].fi]+s[i][j].se);
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}
