/* ***********************************************
Author        :Eopxt
Created Time  :Mon 23 May 2016 08:46:32 PM CST
File Name     :I.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <sstream>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;
#define rep(i,n) for (int i=1; i<=(n); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define For(i,s,t) for (int i=(s); i<=(t); i++)
#define FOR(i,s,t) for (int i=(s); i>=(t); i--)
#define foreach(j,x) for(int j=adj[x]; j>=0; j=E[j].nxt)
#define Foreach(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); it++)
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define mem(a,x) memset(a,x,sizeof(a))
#define X first
#define Y second
#define sqr(x) ((x)*(x))
#define C1(x) cout<<(x)<<endl
#define C2(x,y) cout<<(x)<<" "<<(y)<<endl
#define C3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
typedef long long lld;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector< pair<int,int> > VPII;

int n,d,a[60],s[500009];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    scanf("%d%d",&n,&d);
    rep(i,n) scanf("%d",&a[i]);
    mem(s,-1);
    s[0]=0;
    int maxS=0;
    rep(i,n) {
        For(j,0,maxS) 
            if (s[j]>=0 && s[j]!=i) {
                if (s[j+a[i]]<0) {
                    s[j+a[i]]=i;
                    maxS=max(maxS,j+a[i]);
                }
            }
    }
    int cur=0,cnt=0;
    while (cur<maxS) {
        int nxt=cur;
        For(i,cur+1,cur+d)
            if (s[i]>=0) nxt=i;
        if (cur==nxt) {
            printf("%d %d\n",cur,cnt);
            return 0;
        }
        else {
            cur=nxt;
            cnt++;
        }
    }
    printf("%d %d\n",cur,cnt);
    return 0;
}
