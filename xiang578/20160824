/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
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
int a[N],b[N];
char s[10000];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    gets(s);
    int n=strlen(s),op1=0,op2=0,sum=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]==' ') continue;
        if(s[i]=='?'&&i==0) op1++;
        if(s[i]=='+') op1++;
        if(s[i]=='-') op2++;
        if(s[i]>='0'&&s[i]<='9')
        {
            sum=sum*10+s[i]-'0';
        }
    }
    //printf("%d %d\n",op1,op2);
    int ok=1,need=sum+op2;
    if(op1*sum<sum+op2||op1>sum+op2*sum) ok=0;
    else
    {
        need=max(sum+op2,op1);
        for(int i=1;i<=op1;i++)
        {
            a[i]=min(sum,need-op1+i);
            need-=a[i];
            //printf("%d %d\n",i,a[i]);
        }
        need=max(sum+op2,op1)-sum;
        for(int i=1;i<=op2;i++)
        {
            b[i]=min(sum,need-op2+i);
            need-=b[i];
        }
    }
    if(ok==0) puts("Impossible");
    else
    {
        puts("Possible");
        int f=0,t=1,k=1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='?')
            {
                if(f)
                {
                    printf("%d",b[k]);
                    k++;
                }
                else
                {
                    printf("%d",a[t]);
                    t++;
                }
                f=0;
            }
            else
            {
                if(s[i]=='-') f=1;
                printf("%c",s[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
