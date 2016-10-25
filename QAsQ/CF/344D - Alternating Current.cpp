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

