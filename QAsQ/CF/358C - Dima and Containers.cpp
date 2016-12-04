#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;
int arr[maxn], anw[maxn];

priority_queue<pair<int,int>,vector<pair<int,int>> > Q;

void out(bool in,int num){
    if(in){
        switch(num){
            case 1: printf("pushStack"); break;
            case 2: printf("pushQueue"); break;
            case 3: printf("pushFront"); break;
            default: printf("pushBack"); break;
        }
    }
    else{
        printf("%d",num);
        if(num == 0) return;
        printf(" popStack");
        if(num == 1) return;
        printf(" popQueue");
        if(num == 2) return;
        printf(" popFront");
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i ++) scanf("%d",&arr[i]);
    for(int i = 0 ; i < n ; i ++){
        if(arr[i] != 0){
            Q.push(make_pair(arr[i],i));
            anw[i] = -1;
        }
        else{
            anw[i] = 0;
            for(int v = 1 ; v <= 3 && Q.empty()==false;v++){
                int pos = Q.top().second;
                Q.pop();
                anw[i] = anw[pos] = v;
            }
            while(Q.empty()==false) Q.pop();
        }
    }
    for(int i = 0 ; i < n ; i ++){
        out(arr[i] != 0,anw[i]);
        puts("");
    }
    return 0;
}
