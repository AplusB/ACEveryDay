#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int Node = 5e4 + 5;
const int bk = sqrt(Node);
char str[maxn], tmp[maxn];
int nxt[maxn];

void get_next(const char T[], int len){
    int i = 0, j = -1;
    nxt[i] = -1;
    while(i < len){
        if(j == -1 || T[i] == T[j]){
            i++;
            j++;
            nxt[i] = j;
        }else j = nxt[j];
    }
}

int kmp(const char S[], const char T[]){
    int lenS = strlen(S), lenT = strlen(T);
    get_next(T, lenT);
    int i = 0, j = 0, ans = 0;
    while(i < lenS){
        if(j == -1 || S[i] == T[j]){
            i++;
            j++;
        }else j = nxt[j];
        if(j == lenT) ans++;
    }
    return ans;
}

struct AC{
    int nxt[Node][26];
    int fail[Node];
    int rt, tol;

    vector < int > G[Node];
    int L[Node], R[Node], cnt;
    int sum[Node], sum2[Node];

    int newNode(){
        ++tol;
        memset(nxt[tol], 0, sizeof nxt[tol]);
        return tol;
    }

    void init(){
        memset(nxt[0], 0, sizeof nxt[0]);
        tol = cnt = 0;
        rt = newNode();
        for(int i = 0; i < Node; i++) G[i].clear();
        memset(sum, 0, sizeof sum);
        memset(sum2, 0, sizeof sum2);
    }

    void ins(const char s[]){
        int p = rt;
        for(int i = 0, c; s[i]; i++){
            c = s[i] - 'a';
            if(!nxt[p][c])
                nxt[p][c] = newNode();
            p = nxt[p][c];
        }
    }

    void build(){
        queue < int > que;
        for(int i = 0; i < 26; i++){
            if(!nxt[rt][i])
                nxt[rt][i] = rt;
            else{
                fail[nxt[rt][i]] = rt;
                que.push(nxt[rt][i]);
            }
        }
        while(!que.empty()){
            int u = que.front(); que.pop();
            G[fail[u]].push_back(u);
            for(int i = 0; i < 26; i++){
                if(!nxt[u][i])
                    nxt[u][i] = nxt[fail[u]][i];
                else{
                    fail[nxt[u][i]] = nxt[fail[u]][i];
                    que.push(nxt[u][i]);
                }
            }
        }
    }

    void dfs(int u){
        L[u] = ++cnt;
        for(int i = 0; i < G[u].size(); i++){
            dfs(G[u][i]);
        }
        R[u] = cnt;
    }

    int getPos(int l, int r){
        int p = rt;
        for(int i = l; i <= r; i++){
            p = nxt[p][str[i] - 'a'];
        }
        return p;
    }

    void update(int l, int r, int p, int val){
        for(int i = l; i <= r; i++){
            p = nxt[p][str[i] - 'a'];
            sum[L[p]] += val;
            sum2[L[p] / bk] += val;
        }
    }

    int count(int n){
        int res = 0;
        int m = n / bk;
        for(int i = 0; i < m; i++){
            res += sum2[i];
        }
        for(int i = m * bk; i <= n; i++){
            res += sum[i];
        }
        return res;
    }

    int cal(const char s[]){
        int p = rt;
        for(int i = 0; s[i]; i++){
            p = nxt[p][s[i] - 'a'];
        }
        return count(R[p]) - count(L[p] - 1);
    }

}gao;
struct Query{
    int ope;
    string s;
    void read(){
        scanf("%d%s", &ope, tmp);
        s = tmp;
    }
}Q[maxn];

int main(){
    int n, q;
    while(scanf("%d%d", &n, &q) != EOF){
        for(int i = 0; i < maxn; i++) Q[i].s.clear();
        scanf("%s", str);
        gao.init();
        for(int i = 1; i <= q; i++){
            Q[i].read();
            if(!Q[i].ope){
                gao.ins(tmp);
            }
        }
        gao.build();
        gao.dfs(gao.rt);
        gao.update(0, n - 1, gao.rt, 1);
        for(int i = 1; i <= q; i++){
            if(Q[i].ope){
                int pos = Q[i].ope - 1;
                int l = max(0, pos - bk), r = min(n - 1, pos + bk);
                int p = gao.getPos(l, pos - 1);
                gao.update(pos, r, p, -1);
                str[pos] = Q[i].s[0];
                gao.update(pos, r, p, 1);
            }else{
                if(Q[i].s.length() >= bk)
                    printf("%d\n", kmp(str, Q[i].s.c_str()));
                else
                    printf("%d\n", gao.cal(Q[i].s.c_str()));
            }
        }
    }
    return 0;
}


