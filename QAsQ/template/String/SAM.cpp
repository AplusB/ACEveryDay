const int maxn = 112345 ,mlen = 26;

struct Sam{
    int len[maxn*2],fa[maxn*2],nex[maxn*2][mlen];
    int _cnt,root,omg;
    int newNode(int L = 0){
        len[_cnt] = L;
        memset(nex[_cnt],fa[_cnt] = -1,sizeof(nex[_cnt]));
        return _cnt++;
    }
    void init(){
        _cnt = 0;
        root = omg = newNode();
    }
    void extend(int x){
        int ox = newNode(len[omg]+1);
        while(omg != -1 && nex[omg][x] == -1){
            nex[omg][x] = ox;
            omg = fa[omg];
        }
        if(omg == -1) fa[ox] = root;
        else{
            int omgx = nex[omg][x];
            if(len[omgx] == len[omg]+1) fa[ox] = omgx;
            else{
                int mgx = newNode(len[omg]+1);
                for(int i=0;i<mlen;i++)
                    nex[mgx][i] = nex[omgx][i];
                fa[mgx] = fa[omgx];
                fa[omgx] = fa[ox] = mgx;
                while(omg != -1 && nex[omg][x] == omgx)
                    nex[omg][x] = mgx,omg = fa[omg];
            }
        }
        omg = ox;
    }
    void build(char *arr){
        init();
        for(int i=0;arr[i];i++){
            extend(arr[i] - 'a');
        }
    }
}SAM;
