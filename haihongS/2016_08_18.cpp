#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn=5e2+9;
const int inf=2e9+9;

ll num[2000];
ll ans[2000];

int pre();

int main()
{
    int t;
    scanf("%d",&t);
    pre();
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%lld\n",ans[n]);
        /*
        for(int i=1;i<=200;i++)
        {
            printf("%d %lld\n",i,ans[i]);
        }
        */
    }
    return 0;
}

int pre()
{
    num[0]=4,num[1]=3,num[2]=3,num[3]=5,num[4]=4,num[5]=4,num[6]=3;
    num[7]=5,num[8]=5,num[9]=4,num[10]=3;
    num[11]=6,num[12]=6,num[13]=8,num[14]=8,num[15]=7,num[16]=7;
    num[17]=9,num[18]=8,num[19]=8;
    num[20]=num[30]=6,num[40]=5,num[50]=5,num[60]=5,num[70]=7;
    num[80]=6,num[90]=6;
    for(int i=20;i<=99;i++)
    {
        if(i%10==0) continue;
        int tmp=i/10*10;
        num[i]=num[tmp]+num[i-tmp];
    }
    num[100]=7;
    num[1000]=8;


    memset(ans,0,sizeof(ans));
    ans[1]=3;
    for(int i=2;i<100;i++) 
        ans[i]=num[i]+ans[i-1];
    for(int i=100;i<=999;i++)
    {
        int now=i;
        int bai=now/100;
        ans[i]=num[bai]+num[100]+ans[i-1];
        if(i%100!=0)
            ans[i]+=num[i%100]+3;
    }
    ans[1000]=num[1]+num[1000]+ans[999];
    return 0;
}
