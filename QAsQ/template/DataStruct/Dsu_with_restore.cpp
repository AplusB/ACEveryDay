int fa[maxn],fval[maxn];
void Init(int n) {
    for(int i=0;i<=n;i++)
        fa[i]=i,fval[i]=0;
}
int fnd(int x) {
    while(x!=fa[x])x=fa[x];
    return x;
}
stack<pair<int*,int>>S;
void join(int x,int y,bool on) {
    x=fnd(x),y=fnd(y);
    if(x==y)return;
    if(fval[x]<=fval[y]) {
        if(on) S.push(make_pair(&fa[x],fa[x]));
        fa[x]=y;
        if(fval[x]==fval[y]) {
            if(on) S.push(make_pair(&fval[y],fval[y]));
            fval[y]++;
        }
    }
    else {
        if(on)S.push(make_pair(&fa[y],fa[y]));
        fa[y]=x;
    }
}
void back(bool on) {
    while(!S.empty()) {
        if(on) *S.top().first=S.top().second;
        S.pop();
    }
}
