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
const int M=1e5+10;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int x,y,f=1;
    scanf("%d%d",&x,&y);
    while(1)
    {
        int ok=1,t;
        if(f==1)
        {
            t=min(x,2)*100;
            x-=min(x,2);
            t=(220-t)/10;
            if(y>=t)
            {
                y-=t;
            }
            else ok=0;
            if(!ok)
            {
                puts("Hanako");
                return 0;
            }
            f=0;
        }
        else
        {
            if(y>=22)
            {
                y-=22;
            }
            else if(y>=12)
            {
                y-=12;
                if(x>=1)
                {
                    x-=1;
                }
                else ok=0;
            }
            else if(y>=2)
            {
                y-=2;
                if(x>=2)
                {
                    x-=2;
                }
                else ok=0;
            }
            else ok=0;
            if(!ok)
            {
                puts("Ciel");
                return 0;
            }
            f=1;
        }
    }
    return 0;
}
