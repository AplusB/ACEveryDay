#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF (1<<29)

int N;

struct Mat{
    int m[222][222];
    Mat(){
        for(int i=0; i<222; ++i){
            for(int j=0; j<222; ++j) m[i][j]=INF;
        }
    }
};
Mat operator*(const Mat &m1,const Mat &m2){
    Mat m;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            for(int k=0; k<N; ++k){
                m.m[i][j]=min(m.m[i][j],m1.m[i][k]+m2.m[k][j]);
            }
        }
    }
    return m;
};

int idx[1111];

int main(){
    Mat m;
    int n,t,s,e,a,b,c;
    scanf("%d%d%d%d",&n,&t,&s,&e);
    memset(idx,-1,sizeof(idx));
    while(t--){
        scanf("%d%d%d",&c,&a,&b);
        if(idx[a]==-1){
            idx[a]=N++;
        }
        if(idx[b]==-1){
            idx[b]=N++;
        }
        m.m[idx[a]][idx[b]]=m.m[idx[b]][idx[a]]=c;
    }
    --n;
    Mat ans=m;
    while(n){
        if(n&1){
            ans=ans*m;
        }
        m=m*m;
        n>>=1;
    }
    printf("%d",ans.m[idx[s]][idx[e]]);
    return 0;
}
