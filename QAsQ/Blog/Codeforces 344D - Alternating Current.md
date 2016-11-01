# Codeforces 344D - Alternating Current

桌上有两根相互缠绕的电线，问能否在符合题目要求的移动下将这两根电线解开

---

不难看出相邻的两个同色线结是可以消去的，那么能否解开就等价于能否把线结消空。

这样用一个栈模拟即可。

```cpp
#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;

char arr[maxn];

stack<char> S;
int main(){
    scanf("%s",arr);
    for(int i=0;arr[i];i++){
        if(!S.empty() && S.top() == arr[i]){
            S.pop();
        }
        else{
            S.push(arr[i]);
        }
    }
    puts(S.empty()?"Yes":"No");
    return 0;
}


```

