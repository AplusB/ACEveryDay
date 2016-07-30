//convert whit mu
int g[maxn];
memset(g,0,sizeof(g));
g[1] = 1;
for(int i=1;i<=n;i++){
    for(int j=i+i;j<=n;j+=i){
        g[j] -= g[i];
    }
}

// sum_n = \sum_1^n mu[i]
int sum[maxn];
LL solve(int n,int m)
{
    LL ans = 0;
    if(n > m)swap(n,m);
    for(int i = 1, last = 0; i <= n; i = last+1)
    {
        la = min(n/(n/i),m/(m/i));
        ans += (LL)(sum[last] - sum[i-1])*(n/i)*(m/i);
    }
    return ans;
}
