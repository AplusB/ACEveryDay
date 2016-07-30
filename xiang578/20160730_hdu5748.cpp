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
int b[N],c[N];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,n,t,m,k,cur;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        cur=1;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&t);
            if(i==0)
            {
                c[0]=t;
                b[0]=1;
                m=1;
                cur++;
            }
            else
            {
                k=lower_bound(c,c+m,t)-c;
                if(k==m)
                {
                    c[m]=t;
                    b[i]=m+1;
                    cur++;
                    m++;
                }
                else
                {
                    b[i]=k+1;
                    c[k]=t;
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            if(i) printf(" ");
            printf("%d",b[i]);
        }
        printf("\n");
    }
    return 0;
}
