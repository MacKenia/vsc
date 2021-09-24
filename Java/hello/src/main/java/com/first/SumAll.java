package com.first;
import java.util.*;

public class SumAll {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int sum = 0;
		for(int i = 1; i <= 100; i++) {
			sum += i;
		}
		System.out.println(sum);
		String str = s.nextLine();
		s.close();

	}
}
