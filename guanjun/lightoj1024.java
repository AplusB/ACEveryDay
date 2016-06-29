import java.math.*;
import java.io.*;
import java.util.*;
import java.text.*;
public class Main{

	/**
	 * @param args
	 */
	public static BigInteger lcm(BigInteger a,BigInteger b){
		return a.divide(a.gcd(b)).multiply(b);//.divide(a.gcd(b));
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin=new Scanner(System.in);
		int T,n;
		T=cin.nextInt();
		for(int t=1;t<=T;t++){
			n=cin.nextInt();
			BigInteger x=new BigInteger("1");
			BigInteger ans=new BigInteger("1");
			for(int i=1;i<=n;i++){
				x=cin.nextBigInteger();
				ans=lcm(ans,x);
			}
			System.out.println("Case "+t+": "+ans);
			
		}
	}

}
