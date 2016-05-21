# Ural 1036 Lucky Tickets

简单的dp

$s$为奇数时答案为$0$

$s$为偶数时答案为长$n$的各位之和为$s/2$的方案数的平方

-----

状态其实就是长度和位和，然后转移一下就好了

$dp_{n,s}=\sum\limits_{k=0}^9[n \ge 1][s\ge k]dp_{n-1,s-k}$

------

因为方案数会超过$long\;long $的表示范围，而且这个题不取模，所以需要高精度

```java
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

```

