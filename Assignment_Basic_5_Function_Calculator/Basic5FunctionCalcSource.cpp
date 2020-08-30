/********************
*Assignment:  Assignment_Basic_5_Function_Calculator.cpp
*
*You must create a program that will act as a basic 5 function calculator  
*for the mathematical functions.   
*
*
*For this project you must create a C++ project that will:
*
*Include separate functions to perform the following:
*--Prompt for user to enter a numeric value.  (this will be used twice.) 
*--Prompt for user to enter the type of calculation. ( + - * / )
*--perform the calculation. (one each for addition, subtraction, multiplication, and division)
*--display the full results of the calculation. (see below for sample output.)
*This program will use all double precision variables.
*All variables should be local to the functions they are needed in, and passed appropriately. (NO Globals!)
*The program should loop continuously until the user decides they are done.
*The program should then pause and wait for the user to press a key before closing.
*
*The final output should show the complete calculation:
*
*   Example:
*        12.4 + 5.32 = 17.72
*    Or:
*        3.0 * 2.5 = 7.5
*
*For the addition function, this must be a templated function.  
*So, if the user chooses Addition, they must then enter whether they want to use 
*integers or doubles.  
*Regardless, the program will call the templated function that will handle both 
*types to show the templated function can handle either.
*
* Author: Angela Robinson
* Date:   May 23, 2018
*
**********************/

// PreProcessor Directives
#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;


//function prototypes
int menu(); //get the user choice
double subtraction(double, double); //perform subtraction
double multiplication(double, double); //perform multiplication
double division(double, double); //perform division
double getNumber(); //get a number
void results(double, double, char, double); //show results


//template functions
template <class addType>
double addition(addType num1, addType num2)
{
	cout << "The sum of " << num1 << " + " << num2 << " = " << num1 + num2 << endl;
	return num1 + num2;
};


//Main Program
int main()
{
	//variables
	int choice;
	char intOrDouble;
	double number1;
	double number2;
	double sum =0; //result of additon
	double difference = 0; //result of subtractin
	double product= 0; //result of multiplication
	double quotient = 0; //result of division


	//code
	choice = menu();
	
	while (choice != 5)
	{
		number1 = getNumber();
		number2 = getNumber();
		cout << "number1: " << number1 << endl;
		cout << "number2: " << number2 << endl;

		if (choice == 1)
		{
			//ask user if they want to use integers or double percision
			do
			{
				cout << "Do you want to enter intigers(I) or double percision(D) numbers? ";
				cin >> intOrDouble;
				intOrDouble = toupper(intOrDouble);

			} while (intOrDouble != 'I' && intOrDouble != 'D');
			
			if (intOrDouble == 'I')
			{
				//if user chose to use intigers, then the number intered would be truncated to int type. i.e. if inputed 1.5 for number1, the int type would be 1
				sum = addition((int)number1, (int)number2);
				results((int)number1, (int)number2, '+', sum);
			}
			else
			{
				sum = addition(number1, number2);
				results(number1, number2, '+', sum);
			}

			//show results
			
		} 
		else if (choice == 2)
		{
			difference = subtraction(number1, number2);
			results(number1, number2, '-', difference);
		}
		else if (choice == 3)
		{
			product = multiplication(number1, number2);
			results(number1, number2, '*', product);
		}
		else if (choice == 4)
		{
			quotient = division(number1, number2);
			results(number1, number2, '/', quotient);
		}
		//cin.ignore();//clear buffer
		choice = menu();
	};
	
	cin.ignore();//clear buffer
	cout << "Press any key to exit . . .";
	getchar(); //this will accept any charcter including Enter
	//system("Pause");
	return 0;
}

//functions

//show menu, get and return choice
int menu() 
{ 
	int input;
	
	cout << std::string(50,'#') << endl;
	cout << "#\t What would you like to do today?\t #\n";
	cout << "#\t 1. Addition\t\t\t\t #\n";
	cout << "#\t 2. Subtraction\t\t\t\t #\n";
	cout << "#\t 3. Multiplication\t\t\t #\n";
	cout << "#\t 4. Division\t\t\t\t #\n";
	cout << "#\t 5. Exit\t\t\t\t #\n";
	cout << std::string(50, '#') << endl;
	cout << "\nPlease enter your choice: ";
	cin >> input;

	return input; 
};

double getNumber()
{
	double num;
	cout << "\nEnter a number: ";
	cin >> num;
	cin.ignore(); //clear buffer
	return num;
};

void results(double num1, double num2, char calcSymbol, double result)
{
	cout << setw(6)
		<< setiosflags(ios::fixed | ios::right)
		<< setprecision(2)
		<< num1 << " "
		<< calcSymbol
		<< num2 << " = "
		<< result << endl;
};

double subtraction(double num1, double num2) { return num1 - num2; };
double multiplication(double num1, double num2) { return num1 * num2; };
double division(double num1, double num2) { return num1 / num2; };


