package com.assignment1025;
import java.util.*;

public class Complex {
	int real;
	int image;
	public Complex(int a, int b) {
		real = a;
		image = b;
	}

	public Complex add(Complex a) {
		this.real += a.real;
		this.image += a.image;
		return this;
	}

	public Complex sub(Complex a) {
		this.real -= a.real;
		this.image -= a.image;
		return this;
	}

	public Complex mult(Complex a) {
		this.real = this.real*a.real + this.image*a.image;
		this.image = this.real*a.image + this.image*a.real;
		return this;
	}

	public void dp() {
		System.out.println("real: " + real);
		System.out.println("image: " + image);
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Complex a = new Complex(1, 2);
		Complex b = new Complex(2, 3);
		Complex c;
		c = a.add(b);
		a.dp();
		c = a.sub(b);
		a.dp();
		c = a.mult(b);
		a.dp();
		String s = sc.nextLine();
		sc.close();
	}
}
