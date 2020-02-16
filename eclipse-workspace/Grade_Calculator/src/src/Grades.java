package src;

import java.util.Scanner;

public class Grades {
	
	

	public static void main(String[] args) {
		final String version = "9.0.0 a2";
		final double[] rawPercentages = {93,90,87,83,80,77,73,70,67,63,60};
		final char[] grades = {'A','A','B','B','B','C','C','C','D','D','D'};
		final char[] symbol = {'\0','-','+','\0','-','+','\0','-','+','\0','-'};
		
		int periods = 0;
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
		double[][] teacherConstants = new double[4][8]; //0=q1,1=q2,2=fw,3=round
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
						teacherConstants[0][i] = sc.nextDouble();
						if(teacherConstants[0][i] < 0 || teacherConstants[0][i] > 1) {
							System.out.print("Enter a valid weight! ");
						}else {
							isValid = true;
						}
					}
					isValid = false;
					while(isValid == false) {
						System.out.print("Please enter the weight of the second quarter as a decimal: ");
						teacherConstants[1][i] = sc.nextDouble();
						if(teacherConstants[1][i] < 0 || teacherConstants[1][i] > 1) {
							System.out.print("Enter a valid weight! ");
						}else {
							isValid = true;
						}
					}
					isValid = false;
					while(isValid == false) {
						System.out.print("Please enter the weight of the final as a decimal: ");
						teacherConstants[2][i] = sc.nextDouble();
						if(teacherConstants[2][i] < 0 || teacherConstants[2][i] > 1) {
							System.out.print("Enter a valid weight! ");
						}else {
							isValid = true;
						}
					}
					isValid = false;
					while(isValid == false) {
						System.out.print("Please enter the point at which the teacher rounds: ");
						teacherConstants[3][i] = sc.nextDouble();
						if(teacherConstants[3][i] < 0 || teacherConstants[3][i] > 1) {
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
				teacherConstants[0][i] = q1weight(teachers[i]);
				teacherConstants[1][i] = q2weight(teachers[i]);
				teacherConstants[2][i] = fweight(teachers[i]);
				teacherConstants[3][i] = rounding(teachers[i]);
				results[i][j] = calculate(teacherConstants[0][i], teacherConstants[1][i], teacherConstants[2][i], rawPercentages[j], teacherConstants[3][i], q1grades[i], q2grades[i]);
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
	public static double calculate(double weight1, double weight2, double fweight, double raw, double round, double grade1, double grade2) {
		double percentages = raw - round;
		double result = (percentages - ((grade1 * weight1)+(grade2 * weight2))) / fweight;
		return result;
	}
	public static double q1weight(int teachers) {
		double q1weight = 0;
		if(teachers == 1 || teachers == 3 || teachers == 4 || teachers == 7 || teachers == 8 || teachers == 13) {
			q1weight = 0.45;
		}else if(teachers == 2 || teachers == 5 || teachers == 6 || teachers == 9 || teachers == 10 || teachers == 12) {
			q1weight = 0.4;
		}else if(teachers == 11) {
			q1weight = 0;
		}
		return q1weight;
	}
	public static double q2weight(int teachers) {
		double q2weight = 0;
		if(teachers == 1 || teachers == 3 || teachers == 4 || teachers == 7 || teachers == 8 || teachers == 13) {
			q2weight = 0.45;
		}else if(teachers == 2 || teachers == 5 || teachers == 6 || teachers == 9 || teachers == 10 || teachers == 12) {
			q2weight = 0.4;
		}else if(teachers == 11) {
			q2weight = 1;
		}
		return q2weight;
	}
	public static double fweight(int teachers) {
		double fweight = 0;
		if(teachers == 1 || teachers == 3 || teachers == 4 || teachers == 7 || teachers == 8 || teachers == 13) {
			fweight = 0.1;
		}else if(teachers == 2 || teachers == 5 || teachers == 6 || teachers == 9 || teachers == 10 || teachers == 12) {
			fweight = 0.2;
		}else if(teachers == 11) {
			fweight = 0;
		}
		return fweight;
	}
	public static double rounding(int teachers) {
		double round = 0;
		if(teachers == 1 || teachers == 2 || teachers == 7 || teachers == 8 || teachers == 11 || teachers == 13) {
			round = 0;
		}else if(teachers == 5 || teachers == 12) {
			round = 0.2;
		}else if(teachers == 2 || teachers == 4 || teachers == 6 || teachers == 9 || teachers == 10) {
			round = 0.5;
		}
		return round;
	}

}
