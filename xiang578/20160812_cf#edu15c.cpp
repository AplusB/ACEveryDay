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
const int N=1e5+10;
ll a[N],b[N];
int n,m;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    ll ans=0;
    int l=1,r=1;
    for(int i=1;i<=n;i++)
    {
        while(r<m&&a[i]>b[r]) r++;
        //if(r==m+1) r++;
        l=r;
        while(l>1&&a[i]<b[l]) l--;
        //if(l==0) l=1;
        ans=max(ans,min(abs(a[i]-b[l]),abs(a[i]-b[r])));
        //cout<<r<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
