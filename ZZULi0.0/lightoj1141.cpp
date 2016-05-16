#include <bits/stdc++.h>
#define ll __int64
#define N 1000000+5
using namespace std;

int prim[1200],cnt[200],l,s,t,mmin;
bool ans;
map<int,bool>hashs;

void init()
{
    memset(prim,0,sizeof(prim));
    prim[0] = prim[1] = 1;
    for(int i = 2; i <= 1000; i++)
    {
        if(!prim[i])
            for(int j = i*2; j <= 1000; j += i)
                prim[j] = 1;
    }
    l = 0;
    for(int i = 2; i <= 1000; i++)
        if(!prim[i]) cnt[l++] = i;

}

struct nodes
{
    int cur,step;
};
void bfs()
{
    queue<nodes>Q;
    nodes cur,tmp;
    cur.step = 0;
    cur.cur = s;
    Q.push(cur);
    while(!Q.empty())
    {
        cur = Q.front();
        Q.pop();
        if(cur.cur > t || hashs[cur.cur]) continue;
        if(cur.cur == t)
        {
            mmin = min(mmin,cur.step);
            continue;
        }
        hashs[cur.cur] = true;
        for(int i = l-1; i >= 0; i--)
        {
            if(cur.cur > cnt[i] && cur.cur % cnt[i] == 0 && !hashs[cur.cur + cnt[i]] )
            {
                tmp.cur = cur.cur+cnt[i];
                tmp.step = cur.step + 1;
                Q.push(tmp);
            }
        }
    }

}

void solve()
{
    init();
    ans = false;
    scanf("%d %d",&s,&t);
    mmin = 501;
    hashs.clear();
    bfs();
    if(mmin != 501)
        printf("%d\n",mmin);
    else
        printf("-1\n");
}

int main(void)
{
    int t,cnt = 0;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d: ",++cnt);
        solve();
    }
}
