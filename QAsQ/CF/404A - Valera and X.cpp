#include<cstdio>
using namespace std;

const int maxn = 1010;

char arr[maxn][maxn];

bool jud(int n){
    auto is = [=](int x,int y){return x == y || x+y==n-1;};
    if(n==1) return true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!is(i,j) && arr[i][j] != arr[0][1])
                return false;
            if(is(i,j) && arr[i][j] != arr[0][0])
                return false;
        }
    }
    return arr[0][0] != arr[0][1];
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",arr[i]);
    }
    puts(jud(n)?"YES":"NO");
    return 0;
}
