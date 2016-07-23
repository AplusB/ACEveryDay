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
char s[10000000+10];
int a[10];
string ans;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,t,f=0;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%s",s);
        int len=strlen(s);
        memset(a,0,sizeof(a));
        f=0;
        ans="";
        for(int i=0; i<len; i++)
        {
            a[s[i]-'0']++;
            if(s[i]-'0'>=1) f++;
        }
        if(f<=1) printf("Uncertain\n");
        else
        {
            for(int i=1; i<10; i++)
            {
                if(a[i])
                {
                    t=i;
                    a[i]--;
                    break;
                }
            }

            for(int i=0; i<10; i++)
            {
                for(int j=0; j<a[i]; j++)
                {
                    int k=t+i;
                    t=k/10;
                    k%=10;
                    ans+=k+'0';
                    //cout<<ans<<endl;
                }
            }
            if(t!=0) ans+=t+'0';
            len=ans.size();
            for(int i=len-1; i>=0; i--)
            {
                printf("%c",ans[i]);
            }
            printf("\n");
        }

    }
    return 0;
}
