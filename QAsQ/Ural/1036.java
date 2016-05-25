import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		BigInteger dp[][] = new BigInteger[55][550];
		for(int j=0;j<55;j++){
			for(int i=0;i<550;i++){
				dp[j][i] = new BigInteger("0");
			}
		}
		dp[0][0] = BigInteger.ONE;
		for(int j=1;j<=50;j++){
			for(int i=0;i<=500;i++){
				for(int k=0;k<=9;k++){
					if(i>=k){
						dp[j][i] = dp[j-1][i-k].add(dp[j][i]);
					}
				}
			}
		}
		Scanner cin = new Scanner(System.in);
		int n,s;
		while(cin.hasNext()){
			n = cin.nextInt();
			s = cin.nextInt();
			if(s % 2 != 0){
				System.out.println("0");
				continue;
			}
			else{
				BigInteger ans = dp[n][s/2];
				ans = ans.multiply(ans);
				System.out.println(ans.toString());
			}
		}
	}
}

