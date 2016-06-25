#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;
typedef long long ll;
int main()
{
        ll x,y,t;
        ll ans=0,sav=0;
        char ch[2];
        scanf("%lld %lld",&x,&ans);
        for(int i=0;i<x;i++)
        {
                scanf("%s %lld",&ch,&t);
                if(ch[0]=='+')
                {
                        ans+=t;
                }
                else
                {
                        if(ans<t) sav++;
                        else ans-=t;
                }
        }
        printf("%lld %lld",ans,sav);
        return 0;
}
