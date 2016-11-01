# Codeforces 347E - Number Transformation II

给出$n$个数字$x_i$，两个整数$A$,$B$$(A-B \le 10^6)$

每一步可以做两个操作其中一个

1 将$A$变成$A-1$

2 将$A$变成 $A - A \pmod{x_1}$

问将$A$变成$B$的最小步数。

---

每次贪心的找到能减到的最小的大于等于$B$的$A$即可。

如果一个$A -A\pmod{x_i} < B$ ,那就可以将这个$x_i$删掉。

```cpp
#include<bits/stdc++.h>
using namespace std;

set<int> S;
int main(){
    int a,b,n;
    int x;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        S.insert(x);
    }
    scanf("%d %d",&a,&b);
    int tim = 0;
    while(a != b){
        int mi = a - 1;
        for(set<int>::iterator it = S.begin();it != S.end(); ){
            int x = *it;
            it++;
            if(a - a % x < b) S.erase(x);
            else mi = min(mi,a - a % x);
        }
        a = mi;
        tim++;
    }
    printf("%d\n",tim);
    return 0;
}
```

