/* ***********************************************
Author        :guanjun
Created Time  :2016/8/14 14:04:01
File Name     :hdu5832.cpp
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
char s[10000010];
int a[10000010];
int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int cas=0;
    while(scanf("%s",&s)!=EOF){
        int n=strlen(s);
        for(int i=0;i<n;i++)a[i]=s[i]-'0';
        for(int i=1;i<n;i++){
            a[i]=(a[i-1]*10+a[i])%10001;
        }
        if(a[n-1]){
            printf("Case #%d: NO\n",++cas);
        }
        else printf("Case #%d: YES\n",++cas);
    }
    return 0;
}
