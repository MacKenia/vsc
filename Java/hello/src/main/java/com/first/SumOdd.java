package com.first;
import java.util.*;

public class SumOdd {
	public static void main(String[] args) {
        	Scanner s = new Scanner(System.in);
		int sum = 0;
		for (int i = 0; i < 100; i++) {
			if (i%2 == 1) {
				sum += i;
			}	
		}
		System.out.println(sum);

        	System.out.print("press enter to exit");
	        String str = s.nextLine();
		s.close();
	}
}
