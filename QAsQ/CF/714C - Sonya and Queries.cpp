#include<bits/stdc++.h>
using namespace std;
#define LL long long 
const int maxn = 1123456;

struct Bits{
    int nex[maxn][2],len[maxn],sum[maxn];
    int _cnt,root;
    int newNode(){
        nex[_cnt][0] = nex[_cnt][1] = -1;
        len[_cnt] = sum[_cnt] = 0;
        return _cnt++;
    }
    void init(){
        _cnt = 0;
        root = newNode();
    }
    void out(){
        for(int i=0;i<_cnt;i++){
            printf("%d : %2d %2d len = %d sum = %d\n",i,nex[i][0],nex[i][1],len[i],sum[i]);
        }
    }
    void inser(char *v,int d){
        int st = root;
        for(int i=0;v[i];i++){
            int & stx = nex[st][(v[i] - '0') & 1];
            if(stx == -1) stx = newNode();
            st = stx,sum[st]+=d;
        }
        len[st] += d;
    }
    void add(char *v){
        inser(v,1);
    }
    void del(char *v){
        inser(v,-1);
    }
    int que(char *v){
        int ret = 0,st = root;
        for(int i=0;v[i];i++){
            int & stx = nex[st][(v[i]-'0') & 1];
            if(stx == -1) stx = newNode();
            st = stx,ret += len[st];
        }
        return ret + sum[st] - len[st];
    }
}bits;

void restore(char *arr){
    int len = strlen(arr);
    for(int i=len;i<20;i++){
        arr[i] = '0';
    }
    arr[20] = 0;
    reverse(arr,arr+len);
}


int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    string ord;
    char v[30];
    bits.init();
    while(t--){
        cin>>ord>>v;
        restore(v);
        if(ord == "+") bits.add(v);
        if(ord == "-") bits.del(v);
        if(ord == "?") cout<<bits.que(v)<<endl;
    }
    return 0;
}


