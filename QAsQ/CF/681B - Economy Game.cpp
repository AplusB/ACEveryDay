#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

bool jud(int n){
    int x,y,z;
    x = 1234567,y = 123456,z=1234;
    for(int i=0;i*x<=n;i++){
        for(int j=0;j*y+i*x<=n;j++){
            if((n-i*x-j*y)%z==0)
                return true;
        }
    }
    return false;
}
int main(){
    int n;
    scanf("%d",&n);
    puts(jud(n)?"YES":"NO");
    return 0;
}


