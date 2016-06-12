#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;
const int bnd = 243;

int toid(char c){
    switch(c){
    case 'R':
        return 0;
        break;
    case 'P':
        return 1;
        break;
    case 'S':
        return 2;
        break;
    }
    return -1;
}

int getv(int *s){
    int ret = 0;
    for(int i=0;i<5;i++){
        ret = ret * 3 + s[i];
    }
    return ret;
}

int times(int X,int Y){
    int ret = 0;
    while(X || Y){
        ret += X%3 == (Y+1)%3;
        X/=3,Y/=3;
    }
    return ret;
}

vector<int> Win[bnd][6],Lose[bnd][6];

void init(){
    for(int X=0;X<bnd;X++){
        for(int Y=0;Y<bnd;Y++){
            int t = times(X,Y);
            Win[X][t].push_back(Y);
            Lose[Y][t].push_back(X);
        }
    }
}

int ans[maxn][11];
int inp[maxn][10];
int cnt[6][bnd][bnd];

int main(){
    int T,icase = 1;
    init();
    scanf("%d",&T);
    int n;
    while(T-- && ~scanf("%d",&n)){
        memset(cnt,0,sizeof(cnt));
        char arr[15];
        for(int i=0;i<n;i++){
            scanf("%s",arr);
            for(int j=0;j<10;j++){
                inp[i][j] = toid(arr[j]);
            }
        }
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++){
            int fir = getv(inp[i]),sec = getv(inp[i]+5);
            for(int j=0;j<=5;j++){
                for(vector<int>::iterator it = Lose[fir][j].begin();it!=Lose[fir][j].end();it++){
                    int x = *it;
                    cnt[j][x][sec]++;
                }
            }
        }
        memset(ans,0,sizeof(ans));
        for(int i=0;i<n;i++){
            int fir = getv(inp[i]),sec = getv(inp[i]+5);
            for(int fw = 0;fw<=5;fw++){
                for(int sw = 0;sw<=5;sw++){
                    for(vector<int>::iterator it = Win[sec][sw].begin();it!=Win[sec][sw].end();it++){
                        int x = *it;
                        ans[i][fw+sw] += cnt[fw][fir][x];
                    }
                }
            }
            ans[i][0]--;
        }
        printf("Case #%d:\n",icase++);
        for(int i=0;i<n;i++){
            for(int j=0;j<=10;j++){
                printf(j<10?"%d ":"%d\n",ans[i][j]);
            }
        }
    }
    return 0;
}
