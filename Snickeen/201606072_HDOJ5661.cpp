/*
签到防踢
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
ll a,b,c,d,k,ans;
int main()
{
    for(int i=0;i<1000000;i++);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d %I64d %I64d %I64d",&a,&b,&c,&d);
        ans=0;
        for(ll tmp=ll(1)<<62;tmp>0;tmp>>=1)
        {
            if((a^b)&(c^d)&tmp)
            {
                ans+=(tmp<<1)-1;
                break;
            }
            else
                if(((a^b)|(c^d))&tmp)
                {
                    if((c^d)&tmp)
                    {
                        k=a;a=c;c=k;
                        k=b;b=d;d=k;
                    }
                    ans+=tmp;
                    if(c&tmp)b=tmp-1;
                    else a=0;
                }
            else
            {
                ans+=(a^c)&tmp;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
