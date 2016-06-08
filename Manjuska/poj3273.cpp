#include <stdio.h> 
#define MAX 100001
 
int day[MAX]; 
int N,M;
 
int main() 
{ 
    int i,j; 
    int sum,cnt,max,low,high,mid; 
     
     
    while(scanf("%d %d",&N,&M)!=EOF) 
    { 
       sum = 0;
       max = 0; 
       for(i=0;i<N;i++){ 
             scanf("%d",&day[i]); 
             if(day[i]>max) 
               max = day[i]; 
             sum+=day[i]; 
       } 
       low = max; 
       high = sum;
      
       
       while(low<=high) 
       { 
          mid = (low+high)/2; 
         
          sum = 0;
          cnt = 1; 
          for(i = 0;i<N;i++){ 
            sum+=day[i]; 
            if(sum>mid)  { 
               sum = day[i]; 
               cnt++; 
             }      
          } 
         
          if(cnt<=M)  { 
             max = mid; 
             high = mid-1; 
          } 
          else 
             low = mid+1; 
       } 
       printf("%d\n",max); 
    } 
    return 0; 
} 
