package com.first;
import java.util.*;

public class Reverse {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		// int[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		
		int tmp;
		System.out.print("how many number you want to reverse:");
		tmp = s.nextInt();
		int[] arr = new int[tmp];
		for(int i = 0; i < arr.length; i++){
			arr[arr.length - i - 1] = s.nextInt();
		}
		//for(int i = 0; i < arr.length/2; i++) {
		//	tmp = arr[arr.length - i - 1];
		//	arr[arr.length - i - 1] = arr[i];
		//	arr[i] = tmp;
		//}
        	for (int i = 0; i < arr.length; i++) {
            		System.out.print(arr[i] + "\t");
		}
        	System.out.print("\nPress enter to exit");
		String str = s.nextLine();
		str = s.nextLine();
		s.close();
	}
}
