package com.first;
import java.util.*;

public class intSort{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int[] arr = {1, 2, 3, 4, 5, 66, 7, 8, 9, 10, 11, 12};
        int tmp = 0;
        System.out.println("length = " + arr.length);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + "\t");
            if(arr[tmp] <= arr[i]) {
                tmp = i;
            }
        }
        tmp++;
        System.out.println("\nBiggest index = " + tmp);
        System.out.print("press enter to exit");
        String str = s.nextLine();
	s.close();
    }
}
