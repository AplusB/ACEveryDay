#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345,maxLen = 130;

int toid(char c){ return c; }

queue<int> Q;

struct ACMA{
    int nex[maxn][maxLen],fail[maxn];
    int cnt[maxn];
    int _cnt,root;
    int newNode(){
        memset(nex[_cnt],cnt[_cnt] = fail[_cnt] = -1,sizeof(nex[_cnt]));
        return _cnt++;
    }
    void init(){
        _cnt = 0;
        root = newNode();
    }
    void insert(char *arr,int id){
        int st = root;
        for(int i=0;arr[i];i++){
            int & stx = nex[st][toid(arr[i])]; 
            if(stx == -1) stx = newNode();
            st = stx;
        }
        cnt[st] = id;
    }
    void build(){
        while(Q.empty()==false) Q.pop();
        fail[root] = root;
        int st;
        for(int i=0;i<maxLen;i++){
            if((st = nex[root][i]) != -1){
                fail[st] = root;
                Q.push(st);
            }
        }
        while(Q.empty()==false){
            st = Q.front(),Q.pop();
            for(int i=0;i<maxLen;i++){
                if(nex[st][i] != -1){
                    int fst = fail[st],son = nex[st][i];
                    while(fst != root && nex[fst][i] == -1)
                        fst = fail[fst];
                    fail[son] = nex[fst][i] == -1 ? root : nex[fst][i]; 
                    Q.push(son);
                }
                else{
                    nex[st][i] = nex[fail[st]][i];
                }
            }
        };
    }
    void out(){
        for(int i=0;i<_cnt;i++){
            printf("%d  ",i);
            printf("fail = %2d cnt = %d ",fail[i],cnt[i]);
            for(int j=0;j<26;j++){
                if(nex[i][j] != -1)
                printf("(%c:%3d)",j+'a',nex[i][j]);
            }
            puts("");
        }
    }
    int cal(char *arr,int * anw){
        int len = 0, st = root;
        for(int i=0;arr[i];i++){
            st = nex[st][toid(arr[i])];
            int tem = st;
            while(tem != root){
                if(cnt[tem] != -1)
                    anw[len++] = cnt[tem];
                tem = fail[tem];
            }
            if(len == 3) break;
        }
        return len;
    }
}acma;

int anw[5];

bool solve(char *arr,int id){
    int len = acma.cal(arr,anw);
    if(len != 0){
        sort(anw,anw+len);
        printf("web %d:",id);
        for(int i=0;i<len;i++){
            printf(" %d",anw[i]);
        }
        puts("");
        return true;
    }
    return false;
}

char arr[maxn];
int main(){
    int n;
    while(~scanf("%d\n",&n)){
        acma.init();
        for(int i=1;i<=n;i++){
            gets(arr);
            acma.insert(arr,i);
        }
        acma.build();
        scanf("%d\n",&n);
        int cnt = 0;
        for(int i=1;i<=n;i++){
            gets(arr);
            cnt += solve(arr,i);
        }
        printf("total: %d\n",cnt);
    }
    return 0;
}
