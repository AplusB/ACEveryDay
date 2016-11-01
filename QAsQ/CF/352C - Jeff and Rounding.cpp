#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int num(char c){
    return c - '0';
}
const int maxn = 4123;

int make(string v){
    v = v.substr(v.size() - 3,3);
    return num(v[0])*100 + num(v[1])*10 + num(v[2]);
}

char inp[maxn];
int main(){
    int n;
    scanf("%d",&n);
    int len = 0;
    int nzer = 0,sum = 0;
    for(int i = 0;i < n * 2;i++){
        scanf("%s",inp);
        int v = make(inp);
        if(v){
            sum -= v,nzer ++;
        }
    }
    int ans = INF;
    bool can = nzer & 1;
    int iniw = (nzer + 1) / 2;
    sum += 1000 * iniw;
    if(can){
        ans = min(ans,abs(sum - 1000));
    }
    for(int i = 0; i <= n - iniw;i++){
        ans = min(ans,abs(sum + i * 1000));
        ans = min(ans,abs(sum - i * 1000));
        if(can){
            ans = min(ans,abs(sum + i * 1000 - 1000));
            ans = min(ans,abs(sum - i * 1000 - 1000));
        }
    }
    printf("%d.%03d\n",ans/1000,ans%1000);
    return 0;
}

            

