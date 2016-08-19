/* ***********************************************
Author        :guanjun
Created Time  :2016/8/18 14:20:26
File Name     :hdu5862.cpp
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
#define maxn 100010
#define cle(a) memset(a,0,sizeof(a))
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;
priority_queue<int,vector<int>,greater<int> >pq;
struct node{
    int type,x,y,y2;
}nod[maxn*2];
int a[maxn*2];
int Maxn;
bool cmp(node a,node b){
    if(a.x==b.x)return a.type<b.type;
    return a.x<b.x;
}
int c[maxn*2];
int lowbit(int i){
    return i&(-i);
}
void add(int i,int d){
    while(i<=Maxn){
        c[i]+=d;
        i+=lowbit(i);
    }
}
int sum(int i){
    int ans=0;
    while(i>0){
        ans+=c[i];
        i-=lowbit(i);
    }
    return ans;
}
map<int,int>mp;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        mp.clear();
        int n,tot=0;
        int all=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int x1,x2,y1,y2;
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            if(x1==x2){
                if(y1>y2)swap(y1,y2);
                nod[tot++]={1,x1,y1,y2};
                a[all++]=y1;
                a[all++]=y2;
            }
            else{
                if(x1>x2)swap(x1,x2);
                nod[tot++]={0,x1,y1,1};
                nod[tot++]={0,x2+1,y2,-1};
                a[all++]=y1;
            }
        }
        sort(a+1,a+all);
        int cnt=0;
        for(int i=1;i<=all;i++){
            if(!mp[a[i]])mp[a[i]]=++cnt;
        }
        Maxn=cnt+1;
        sort(nod,nod+tot,cmp);
        ll ans=0;
        cle(c);
        for(int i=0;i<tot;i++){
            if(nod[i].type==0){
                int xpy=mp[nod[i].y];
                add(xpy,nod[i].y2);
            }
            else{
                int xpl=mp[nod[i].y];
                int xpr=mp[nod[i].y2];
                ans+=sum(xpr)-sum(xpl-1);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
