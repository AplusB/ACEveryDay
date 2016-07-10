import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

import javax.swing.text.GapContent;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n, m;
		int[][] dp = new int[1010][1010];
		String cmd = new String();
		for(int i = 0; i < 1010; i++) {
			for(int j = 0; j < 1010; j++) {
				dp[i][j] = 0;
			}
		}
		n = in.nextInt(); m = in.nextInt();
		int x1, x2, y1, y2, num;
		while(m-- > 0) {
			cmd = in.next();
			if(cmd.charAt(0) == 'A') {
				x1 = in.nextInt();
				y1 = in.nextInt();
				num = in.nextInt();
				for(int i = y1; i < n; i++) {
					dp[x1][i] = (dp[x1][i] + num) % 1000000007;
				}
			}
			else {
				x1 = in.nextInt();
				x2 = in.nextInt();
				y1 = in.nextInt();
				y2 = in.nextInt();
				int ret = 0;
				for(int i = x1; i <= y1; i++) {
					if(x2 == 0) ret = (ret + dp[i][y2]) % 1000000007;
					else ret = (ret + dp[i][y2] - dp[i][x2-1]) % 1000000007;
				}
				System.out.println((ret + 1000000007) % 1000000007);
			}
		}
	}
}
