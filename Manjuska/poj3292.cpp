#include<iostream> 
#include<string.h>
using namespace std;  
  
const int size=1000001;  
  
int H_Number[size+1];  
  
/*筛法打表*/  
void Table(void)  
{  
    memset(H_Number,0,sizeof(H_Number));  
  
    for(int i=5;i<=size;i+=4)  
    {  
        for(int j=5;j<=size;j+=4)  
        {  
            int multiply=i*j;  
            if(multiply>size)  
                break;  
  
            if(H_Number[i]==0 && H_Number[j]==0)  
                H_Number[multiply]=1;  
            else  
                H_Number[multiply]=-1; 
        }  
    }  
  
    int Pcount=0;  
    for(int k=1;k<=size;k++)  
    {  
        if(H_Number[k]==1)  
            Pcount++;  
        H_Number[k]=Pcount;  
    }  
    return;  
}  
  
int main(void)  
{  
    Table();  
    int h;  
    while(cin>>h && h)  
        cout<<h<<' '<<H_Number[h]<<endl;  
  
    return 0;  
}  
