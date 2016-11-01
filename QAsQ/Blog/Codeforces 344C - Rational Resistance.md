# Codeforces 344C - Rational Resistance

刚开始手头有一个阻值为1的电阻。

每次可以将手上的一堆电阻和某个阻值为1的电阻串联或者并联来获得一个新的电阻，问至少需要多少个阻值为1的电阻能凑出阻值为$\frac{a}{b}(1 \le a,b\le 10^{18})$的电阻

---

假设当前手头上有$\frac{x}{y}$的电阻，那么每一次加电阻可以将其变为$\frac{x}{x+y}$或者$\frac{x+y}{y}$的电阻。通过简单的模拟前五次左右的策略不看出规律

具体见代码

```cpp
#include<bits/stdc++.h>
using namespace std;

#define LL long long 

int main(){
    LL a,b;
    cin>>a>>b;
    LL tim = 0;
    do{
        if(a > b) swap(a,b);
        if(a == 1){
            tim += b,b = 1;
        }
        else{
            tim += b / a;
            b %= a;
        }
    } while(a != 1 || b != 1);
    cout<<tim<<endl;
    return 0;
}
```

