package com.first;
import java.util.*;

public class PrimeNumber {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		boolean f = false;
		for (int i = 2; i <= 100; i++) {
			for (int j = i - 1; j > 1; j--) {
				f = true;
				if(i%j == 0) {
					f = false;
					break;
				}
			}
			if (f) {
				System.out.println(i);
			}
		}

        	System.out.print("press enter to exit");
	        String str = s.nextLine();
			s.close();
	}
}
