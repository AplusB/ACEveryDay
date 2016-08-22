# 707D - Persistent Bookcase

将操作建立成一个树

维护之前的最后一个操作的节点编号，不妨设为$last$

如果当前操作是回退操作，就将$last$修改为回退的那个节点

然后将当前操作作为一个子节点挂在$last$下面，并且修改$last$为当前节点

对这一个树dfs的过程中，进入一个节点的时候使用这个节点的操作更新维护的信息，离开这个节点的时候撤销这个操作

需要注意的是对于操作1、2，需要同时记录这个操作有没有和整体的状态冲突，如果冲突的话，撤销操作的时候需要跳过

对于操作3，如果同时维护每一行当前的书本个数，每一行当前是否被翻转的话，可以$O(1)$的时间内维护操作后的贡献

---

剩下的具体见代码

----

```cpp
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

```



