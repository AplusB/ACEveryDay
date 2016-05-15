#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 3000005;
char str[100];

struct Trie{
    int nxt[maxn][26];
    int cnt[maxn];
    int tol, rt;

    int newNode(){
        memset(nxt[tol], -1, sizeof nxt[tol]);
        cnt[tol] = 0;
        return tol++;
    }

    void init(){
        tol = 0;
        rt = newNode();
    }

    void add(char s[]){
        int p = rt;
        for(int i = 0, c; s[i]; i++){
            c = s[i] - 'a';
            if(nxt[p][c] == -1)
                nxt[p][c] = newNode();
            p = nxt[p][c];
            cnt[p]++;
        }
    }

    void del(char s[], int val){
        if(!val) return;
        int p = rt;
        for(int i = 0, c; s[i]; i++){
            c = s[i] - 'a';
            p = nxt[p][c];
            cnt[p] -= val;
        }
        memset(nxt[p], -1, sizeof nxt[p]);
    }

    int find(char s[]){
        int p = rt;
        for(int i = 0, c; s[i]; i++){
            c = s[i] - 'a';
            p = nxt[p][c];
            if(p == -1) return 0;
        }
        return cnt[p];
    }
}gao;

int main(){
    int n;
    char ope[30];
    while(scanf("%d", &n) != EOF){
        gao.init();
        while(n--){
            scanf("%s%s", ope, str);
            if(ope[0] == 'i')
                gao.add(str);
            else if(ope[0] == 'd')
                gao.del(str, gao.find(str));
            else
                puts(gao.find(str) ? "Yes" : "No");
        }
    }
    return 0;
}
