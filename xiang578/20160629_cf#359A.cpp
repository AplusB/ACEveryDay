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


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long m,ans,t;
    int n;
    scanf("%d%lld",&n,&m);
    ans=0;
    char s[1024];
    for(int i=0;i<n;i++)
    {
        scanf("%s%lld",s,&t);
        if(s[0]=='+')
        {
            m+=t;
        }
        else
        {
            if(t<=m)
            {
                m-=t;
            }
            else ans++;
        }

    }
     cout<<m<<" "<<ans<<endl;
    return 0;
}
