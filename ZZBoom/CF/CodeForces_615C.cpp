#include <bits/stdc++.h>
//#include<iostream>
//#include<cstdio>
//#include<math.h>
//#include<string.h>
//#include<algorithm>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-6;
const double pi=acos(-1.0);
const int mod=998244353;
const int INF=0x3f3f3f3f;

const int N=1200;

char s1[N*2];
char s2[N*2];
int dp[N*2][3];

int main()
{
    int flag,n,m,k,j,h1,h2;
    int num;
    int len1,len2;
    scanf("%s%s",s1,s2);
    len1=strlen(s1);len2=strlen(s2);
    flag=k=0;
    num=0;
    int s,t;
    int x;
    for(int i=0;i<len2;){
        int nextpos=-1;
        int p1,p2;
        for(int j=0;j<len1;j++){
            int k=j;
            int next=i;
            while(k<len1&&s1[k]==s2[next])
                k++,next++;
            if(next>nextpos){
                nextpos=next;
                p1=j+1;
                p2=k;
            }
        }
        for(int j=len1-1;j>=0;j--){
            int k=j;
            int next=i;
            while(k>=0&&s1[k]==s2[next]){
                next++;
                k--;
            }
            if(next>nextpos){
                nextpos=next;
                p1=j+1;
                p2=k+2;
            }
        }
        if(i==nextpos){
            puts("-1");
            return 0;
        }
        i=nextpos;
        dp[num][0]=p1;
        dp[num][1]=p2;
        num++;
    }
    printf("%d\n",num);
    for(int i=0;i<num;i++)
    {
        printf("%d %d\n",dp[i][0],dp[i][1]);
    }
    return 0;
}



