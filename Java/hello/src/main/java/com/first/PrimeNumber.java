package com.first;
import java.util.*;

public class PrimeNumber {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		for (int i = 2; i <= 100; i++) {
			for (int j = i; j > 1; j--) {
				if(i%j == 0) continue;
			}	
		}

        	System.out.print("press enter to exit");
	        String str = s.nextLine();
		s.close();
	}
}
