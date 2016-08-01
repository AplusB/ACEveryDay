//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-5;
const double pi=acos(-1.0);
const int mod=1e8+7;
const int INF=0x3f3f3f3f;
/*
要求程序实现一个涂色的程序
支持对区间[A,B]涂C的颜色和统计区间[A,B]的颜色种类
*/
const int N=200005;
struct asd{
    int z,y;
    int w;
};
asd q[N*4];

void Built(int z,int y,int num)
{
    q[num].z=z;
    q[num].y=y;
    if(z==y)
    {
        scanf("%d",&q[num].w);
        return;
    }
    int mid=(q[num].z+q[num].y)/2;
    Built(z,mid,2*num);
    Built(mid+1,y,2*num+1);
    q[num].w=q[num*2].w;
    if(q[2*num+1].w>q[num].w)
        q[num].w=q[2*num+1].w;
}

void update(int pp,int qq,int num)
{
    if(q[num].z>pp||pp>q[num].y)
        return;
    if(q[num].z==pp&&q[num].z==q[num].y)
    {
        q[num].w=qq;
        return;
    }
    update(pp,qq,2*num);
    update(pp,qq,2*num+1);
    q[num].w=max(q[2*num].w,q[2*num+1].w);
}

int query(int z,int y,int num)
{
    if(q[num].z==z&&q[num].y==y)
        return q[num].w;
    int mid=(q[num].z+q[num].y)/2;
    if(mid>=y)
        return query(z,y,2*num);
    else if(mid+1<=z)
        return query(z,y,2*num+1);
    else
        return max(query(z,mid,2*num),query(mid+1,y,2*num+1));
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        Built(1,n,1);
        char ss[3];
        int x,y;
        for(int i=1;i<=m;i++)
        {
            scanf("%s%d%d",ss,&x,&y);
            if(strcmp(ss,"Q")==0){
                printf("%d\n",query(x,y,1));
            }
            else{
                update(x,y,1);
            }
        }
    }
}



