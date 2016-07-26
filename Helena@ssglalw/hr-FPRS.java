
import java.io.*;
import java.util.*;

public class Solution {
	static int state;
	static StringBuffer medium = new StringBuffer();
	static int getType(char c){
		if(c == '.' || c == '?' || c == '!') return 0;//句结束
		if(c == '\"') return 1;//引号
		if(c == ' ') return 3;//空格
		return 2;//字母或其他标点
	}
	static void stateChange(int type){
		switch(state){
		case 0:
			switch(type){
			case 0: state = 1; break;//开头若为句结束标点，其实不合法
			case 1: state = 3; break;
			case 2:
			case 3: state = 1; break;
			}
			break;
		case 1:
			switch(type){
			case 0: state = 2; break;
			case 1: state = 3; break;
			case 2: 
			case 3: state = 1; break;
			}
			break;
		case 2:
			switch(type){
			case 0: state = 2; break;//连续两个句结束标点，其实不合法
			case 1:
			case 2:
			case 3: state = 1;
			}
			break;
		case 3:
			switch(type){
			case 0:
			case 1: state = 1; break;
			case 2: 
			case 3: state = 3;
			}
		}
	}
	static void actionPerform(char c){
		switch(state){
		case 1:
		case 3:
			Solution.medium.append(c);
			break;
		case 2:
			Solution.medium.append(c + "\n");
		}
	}
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		File file = new File("in.txt");
		Scanner input = new Scanner(file);
		String in = input.next();
		while(input.hasNext()) in = in + " " + input.next();//以空格分隔的一行，无回车
		for(int i=0; i<in.length(); i++){
			char cur = in.charAt(i);
			int option = Solution.getType(cur);
			int lastState = state;
			Solution.stateChange(option);
			if(lastState == 2 && option == 3) continue;
			Solution.actionPerform(cur);
		}
		int len = 0;
		for(int i=0; i<medium.length(); i++){
			if(medium.charAt(i) == ' ') len = 0;
			if(medium.charAt(i) == '.'){
//				System.out.println(len);
//				System.out.println(medium.substring(i-len, i));
				if(len <= 3 && i < medium.length()-1){
					medium.setCharAt(i+1, ' ');
				}
				len = 0;
			}
			else len++;
		}
		System.out.print(medium);
	}

}
