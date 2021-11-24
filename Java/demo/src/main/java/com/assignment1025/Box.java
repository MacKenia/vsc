package com.assignment1025;
import java.util.*;

public class Box{
	int height;
	int width;
	int lenght;
	public Box(int a, int b, int c) {
		lenght = a;
		height = b;
		width = c;
	}

	public  int GetV() {
		return height*width*lenght;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Box b = new Box(1, 2, 3);
		System.out.println(b.GetV());
		String s = sc.nextLine();
		sc.close();
	}
}
