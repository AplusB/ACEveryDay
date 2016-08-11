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
int f[32];
map<int,int>mp;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    f[0]=1;
    for(int i=1;i<=31;i++) f[i]=f[i-1]*2;
    int n,t;
    mp.clear();
    ll ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>t;
        for(int j=0;j<=30;j++)
        {
            ans+=mp[f[j]-t];
        }
        mp[t]++;
    }
    cout<<ans<<endl;
    return 0;
}
