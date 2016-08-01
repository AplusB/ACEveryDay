import java.math.*;
import java.util.Scanner;
public class Main {

	/**
	 * @param args
	 */
	public static int []vis=new int[3100];
	public static void get(){
		//for(int i=0;i<3100;i++)vis[i]=0;
		vis[1]=1;
		for(int i=2;i<3100;i++){
			if(vis[i]==0){
				for(int j=i+i;j<3100;j+=i)
					vis[j]=1;
			}
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin=new Scanner(System.in);
		get();
		int s,m;
		while(cin.hasNext()){
			s=cin.nextInt();
			m=cin.nextInt();
			if(s<3){
				System.out.println("1");continue;
			}
			int cnt=0;
			BigInteger dp[]=new BigInteger[3100];
			int v[]=new int[3100];
			dp[0]=BigInteger.ONE;
			for(int i=1;i<=s;i++){
				dp[i]=BigInteger.ONE;
				if(vis[i]==0)v[++cnt]=i;
			}
			//System.out.println(cnt);
			for(int i=1;i<=cnt;i++){
				for(int j=s;j>=v[i];j--){
					//if(j-1<0||j-v[i]<0||j<0||v[i]<0)continue;
					for(int k=v[i];k<=j;k*=v[i]){
						BigInteger x=new BigInteger(Integer.toString(k));
						if(dp[j].compareTo(dp[j-k].multiply(x))>0){
							dp[j]=dp[j];
						}
						else dp[j]=dp[j-k].multiply(x);
					}
				}
			}
			System.out.println(dp[s].mod(new BigInteger((Integer.toString(m)))));
		}
	}

}
