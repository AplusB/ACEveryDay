#include<bits/stdc++.h>
using namespace std;

const int maxn = 512345;
char arr[maxn];

int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",&arr);
    int an = 0;
    for(int i = 0;i<n;i++) an += arr[i] == 'A';
    if(an == n - an){
        puts("Friendship");
    }
    else{
        puts(an > n - an ? "Anton":"Danik");
    }
    return 0;
}
