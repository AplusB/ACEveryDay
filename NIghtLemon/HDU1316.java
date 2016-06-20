import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main
{
	public static void main(String args[])
	{
		Scanner cin = new Scanner(System.in);	
		int i,L,R;
		BigInteger l,r;
		BigInteger[] a = new BigInteger[7107];
		a[1] = new BigInteger("1");
		a[2] = new BigInteger("2");
		for(i=2;i<=480;i++)
			a[i+1] = a[i].add(a[i-1]);
		while(cin.hasNext()){
			l=cin.nextBigInteger();
			r=cin.nextBigInteger();
			if(r.equals(r.ZERO)) break;
			for(L=1;a[L].compareTo(l)==-1;L++);
			for(R=481;a[R].compareTo(r)==1;R--);
			if(L>R) System.out.println("0");
			else System.out.println(R-L+1);		
		}
	}
}
