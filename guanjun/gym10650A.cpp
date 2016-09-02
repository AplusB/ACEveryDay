/* ***********************************************
Author        :guanjun
Created Time  :2016/9/1 12:30:11
File Name     :2005a.cpp
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
#include <sstream>
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
string g;
map<string,int>mp;
//char s[300];
string p="LAST CASE";
string tmp[300];
vector<string>v;
ll dp[300][300];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int n;
	while(cin>>n&&n){
		mp.clear();
		v.clear();
		for(int i=1;i<=n;i++){
			cin>>g;
			mp[g]=1;
		}
		getchar();string s;
		while(getline(cin,s)&&s!=p){
			v.clear();
			istringstream is(s);
			string x,t;
			while(is>>t){
				//cout<<t<<endl;
				if(!mp[t])v.push_back(t);
			}
			x=v[0];
			for(int i=0;i<x.size();i++){
				x[i]=v[0][i]-'A'+'a';
			}
			//cout<<v.size()<<endl;
			cle(dp);
			int n=v.size();
			for(int i=0;i<v[1].size();i++){
				for(int j=x.size()-1;j>=0;j--){
					if(v[1][i]==x[j]){
						if(j==0)dp[1][j]++;
						else dp[1][j]+=dp[1][j-1];
					}
				}
			}
			//cout<<dp[1][3]<<" 123"<<endl;

			for(int i=2;i<n;i++){
				for(int t=0;t<v[i].size();t++){
					for(int j=x.size()-1;j>=i-1;j--){
						if(v[i][t]==x[j]){
							dp[i][j]+=dp[i-1][j-1]+dp[i][j-1];
							//cout<<dp[i][j]<<endl;
						}
					}
				}
			}
			ll ans=dp[n-1][x.size()-1];

			if(ans>0)cout<<v[0]<<" "<<"can be formed in "<<ans<<" "<<"ways"<<endl;
			else cout<<v[0]<<" is not a valid abbreviation"<<endl;
		}
	}
    return 0;
}
