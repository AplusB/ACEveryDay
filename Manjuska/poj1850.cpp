#include <iostream>  
#include <string>  
  
using namespace std;  
  
int c[27][27];  
  
void combinations()  
{  
    for (int i = 0; i <= 26; i++)  
    {  
        for (int j = 0; j <= i; j++)  
        {  
            if (!j || i == j)  
            {  
                c[i][j] = 1;  
            }  
            else  
            {  
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];  
            }  
        }  
    }  
    return;  
}  
  
  
int main()  
{  
    combinations();  
    string s;  
    while (cin>>s)  
    {  
        for(int i=1;i<s.length();i++)  
        {  
            if(s[i-1]>=s[i])  
            {  
                cout<<0<<endl;  
                return 0;  
            }  
        }  
        int sum=0;  
          
        for(int i=1;i<s.length();i++)  
            sum+=c[26][i];  
          
        for(int i=0;i<s.length();i++)  
        {  
            char ch= (!i)?'a':s[i-1]+1;  
            while(ch<=s[i]-1)  
            {  
                sum+=c['z'-ch][s.length()-1-i];  
                ch++;  
            }  
        }  
        cout<<++sum<<endl;  
    }  
}  
