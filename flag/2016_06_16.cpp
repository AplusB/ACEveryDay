#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int md = 1e9 + 7;
struct Node{
    int h;
    Node(){}
    Node(int _h): h(_h) {}
    bool operator<(const Node& tmp) const{
        if(h % 3 != tmp.h % 3)
            return h % 3 < tmp.h % 3;
        return h < tmp.h;
    }
};
priority_queue < Node > heap;

int main(){
    int n, m, h, sum, ans;
    while(scanf("%d%d", &n, &m) != EOF){
        while(!heap.empty()) heap.pop();
        sum = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &h);
            heap.push(h);
            sum += (h + 2) / 3;
            sum %= md;
        }
        ans = sum;
        while(m && !heap.empty()){
            m--;
            Node tmp = heap.top(); heap.pop();
            sum = (sum - (tmp.h + 2) / 3 + md) % md;
            tmp.h -= 2;
            if(tmp.h > 0){
                sum +=  (tmp.h + 2) / 3;
                sum %= md;
                heap.push(tmp);
            }
            ans = (ans + sum) % md;
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*
2 3
3 16

2 4
3 16
*/
