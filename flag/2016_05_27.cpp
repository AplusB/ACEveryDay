#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100005;
const int SIZE = maxn << 1;
char str[maxn];

struct SAM{
    int nxt[SIZE][26], par[SIZE], len[SIZE], mxl[SIZE];\
    int cur[SIZE], pos[SIZE];
    int root, tol, last;

    int newNode(int x){
        len[tol] = x;
        par[tol] = -1;
        memset(nxt[tol], -1, sizeof nxt[tol]);
        return tol++;
    }

    void Init(){
        root = tol = 0;
        last = newNode(0);
        memset(mxl, 0, sizeof mxl);
    }

    void add(int k){
        int p = last;
        int np = newNode(len[p] + 1);
        while(p != -1 && nxt[p][k] == -1){
            nxt[p][k] = np;
            p = par[p];
        }
        if(p == -1) par[np] = root;
        else{
            int q = nxt[p][k];
            if(len[p] + 1 == len[q]) par[np] = q;
            else{
                int nq = newNode(len[p] + 1);
                memcpy(nxt[nq], nxt[q], sizeof nxt[q]);
                par[nq]  = par[q];
                par[q] = par[np] = nq;
                while(p != -1 && nxt[p][k] == q){
                    nxt[p][k] = nq;
                    p = par[p];
                }
            }
        }
        last = np;
    }

    void ins(char s[]){
        for(int i = 0; s[i]; i++)
            add(s[i] - 'a');
    }

    void cmax(int &a, int b){
        if(a < b) a = b;
    }

    void Match(char s[]){
        int now = root, l = 0;
        for(int i = 0; s[i]; i++){
            int k = s[i] - 'a';
            if(nxt[now][k] != -1){
                l++;
                now = nxt[now][k];
                cmax(mxl[now], l);
            }else{
                while(now != -1 && nxt[now][k] == -1) now = par[now];
                if(now == -1){
                    now = root;
                    l = 0;
                }else{
                    l = len[now] + 1;
                    now = nxt[now][k];
                    cmax(mxl[now], l);
                }
            }
        }
    }

    LL Count(){
        memset(cur, 0, sizeof cur);
        for(int i = 0; i < tol; i++) cur[len[i]]++;
        for(int i = 0; i < tol; i++) cur[i] += cur[i - 1];
        for(int i = 0; i < tol; i++) pos[--cur[len[i]]] = i;
        LL ans = 0;
        for(int i = tol - 1; i >= 1; i--){
            int u = pos[i];
			cmax(mxl[par[u]], min(len[par[u]], mxl[u]));
			ans += min(len[u] - len[par[u]], len[u] - mxl[u]);
		}
        return ans;
    }

}sam;

int main(){
    int T, n, cas = 1;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        scanf("%s", str);
        sam.Init();
        sam.ins(str);
        for(int i = 1; i <= n; i++){
            scanf("%s", str);
            sam.Match(str);
        }
        printf("Case %d: %lld\n", cas++, sam.Count());
    }
    return 0;
}
