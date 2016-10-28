#include<bits/stdc++.h>
using namespace std;

const int maxn = 512345;
const int sb = 1123456;

int arr[sb];
int lowbit(int x){ return x&(-x); }

void upd(int x,int v){
    x+=5;
    while(x < sb){
        arr[x] += v;
        x += lowbit(x);
    }
}
int que(int x){
    x+=5;
    int ret = 0;
    while(x){
        ret += arr[x];
        x -= lowbit(x);
    }
    return ret;
}

int last[maxn],yet[maxn];
int ln,yn;

int getDif(){
    int pos = 0;
    while(pos < ln && pos < yn){
        if(last[pos] == yet[pos]) pos++;
        else return pos;
    }
    return -1;
}
int cal(int m,int c){
    memset(arr,0,sizeof(arr));
    int gl = 0,gr = c-1;
    scanf("%d",&ln);
    for(int i = 0;i<ln;i++) scanf("%d",&last[i]);
    for(int j = 2;j<=m;j++){
        scanf("%d",&yn);
        for(int i = 0;i<yn;i++) scanf("%d",&yet[i]);
        int pos = getDif();
        if(pos == -1){
            if(ln > yn) return -1;
        }
        else{
            int a = last[pos],b = yet[pos];
            if(a < b){
                upd(c-b+1,1);
                upd(c-a+1,-1);
                //printf("inseg = %d %d\n",c-b+1,c-a+1);
            }
            else{
                //printf("othseg %d %d\n",c-a+1,c-b);
                gl = max(gl,c-a+1),gr = min(gr,c-b);
            }
        }
        ln = yn;
        for(int i = 0;i<ln;i++) last[i] = yet[i];
    }
    //printf("lr = %d %d\n",gl,gr);
    for(int i = gl;i <= gr;i++){
        if(que(i) == 0) return i;
    }
    return -1;
}

int main(){
    int m,c;
    scanf("%d %d",&m,&c);
    printf("%d\n",cal(m,c));
    return 0;
}
