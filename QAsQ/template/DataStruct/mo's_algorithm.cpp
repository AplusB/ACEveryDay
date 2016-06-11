struct Ask
{
    int l,r;
    int id;
    LL ans;
    void init(int i)
    {
        scanf("%d %d",&l,&r);
        id = i;
    }
};

Ask ask[maxn];

LL renew(LL ans,int pos,bool adder)
{

    if(adder)
    {
        //add
    }
    else
    {
        //del
    }
    return ans;
}

int main()
{
    scanf("%d %d",&n,&m);
    int unit = (int)sqrt(n*1.0);
    for(int i=0; i<m; i++)
    {
        ask[i].init(i);
    }
    sort(ask
         ,ask+m
         ,[=](Ask a,Ask b)
         {return a.l/unit!=b.l/unit?a.l<b.l:a.r<b.r;}
        );
    LL ans = zeroAns;
    for(int i=ask[0].l; i<=ask[0].r; i++)
    {
        ans = renew(ans,i,true);
    }
    ask[0].ans = ans;
    int st,ed;
    for(int i=1; i<m; i++)
    {
        st = min(ask[i].r,ask[i-1].r);
        ed = max(ask[i].r,ask[i-1].r);
        for(int id=st+1; id<=ed; id++)
            ans = renew(ans,id,ed==ask[i].r);
        st = min(ask[i].l,ask[i-1].l);
        ed = max(ask[i].l,ask[i-1].l);
        for(int id=st; id<ed; id++)
            ans = renew(ans,id,st==ask[i].l);
        ask[i].ans = ans;
    }
    sort(ask,ask+m,[](Ask a,Ask b){return a.id < b.id});
    for(int i=0; i<m; i++)
        printf(ask[i].ans);
    return 0;
}
