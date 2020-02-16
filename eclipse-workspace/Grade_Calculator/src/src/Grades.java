package src;

import java.util.Scanner;

public class Grades {

	public static void main(String[] args) {
		double version = 9.00;
		int periods = 0;
		double[] rawPercentages = {93,90,87,83,80,77,73,70,67,63,60};
		char[] grades = {'A','A','B','B','B','C','C','C','D','D','D'};
		char[] symbol = {'\0','-','+','\0','-','+','\0','-','+','\0','-'};
		boolean isValid = false;
		Scanner sc = new Scanner(System.in);

		System.out.print("Welcome to v");
		System.out.print(version);
		System.out.print(" of the grade calculator.\n");
		while(isValid == false) {
			System.out.print("Please enter the number of periods that you wish to calculate grades for (1-8): ");
			periods = sc.nextInt();
			if(periods < 1 || periods > 8) {
				System.out.print("Please enter a valid number of periods! ");
			}else {
				isValid = true;
			}
		}
		
		int[] teachers = new int[8];
		double[] q1grades = new double[8];
		double[] q2grades = new double[8];
		double[] q1weights = new double[8];
		double[] q2weights = new double[8];
		double[] fweights = new double[8];
		double[] rounding = new double[8];
		double[][] percentages = new double[8][11];
		double[][] results = new double[8][11];
		
		for(int i = 0; i < periods; i++) {
			String teacher_list = "1) Mrs. Baker\n2) Mr. Sabatke\n3) Ms. Bright\n4) Mr. Ginorio\n5) Mr. McCormack\n6) Mr. Gabrielsen\n7) Mr. Harrison\n8) Mr. Williams\n9) Mr. Hall\n10) Mrs. Vaughan\n11) Mrs. Ketchum\n12) Ms. Solsvik\n13) Mr. Rigg\n14) Other\nPlease enter the number of the teacher for period ";
			int period = i + 1;
			isValid = false;
			while(isValid == false) {
				System.out.print(teacher_list);
				System.out.print(period);
				System.out.print(":");
				teachers[i] = sc.nextInt();
				if(teachers[i] < 1 || teachers[i] > 14) {
					System.out.print("Enter a valid teacher! ");	
				}else {
					isValid = true;
				}
				if(teachers[i] == 14) {
					isValid = false;
					while(isValid == false) {
						System.out.print("Please enter the weight of the first quarter as a decimal: ");
						q1weights[i] = sc.nextDouble();
						if(q1weights[i] < 0 || q1weights[i] > 1) {
							System.out.print("Enter a valid weight! ");
						}else {
							isValid = true;
						}
					}
					isValid = false;
					while(isValid == false) {
						System.out.print("Please enter the weight of the second quarter as a decimal: ");
						q2weights[i] = sc.nextDouble();
						if(q2weights[i] < 0 || q2weights[i] > 1) {
							System.out.print("Enter a valid weight! ");
						}else {
							isValid = true;
						}
					}
					isValid = false;
					while(isValid == false) {
						System.out.print("Please enter the weight of the final as a decimal: ");
						fweights[i] = sc.nextDouble();
						if(fweights[i] < 0 || fweights[i] > 1) {
							System.out.print("Enter a valid weight! ");
						}else {
							isValid = true;
						}
					}
					isValid = false;
					while(isValid == false) {
						System.out.print("Please enter the point at which the teacher rounds: ");
						rounding[i] = sc.nextDouble();
						if(rounding[i] < 0 || rounding[i] > 1) {
							System.out.print("Enter a valid weight! ");
						}else {
							isValid = true;
						}
					}
				}
			}
			isValid = false;
			while(isValid == false) {
				System.out.print("What is your grade for the first quarter of this semester? ");
				q1grades[i] = sc.nextDouble();
				if(q1grades[i] <= 0) {
					System.out.print("Enter a valid grade! ");
				}else {
					isValid =  true;
				}
			}
			isValid = false;
			while(isValid == false) {
				System.out.print("What is your grade for the second quarter of this semester? ");
				q2grades[i] = sc.nextDouble();
				if(q2grades[i] <= 0) {
					System.out.print("Enter a valid grade! ");
				}else {
					isValid =  true;
				}
			}
		}
		for(int i = 0; i < periods; i++) {
			for(int j = 0; j < 11; j++) {
				if(teachers[i] == 1 || teachers[i] == 3 || teachers[i] == 4 || teachers[i] == 7 || teachers[i] == 8 || teachers[i] == 13) {
					q1weights[i] = 0.45;
					q2weights[i] = 0.45;
					fweights[i] = 0.1;
				}else if(teachers[i] == 2 || teachers[i] == 5 || teachers[i] == 6 || teachers[i] == 9 || teachers[i] == 10 || teachers[i] == 12) {
					q1weights[i] = 0.4;
					q2weights[i] = 0.4;
					fweights[i] = 0.2;
				}else if(teachers[i] == 11) {
					q1weights[i] = 0;
					q2weights[i] = 1;
					fweights[i] = 0;
				}
				if(teachers[i] == 1 || teachers[i] == 2 || teachers[i] == 7 || teachers[i] == 8 || teachers[i] == 11 || teachers[i] == 13) {
					rounding[i] = 0;
				}else if(teachers[i] == 5 || teachers[i] == 12) {
					rounding[i] = 0.2;
				}else if(teachers[i] == 2 || teachers[i] == 4 || teachers[i] == 6 || teachers[i] == 9 || teachers[i] == 10) {
					rounding[i] = 0.5;
				}
				percentages[i][j] = rawPercentages[j] - rounding[i];
				results[i][j] = (percentages[i][j] - ((q1grades[i] * q1weights[i])+(q2grades[i] * q2weights[i]))) / fweights[i];
			}
		}
		for(int i = 0; i < periods; i++) {
			String guaranteed1 = "You are guaranteed to get at least an ";
			String guaranteed2 = "You are guaranteed to get at least a ";
			String guaranteed3 = " for the semester!";
			
			String out1 = "You need at least a ";
			String out2 = " to get a ";
			String out3 = " for this semester.";
			
			int k = i + 1;
			
			for(int j = 0; j < 11; j++) {
				if(results[i][j] <= 0) {
					if(j <= 1) {
						System.out.println("Period " + k + ": " + guaranteed1 + grades[j] + symbol[j] + guaranteed3);
						j = 11;
					}else {
						System.out.println("Period " + k + ": " + guaranteed2 + grades[j] + symbol[j] + guaranteed3);
						j = 11;
					}
				}else {
					System.out.println("Period " + k + ": " + out1 + results[i][j] + "%" + out2 + grades[j] + symbol[j] + out3);
				}
			}
		}
		sc.close();
	}

}
