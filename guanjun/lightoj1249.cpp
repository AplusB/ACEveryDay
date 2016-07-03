/* ***********************************************
Author        :sdf
Created Time  :2016/1/28 13:55:27
File Name     :1249.cpp
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
#define maxn 10000+10
#define cle(a) memset(a,0,sizeof(a))
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;
struct node{
    int sum;
    char name[30];
}nod[maxn];
bool cmp(node a,node b){
    return a.sum<b.sum;
}
int main()
{
    #ifndef ONLINE_JUDGE
//  freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    int cas=0;
    while(t--){
        int n;
        cin>>n;
        int x,y,z;
        for(int  i=0;i<n;i++){
            cin>>nod[i].name>>x>>y>>z;
            nod[i].sum=x*y*z;
        }
        sort(nod,nod+n,cmp);
        if(nod[0].sum!=nod[n-1].sum){
            printf("Case %d: %s took chocolate from %s\n",++cas,nod[n-1].name,nod[0].name);
        }
        else{
            printf("Case %d: no thief\n",++cas);
        }
    }
    return 0;
}
