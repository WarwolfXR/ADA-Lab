import java.util.*;
import java.io.*;
import java.util.Scanner;

public class demo {
	public static void main(String[] args) {
		ArrayList<Integer> a = new ArrayList<Integer>();
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter 5 integers:");
		for(int i=0; i<5; i++) {
			int item = sc.nextInt();
			a.add(item);
		}
			
		System.out.println("Array List before modification:" + a);
		
		//Selection sort
		
		int n = a.size();
		for(int i=0; i<n-1; i++) {
			int min = i;
			for(int j = i+1; j<n; j++) {
				if(a.get(j) < a.get(min)) {
					min=j;
				}
					int temp = a.get(i);
					a.set(i, a.get(min));
					a.set(min,temp);
				 
			}
		}
		
		System.out.println("Sorted ArrayList:" + a);
	}
}
