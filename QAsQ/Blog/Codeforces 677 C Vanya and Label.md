# Codeforces 677 C Vanya and Label

按位考虑大水题，，感觉没有什么好说的。。还是看代码吧

```cpp
#include<cstdio>
#include<cctype>
#include<cassert>
#include<algorithm>
using namespace std;
#define LL long long
const int mod = 1000000007;

int cove(char c){
    if(isdigit(c)) return c-'0';
    if(isupper(c)) return c-'A'+10;
    if(islower(c)) return c-'a'+36;
    if(c == '-') return 62;
    if(c == '_') return 63;
    return -1;
}

LL getpair(int x){
    assert(x != -1);
    LL ret = 1;
    for(int i=0;i<6;i++){
        if(!(x&1))
            (ret *= 3) %= mod;
        x>>=1;
    }
    return ret;
}

char arr[112345];

int main(){
    LL ans = 1;
    scanf("%s",arr);
    for(int i=0;arr[i];i++){
        (ans *= getpair(cove(arr[i]))) %= mod;
    }
    printf("%I64d\n",ans);
    return 0;
}
```



