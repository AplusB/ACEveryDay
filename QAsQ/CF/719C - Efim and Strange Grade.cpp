#include<bits/stdc++.h>
using namespace std;

char arr[212345];

int dig(){
    for(int i=1;arr[i];i++){
        if(arr[i] == '.')
            return i;
    }
    return -1;
}

void round(int k,int pos){
    for(int i = pos;arr[i];i++){
        if(arr[i] != '.' && arr[i] >='5' ){
            while(k-- && i > pos){ 
                arr[i] = 0;
                if(arr[i-1] == '.'){
                    arr[i-1] = 0;
                    i = i-1;
                }
                arr[i-1]++;
                i--;
                while(i > 0 && arr[i] > '9'){
                    arr[i] = '0';
                    arr[i-1]++;
                    i--;
                }
                if(i == 0) arr[i] = '1';
                if(arr[i] < '5')
                    return;
            }
            return;
        }
    }
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    scanf("%s",arr+1);
    arr[0] = 0;
    int pos = dig();
    round(k,pos);
    if(arr[0] == 0) printf("%s",arr+1);
    else printf("%s",arr);
    return 0;
}
    

