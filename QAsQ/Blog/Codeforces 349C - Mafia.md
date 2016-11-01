# Codeforces 349C - Mafia

有$n$个小朋友玩游戏。每一次游戏都必须有一个小朋友坐庄，其他的人作为$player$参加。对于小朋友$i$，他希望至少有$a_i$次游戏作为$player$参加，问至少需要多少次游戏才能满足所有小朋友的条件。

---

二分游戏的次数，计算每个小朋友可以坐庄的次数，加和判断是否大于总次数即可

```cpp
#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;
#define LL long long 
const LL INFF = 0x3f3f3f3f3f3fll;

LL arr[maxn];
int n;

bool check(LL x){
    LL ret = 0;
    for(int i = 0;i<n;i++){
        ret += x - arr[i];
    }
    return ret >= x;
}

LL cal(){
    LL st = *max_element(arr,arr+n),ed = INFF;
    LL ans = -1;
    while(st <= ed){
        LL mid = (st + ed)>>1;
        if(check(mid)){
            ans = mid;
            ed = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }
    return ans;
}

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%I64d",&arr[i]);
    }
    printf("%I64d\n",cal());
    return 0;
}
```

