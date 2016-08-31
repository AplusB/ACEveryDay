#include<bits/stdc++.h>
using namespace std;

const int maxn = 251234,mlen = 26;
int toid(char c){ return c - 'a'; }

struct Node{
    int len,fa,nex[mlen];
    Node(int _len = 0){
        len = _len;
        memset(nex,fa=-1,sizeof(nex));
    }
    void copy(const Node & v){
        for(int i=0;i<mlen;i++) 
            nex[i] = v.nex[i];
        fa = v.fa;
    }
    void out(){
        printf("fa = %2d len = %d ",fa,len);
        for(int i=0;i<4;i++){
            printf("(%c %2d)",i+'a',nex[i]);
        }
        puts("");
    }
}node[maxn*2]; 
int _cnt;

int newNode(int len){
    node[_cnt] = Node(len);
    return _cnt++;
}
int root,omega;
void init(){
    _cnt = 0;
    root = omega = newNode(0);
}
void extend(int x){
    int ox = newNode(node[omega].len+1);
    while(omega != -1 && node[omega].nex[x] == -1){
        node[omega].nex[x] = ox;
        omega = node[omega].fa;
    }
    if(omega == -1){
        node[ox].fa = root;
    }
    else{
        int omegax = node[omega].nex[x];
        if(node[omega].len + 1 == node[omegax].len){
            node[ox].fa = omegax;
        } 
        else{
            int megax = newNode(node[omega].len+1);
            node[megax].copy(node[omegax]);
            node[ox].fa = node[omegax].fa = megax;
            while(omega != -1 && node[omega].nex[x] == omegax){
                node[omega].nex[x] = megax;
                omega = node[omega].fa;
            }
        }
    }
    omega = ox;
}

void build(char *arr){
    init();
    for(int i=0;arr[i];i++){
        extend(toid(arr[i]));
    }
}


int run(char *arr){
    int st = root;
    int ret = 0,len = 0;
    auto tox = [&](int s,int i){return node[s].nex[toid(arr[i])];};
    for(int i=0;arr[i];i++){
        if(tox(st,i) != -1){
            len++;
            ret = max(ret,len);
            st = tox(st,i);
        }
        else{
            while(st != -1 && tox(st,i) == -1){
                st = node[st].fa;
            }
            if(st == -1){
                len = 0;
                st = 0;
            }
            else {
                len = node[st].len+1;
                st = tox(st,i);
                ret = max(ret,len);
            }
        }
    }
    return ret;
}

char inp[maxn];

int main(){
    while(~scanf("%s",inp)){
        build(inp);
        scanf("%s",inp);
        printf("%d\n",run(inp));
    }
    return 0;
}

