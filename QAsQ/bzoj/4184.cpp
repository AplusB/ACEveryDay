#include<vector>
#include<map>
#include<stack>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 512345;

vector<int> oper[maxn * 2];

#define root 1,n
#define lson l,m
#define rson m+1,r
#define Mid int m = (l + r) >> 1
#define Now int l,int r

int ID(int l, int r) {  
    return l + r | (l != r);  
}
void insert(Now,int il,int ir,int v){
    //printf("ins lr = %d %d ilir = %d %d v = %d\n",l,r,il,ir,v);
    int o = ID(l,r);
    if(il <= l && r <= ir){
        oper[o].push_back(v);
        return;
    }
    Mid;
    if(il <= m) insert(lson,il,ir,v);
    if(m+1<=ir) insert(rson,il,ir,v);
}

struct Info{
    int bas[32];
    void init(){
        memset(bas,0,sizeof(bas));
    }
    void add(int x){
        for(int i = 31;i>=0;i--) {
            if((x>>i)&1) {
                if(bas[i]) x^=bas[i];
                else {
                    bas[i]=x;
                    break;
                }
            }
        }
    }
    int que(){
        int ans = 0;
        for(int i = 31;i>=0;i--) ans = max(ans,ans^bas[i]);
        return ans;
    }
    void cpy(Info & v){
        for(int i = 0 ; i <= 31; i ++){
            bas[i] = v.bas[i];
        }
    }
}info[50];
int nex[50],head,tail;
void init(){
    head = 0,tail = 50-1;
    for(int i = 0 ; i < 50 ; i ++)
        nex[i] = i + 1;
    nex[tail] = -1;
}
int newInfo(){
    info[head].init();
    int ret = head;
    head = nex[head];
    return ret;
}
void deleteInfo(int st){
    nex[tail] = st;
    nex[st] = -1;
    tail = st;
}

stack<int> S;
void dfs(Now){
    int o = ID(l,r),st = newInfo();
    info[st].cpy(info[S.top()]);
    S.push(st);
    for(vector<int>::iterator it = oper[o].begin(); it != oper[o].end();it++) 
        info[st].add(*it);
    if(l == r) printf("%d\n",info[st].que());
    else{
        Mid;
        dfs(lson),dfs(rson);
    }
    deleteInfo(st);
    S.pop();
}

map<int,int> M;

int main(){
    int n;
    scanf("%d",&n);
    int x;
    for(int i = 1; i <= n ; i ++){
        scanf("%d",&x);
        if(x > 0) M[x] = i;
        else{
            insert(root,M[-x],i-1,-x);
            M.erase(-x);
        }
    }
    for(map<int,int>::iterator ite = M.begin();ite != M.end();ite++) 
        insert(root,ite->second,n,ite->first);
    init();
    int rot = newInfo();
    S.push(rot);
    dfs(root);
    return 0;
}
