const int maxn = 10086;

int mobius[maxn];

int main(){
    memset(mobius,0,sizeof(mobius));
    for(int i=1;i<maxn;i++){
        int target = i==1;
        int delta = target - mobius[i];
        mobius[i] = delta;
        for(int j = i * 2;j<maxn;j+=i){
            mobius[j] += delta;
        }
    }
    for(int i=0;i<100;i++)
        printf("%d ",mobius[i]);
    return 0;
}

