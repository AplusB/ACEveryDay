//hdoj5625

#include<iostream>
using namespace std;
int n,A,B,C,a[26],b[26],c[26],i,k,j,q;
char w;
bool flag;
int main(void){
    cin>>n;
    L1:while(n-->0){
        for(i=0;i<26;i++)
        a[i]=b[i]=c[i]=0;
        cin>>A>>B>>C;
        for(i=0;i<A;i++){
            cin>>w;
            q=w-'A';
            cin>>a[q];
        }
        for(i=0;i<B;i++){
            cin>>w;
            q=w-'A';
            cin>>b[q];
        }
        for(i=0;i<C;i++){
            cin>>w;
            q=w-'A';
            cin>>c[q];
        }
        for(i=1;i<=100;i++){
            for(j=1;j<=100;j++){
                flag=true;
                for(k=0;k<26;k++){
                    if(i*a[k]+j*b[k]!=c[k]){
                        flag=false;
                        break;    
                    }
                }
                if(flag){
                    cout<<i<<" "<<j<<endl;
                    goto L1;
                }
            }
        }
        cout<<"NO"<<endl;
        
    }
    return 0;
}
