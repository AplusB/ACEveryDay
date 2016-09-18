const int maxn = 52345;
const int ROOT = 0;
int n;
vector<int> edge[maxn];


int fa[maxn],son[maxn],siz[maxn];
int deep[maxn],top[maxn],tid[maxn];
int _cnt;

void dffs(int st,int Fa,int Deep){
    siz[st] = 1,deep[st] = Deep;
    fa[st] = Fa,son[st] = -1;
    for(auto &x:edge[st]){
        if(x != Fa){
            dffs(x,st,Deep+1);
            siz[st] += siz[x];
            if(son[st] == -1 || siz[son[st]] < siz[x])
                son[st] = x;
        }
    }
}

void dfss(int st,int Top){
    top[st] = Top,tid[st] = _cnt++;
    if(son[st] != -1)
        dfss(son[st],Top);
    for(auto &x:edge[st]){
        if(son[st] != x && fa[st] != x){
            dfss(x,x);
        }
    }
}

void splite(){
    _cnt = 1;
    dffs(ROOT,-1,0);
    dfss(ROOT,ROOT);
}

int QUE_or_UPD(int x,int y){
    Info ix,iy;
    int tx = top[x],ty = top[y];
    while(tx != ty){
        if(deep[tx] < deep[ty])
            swap(tx,ty),swap(x,y),swap(ix,iy);
        ix = QU(root,tid[tx],tid[x]) + ix;
        x = fa[tx],tx = top[x];
    }
    if(deep[x] < deep[y])
        swap(x,y);
    return rev(ix) + rev(QU(root,tid[y]/*+1 (Vertex weight)*/,tid[x])) + iy;
}

