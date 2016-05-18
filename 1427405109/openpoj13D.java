/*************************************************************************
 > File Name: Main.java
 > Author: Baiyan
 > 题意：
 > Created Time: 2016年05月17日 星期二 22时31分27秒
 **********************************************************************/
import java.math.BigInteger;
import java.util.Scanner;
import java.math.BigDecimal;

public class Main
{
    static BigInteger[][] p = new BigInteger[205][205];
    void Init()
    {
        p[1][1] = BigInteger.ONE;
        p[3][1] = BigInteger.ONE;
        p[3][2] = p[3][1].add(BigInteger.ONE);
        p[3][3] = p[3][2].add(BigInteger.ONE);
        p[4][1] = BigInteger.ONE;
        p[4][2] = p[4][1].add(BigInteger.ONE);
        p[4][3] = p[4][2].multiply(p[3][3]);
        p[4][4] = p[3][3].multiply(p[3][3]);
        for(int i=5;i<=200;i++)
        {
            BigInteger sum;
            sum = BigInteger.ZERO;
            for(int j =1;j<=i-2;j++)
            {
                sum = sum.add(p[i-2][j]);
                p[i][j] = p[i-2][j];
            }
            p[i][i-1] = sum.multiply(p[3][2]);
            p[i][i] = sum.multiply(p[3][3]);
        }
    }
    public static void main(String args[])
    {
        //Init();
        p[1][1] = BigInteger.ONE;
        p[3][1] = BigInteger.ONE;
        p[3][2] = p[3][1].add(BigInteger.ONE);
        p[3][3] = p[3][2].add(BigInteger.ONE);
        p[4][1] = BigInteger.ONE;
        p[4][2] = p[4][1].add(BigInteger.ONE);
        p[4][3] = p[4][2].multiply(p[3][3]);
        p[4][4] = p[3][3].multiply(p[3][3]);
        for(int i=5;i<=200;i++)
        {
            BigInteger sum;
            sum = BigInteger.ZERO;
            for(int j =1;j<=i-2;j++)
            {
                sum = sum.add(p[i-2][j]);
                p[i][j] = p[i-2][j];
            }
            p[i][i-1] = sum.multiply(p[3][2]);
            p[i][i] = sum.multiply(p[3][3]);
        }
        Scanner scan = new Scanner(System.in);
        int T;
        T = scan.nextInt();
        while( T > 0 )
        {
            int n;
            n = scan.nextInt();
            if(n==2)
            {
                System.out.println(-1);
                continue;
            }
            for(int i=1;i<=n;i++)
                System.out.println(p[n][i]);
        }
    }

}
