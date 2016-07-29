//poj 3253
//#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<cstdio>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-5;
const double pi=acos(-1.0);
const int mod=1e8+7;
const LL INF=0x3f3f3f3f;

const int N=1e5+10;

LL a[N];
LL sum;
priority_queue<LL,vector<LL>,greater<LL> >q;

int main()
{
    LL u;
    int i,n;
    while(!q.empty())
        q.pop();
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%I64d",&u);
        q.push(u);
    }
    sum=0;
    while(!q.empty())
    {
        u=q.top();
        q.pop();
        if(!q.empty())
        {
            u=q.top()+u;
            q.pop();
            sum+=u;
            q.push(u);
        }
        else{
            printf("%I64d\n",sum);
            break;
        }
        //printf("sum=%d\n",sum);
    }
    return 0;
}

