//hdu5023 A Corrupt Mayor's Performance Art
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const LL mod=1e9+7;
const double eps=1e-9;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
#define lson l , mid , rt << 1
#define rson mid + 1 , r , rt << 1 | 1
const int maxn = 1100017;
LL add[maxn<<2];
LL sum[maxn<<2];
void PushUp(int rt)
{
    sum[rt] = sum[rt<<1] | sum[rt<<1|1];
}
void PushDown(int rt,int m)
{
    if(add[rt])
    {
        add[rt<<1] = add[rt];
        add[rt<<1|1] = add[rt];
        sum[rt<<1] = add[rt] ;
        sum[rt<<1|1] = add[rt] ;
        add[rt] = 0;
    }
}
void build(int l,int r,int rt)
{
    add[rt] = 0;
    if (l == r)
    {
        sum[rt]=2;
        return ;
    }
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);
}
void update(int L,int R,int c,int l,int r,int rt)
{
    if (L <= l && r <= R)
    {
        add[rt] =1<<(c-1);
        sum[rt] =1<<(c-1);
        return ;
    }
    PushDown(rt , r - l + 1);
    int mid = (l + r) >> 1;
    if (L <= mid)
        update(L , R , c , lson);
    if (mid < R)
        update(L , R , c , rson);
    PushUp(rt);
}
LL query(int L,int R,int l,int r,int rt)
{
    if (L <= l && r <= R)
    {
        return sum[rt];
    }
    PushDown(rt , r - l + 1);
    int mid = (l + r) >> 1;
    LL ret = 0;
    if (L <= mid)
        ret |= query(L , R , lson);
    if (mid < R)
        ret |= query(L , R , rson);
    return ret;
}
int main()
{
    int N , Q;
    int a , b , c;
    while(scanf("%d%d",&N,&Q))
    {
        if(N==0 && Q==0)
            break;
        build(1 , N , 1);
        while(Q--)
        {
            char op[2];
            scanf("%s",op);
            if(op[0] == 'Q')
            {
                scanf("%d%d",&a,&b);
                LL tt=query(a , b , 1 , N , 1);
                LL flag = 0;
                for(int i=1; i<=30; i++)
                {
                    if(tt>>(i-1)&1 && flag==0)
                    {
                        printf("%d",i);
                        flag = 1;
                    }
                    else if(tt>>(i-1)&1)
                        printf(" %d",i);
                }
                printf("\n");
            }
            else
            {
                scanf("%d%d%d",&a,&b,&c);
                update(a , b , c , 1 , N , 1);
            }
        }
    }
    return 0;
}
