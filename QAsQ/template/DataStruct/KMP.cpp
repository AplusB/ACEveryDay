void calnext(char *arr,int *next){
    next[0]=-1;
    for(int i=1;arr[i];i++){
        int ind = next[i-1];
        while(ind >= 0 && arr[i] != arr[ind+1])
            ind = next[ind];
        if(arr[i] == arr[ind+1]) next[i] = ind + 1;
        else next[i] = -1;
    }
}
