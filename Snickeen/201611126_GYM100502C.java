import java.util.Scanner;
import java.math.*;

public class Main{
    public static void main(String args[]){
        Scanner cin = new Scanner(System.in);
        BigInteger [] f = new BigInteger[5010];
        BigInteger a,b;int n,m,i;
        BigInteger r = new BigInteger("1");
        BigInteger s = new BigInteger("2");
        BigInteger t = new BigInteger("4");
        f[0]=r;
        for(i=1;i<5005;i++){
            String tmp = i + "";
            BigInteger k = new BigInteger(tmp);
            a=k.multiply(t);
            a=a.subtract(s);
            b=k.add(r);
            //string tmp = i+"";
            f[i]=f[i-1].multiply(a);
            f[i]=f[i].divide(b);
        }
        n=cin.nextInt();
        System.out.println(f[n+1]);
        
    }
}
