#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=50+9;
const ll inf=1e8+2;


int main()
{
    int n,b,p;
    while(~scanf("%d%d%d",&n,&b,&p))
    {
        int ans1=0,ans2=p*n;
        int num=n;
        while(num>1)
        {
            int tmp=(int)(log(num)/log(2));
            tmp=pow(2,tmp);
            ans1+=tmp*b+tmp/2;
            num=num-tmp+tmp/2;
        }
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}

