# Codeforces 347C - Alice and Bob

组合游戏。

每一回合挑选集合中的两个数$x,y$, 满足$|x-y|$不在集合中，然后把$|x-y|$加到集合里。给出集合最初的$n$个数问是否先手必胜。

---

游戏结束的时候最小的数就是这$n$个数的$gcd$，最大的数就是一开始给出的集合的最大的数。

游戏结束的时候的集合的大小就是结束时$\frac{最大的数}{最小的数}$

这样就可以得出游戏进行的步数,然后就可以得到结果了

---

```cpp
#include<bits/stdc++.h>
using namespace std;

const int maxn = 120;

int arr[maxn];

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++) cin>>arr[i];
    int v = arr[0];
    for(int i = 1;i<n;i++) v = __gcd(v,arr[i]);
    int siz = *max_element(arr,arr+n) / v - n;
    cout<<((siz&1)?"Alice":"Bob")<<endl;
    return 0;
}
```

