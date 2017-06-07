/*
Finding the square root of an integer 
Using Newton Raphson method
logics: f(x) = x^2-N, N is the number whose square root needs to be determined
		Goal is to find x and make f(x) = 0.
		1. x(1) = N/2;
		2. x(n+1) = x(n)-f(x(n))/f'(x(n))  choosing a learning rate alfa = 1;

eg: x2 = x(1)/2.0 + N/(2.0*x(1))

*/


#include <iostream>
#include <assert.h>
#include <sstream>

#define precision 0.0000001

// get the value from console and filters the undesired input
double get_value();
//return square root of the number
double square_root(double n);


int main() {
	std::cout << "*********************************************" << std::endl;
	std::cout << "Finding the square root of a positive number" << std::endl;
	std::cout << "*********************************************" << std::endl;
	double num;
	num = get_value();
	while (num) {
		std::cout << "\nsquare root of " << num << " = " << square_root(num) << "\n\n";
		num = get_value();
	}
	return 0;
}

double get_value() {
	double value;
	std::string entered_string;
	std::cout <<"Enter 'x' if you want to terminate or else enter a positive number: ";
	while (true)
	{
		std::getline(std::cin, entered_string);
		std::stringstream ss(entered_string);
		if (entered_string == "x")
			return 0;
		if (ss >> value && !(ss >> entered_string) && value>0)
			return value;
		std::cin.clear();
		std::cerr << "\nInvalid input. Please enter a valid positive number: ";
	}
}


double square_root(double n) {
	assert(n>0);
	double guess = n / 2.0;
	double error = guess*guess - n;
	while (std::abs(error) > precision) {
		guess = (guess / 2.0) + (n/(2.0*guess));
		error = guess*guess - n;
	}
	return guess;
}
