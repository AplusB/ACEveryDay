#include<bits/stdc++.h>
using namespace std;

const int maxn = 150;
queue<int> edge[maxn];
int main(){
    int n;
    cin>>n;
    int x;
    int rev =0;
    for(int i=0;i<n;i++){
        cin>>x;
        edge[x].push(i+1);
        rev += x;
    }
    int v = n / 2;
    rev /= n / 2 ;
    while(v>0){
        for(int i=0;i<maxn;i++){
            if(edge[i].size() > 0){
                cout<<edge[i].front()<<" ";
                edge[i].pop();
                cout<<edge[rev-i].front()<<endl;
                edge[rev-i].pop();
                v--;
                break;
            }
        }
    }
    return 0;
}
