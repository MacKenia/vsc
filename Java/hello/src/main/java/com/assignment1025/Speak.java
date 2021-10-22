package com.assignment1025;
import java.util.*;

public class Speak {
	 public class Monkey {
		 private String sound;
		 public Monkey (String s) {
			sound = s;
		 }

		 public void speak() {
			 System.out.println("咿咿呀呀......");
		 }
	 }

	 public class People extends Monkey {
		public People(String s) {
			super(s);
		}

		public void speak() {
			System.out.println("小样的，不错嘛！会说话了！");
		}
		
		public void think() {
			System.out.println("别说话！认真思考!");
		}
	}

	public static void main() {
		Monkey mo = new Monkey("fuck");
		People pe = new People("fuck");
		mo.speak();
		pe.speak();
	}
}

