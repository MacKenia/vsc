package com.first;
import java.util.*;

public class PrintStar {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		for (int i = 0; i < n; i++) {
			for(int j = 1; j <= i + 1; j++) {
				System.out.print("*\t");
			}
			System.out.println();
		}
		String str = s.nextLine();
		str = s.nextLine();
		s.close();
	}


}
