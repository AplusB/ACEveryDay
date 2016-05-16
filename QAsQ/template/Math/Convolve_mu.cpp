int g[150];
int n;

memset(g,0,sizeof(g));
g[1] = 1;
for(int i=1;i<=n;i++){
    for(int j=i+i;j<=n;j+=i){
        g[j] -= g[i];
    }
}
