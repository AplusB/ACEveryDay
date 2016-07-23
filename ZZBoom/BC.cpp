#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-6;
const double pi=acos(-1.0);
const int mod=998244353;
const int INF=0x3f3f3f3f;

const int N=1e5+10;

char s[N];
bool v1[N];
int v2[N];
int p1,p2;

int main()
{
    int len;
    scanf("%d",&len);
    scanf("%s",s);
    int sum;
    int x;
    sum=0;
    memset(v1,0,sizeof(v1));
    for(int i=0;i<len;i++){
        x=s[i];
        if(!v1[x]){
            sum++;
            v1[x]=1;
        }
    }
    memset(v2,0,sizeof(v2));
    int ans=INF;
    int num=0;
    int flag=0;
    p1=p2=0;
    num=0;
    while(1){
        flag=0;
        while(num<sum&&p2<=len){
            x=s[p2];
            if(!v2[x])
                num++;
            v2[x]++;
            p2++;
            flag=1;
        }
        while(num==sum&&p1<=len){
            ans=min(ans,p2-p1);
            x=s[p1];
            v2[x]--;
            if(!v2[x])
                num--;
            p1++;
            flag=1;
        }
        if(!flag)
            break;
    }
    printf("%d\n",ans);
    return 0;
}
