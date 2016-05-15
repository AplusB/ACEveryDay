import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main
{
    public static void main(String args[])
    {
        Scanner cin = new Scanner(System.in);    
        int i,j,t = 0,n;
        BigInteger[] a = new BigInteger[10007];
        a[1] = new BigInteger("1");
        a[2] = new BigInteger("1");
        a[3] = new BigInteger("1");
        a[4] = new BigInteger("1");
        for(i=5;i<=10000;i++)
            a[i]=a[i-1].add(a[i-2].add(a[i-3].add(a[i-4])));
        while(cin.hasNext()){
            n = cin.nextInt();
            System.out.println(a[n]);
        }
    }
}
