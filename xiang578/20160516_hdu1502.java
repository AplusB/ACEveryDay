import java.math.BigInteger;
import java.util.Scanner;

public class Maxin {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n,x,y,z;
		BigInteger[][][] dp=new BigInteger[100][100][100];
		for(int i=0;i<=90;i++)
			for(int j=0;j<=90;j++)
				for(int k=0;k<=90;k++)
					dp[i][j][k]=BigInteger.ZERO;
		dp[0][0][0]=BigInteger.ONE;
		for(int i=0;i<=60;i++)
			for(int j=0;j<=i;j++)
				for(int k=0;k<=j;k++)
				{
					x=i-1;
					y=j-1;
					z=k-1;
					if(x>=0&&j>=0&&k>=0&&x>=j&&x>=k&&j>=k) dp[i][j][k]=dp[i][j][k].add(dp[i-1][j][k]);
					if(i>=0&&y>=0&&k>=0&&i>=y&&x>=k&&y>=k) dp[i][j][k]=dp[i][j][k].add(dp[i][j-1][k]);
					if(i>=0&&j>=0&&z>=0&&i>=j&&x>=z&&y>=z) dp[i][j][k]=dp[i][j][k].add(dp[i][j][k-1]);
				}
		while(in.hasNext())
		{
			n=in.nextInt();
			System.out.println(dp[n][n][n]);
			System.out.println();
		}
		in.close();
	}

}

