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
string s;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,a[30],cnt1=0,cnt2=0;
    scanf("%d",&n);
    cin>>s;
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++)
    {
        if(a[s[i]-'a']==0)
        {
            a[s[i]-'a']++;
            cnt1++;
        }
        else
        {
            cnt2++;
        }
    }
    if(cnt1+cnt2>26) puts("-1");
    else printf("%d\n",cnt2);
    return 0;
}
