#include<bits/stdc++.h>
using namespace std;

const int maxn = 1123,maxm = 112345;

vector<int> edge[maxm];

int q;

int arr[maxn][maxn],line[maxn],rev[maxn];
int oper[maxm],x[maxm],y[maxm],worked[maxm];

int n,m;
int ans[maxm];
int anser;
void did(int i,int &anw,bool redo){
    if(oper[i] == 4) return;
    int & l = line[x[i]];
    if(oper[i] == 3){
        anw -= l, l = m - l;
        anw += l, rev[x[i]] ^= 1;
    }
    if(redo && worked[i]==false) return;

    int ope = oper[i];
    if(redo){
        worked[i] = false;
        ope = 3 - ope;
    }
    if(ope == 1 && arr[x[i]][y[i]] == rev[x[i]]){ 
        worked[i] = true;
        l ++;
        arr[x[i]][y[i]] ^= 1;
        anw ++;
    }
    if(ope == 2 && arr[x[i]][y[i]] != rev[x[i]]){
        worked[i] = true;
        l --;
        arr[x[i]][y[i]] ^= 1;
        anw--;
    }
}

void dfs(int st,int fa){
    did(st,anser,false);
    ans[st] = anser;
    for(auto x : edge[st]){
        dfs(x,st);
    }
    did(st,anser,true);
}


int main(){
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=q;i++){
        scanf("%d %d",&oper[i],&x[i]);
        if(oper[i] < 3) scanf("%d",&y[i]);
    }
    int last = 0;
    for(int i=1;i<=q;i++){
        if(oper[i] == 4){
            last = x[i];
        }
        edge[last].push_back(i);
        last = i;
    }
    memset(rev,0,sizeof(rev));
    memset(arr,0,sizeof(arr));
    memset(line,0,sizeof(line));
    memset(worked,0,sizeof(worked));
    anser = 0;
    dfs(0,-1);
    for(int i=1;i<=q;i++)
        if(oper[i] != 4) printf("%d\n",ans[i]);
        else printf("%d\n",ans[x[i]]);
    return 0;
}


