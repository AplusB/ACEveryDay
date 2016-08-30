#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    if(n == 1 || n == 2){
        puts("1");
        puts("1");
    }
    else if(n == 3){
        puts("2");
        puts("1 3");
    }
    else{
        printf("%d\n",n);
        deque<int> ans;
        for(int i=1;i<=n;i+=2){
            ans.push_back(i);
        }
        int ed = n;
        if(n & 1) ed--;
        for(int i = ed;i >= 1;i-=2)
            ans.push_front(i);
        auto it = ans.begin();
        for(int i=1;i<=n;i++){
            printf(i<n?"%d ":"%d\n",*it);
            it++;
        }
    }
    return 0;
}
