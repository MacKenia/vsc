package com.first;

public class intSort{
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
        int tmp = 0;
        System.out.println("length = " + arr.length);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + "\t");
            if(arr[tmp] <= arr[i]) {
                tmp = i;
            }
        }
        tmp++;
        System.out.println("\nBiggest int = " + tmp);
    }
}
