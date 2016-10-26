#include<bits/stdc++.h>
using namespace std;
const int maxn = 112,maxLen = 26;

int toid(char c){ return c - 'A'; }
queue<int> Q;

struct acam{
    int nex[maxn][maxLen],fail[maxn];
    int cnt[maxn];
    int _cnt,root;
    int newNode(){
        memset(nex[_cnt],fail[_cnt] = -1,sizeof(nex[_cnt]));
        cnt[_cnt] = 0;
        return _cnt++;
    }
    void init(){
        _cnt = 0;
        root = newNode();
    }
    void insert(char *arr){
        int st = root;
        for(int i=0;arr[i];i++){
            int & stx = nex[st][toid(arr[i])];
            if(stx == -1) stx = newNode();
            st = stx;
        }
        cnt[st]++;
        // update cnt
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
            else nex[root][i] = root;
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
        }
    }
    void out(){
        for(int i = 0; i<_cnt;i++){
            printf("id = %d : ",i);
            for(int j = 0;j<maxLen;j++){
                if(nex[i][j] != 0){
                    printf("%c -> %d ",j + 'A',nex[i][j]);
                }
            }
            puts("");
        }
    }
}acam;

char a[maxn],b[maxn],vair[maxn];
string dp[maxn][maxn][maxn];

string smax(string a,string b){
    if(a.size() > b.size())
        return a;
    return b;
}

int main(){
    acam.init();
    scanf("%s %s %s",a+1,b+1,vair);
    acam.insert(vair);
    acam.build();
    int n = strlen(a+1),m = strlen(b+1);
    int vsiz = strlen(vair);
    for(int i = 0;i<=n;i++){
        for(int j = 0;j <= m;j++){
            for(int k = 0; k <= vsiz; k++){
                dp[i][j][k] = "";
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            for(int k = 0 ; k < vsiz;k++){
                dp[i][j][k] = smax(dp[i][j][k],dp[i-1][j][k]);
                dp[i][j][k] = smax(dp[i][j][k],dp[i][j-1][k]);
                if(a[i] == b[j]){
                    int x = a[i] - 'A';
                    int kx = acam.nex[k][x];
                    dp[i][j][kx] = smax(dp[i][j][kx],dp[i-1][j-1][k]+string(1,a[i]));
                }
            }
        }
    }
    string ans = "";
    for(int i = 0;i < vsiz;i++){
        ans = smax(ans,dp[n][m][i]);
    }
    if(ans == "") ans = "0";
    printf("%s\n",ans.c_str());
    return 0;
}
