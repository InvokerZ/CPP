// HW10.2.beta.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include"Stock.h"
using namespace std;


int main()
{
	ifstream infile1("TS_A");
	if (!infile1) {
		cout << "failed" << endl;
		exit(1);
	}
	int num1 = 0;
	char c;
	while (infile1.get(c)) {
		if (c == '\n')
			num1++;
	}
	ifstream infile2("TS_A");
	/*cout << "The number of lines of this file is" << num1 << endl;*/
	double* p = new double[num1];
	for (int i = 0; i < num1; i++) {
		infile2 >> p[i];
	}
	Stock A(p, num1);
	ifstream infile3("TS_AMZN");
	if (!infile3) {
		cout << "failed" << endl;
		exit(1);
	}
	int num2 = 0;
	char cc;

	while (infile3.get(cc)) {
		if (cc == '\n')
			num2++;
	}
	/*cout << "The number of lines of this file is " << num2 << endl;*/
	double* p1 = new double[num2];
	ifstream infile4("TS_AMZN");
	for (int i = 0; i < num2; i++) {
		infile4 >> p1[i];
	}
	infile1.close();
	infile2.close();
	infile3.close();
	infile4.close();
	Stock B(p1, num2);
	Stock C(A);
	Stock D = C;
	Stock E = A + B;
	cout << "__________________________________________________________________" << endl;
	cout <<endl<<"information of A is"<<endl<< A << endl;
	cout << endl<< "information of B is" << endl<< B << endl;
	cout << endl<< "information of A-B is" << endl << A - B << endl;
	cout << endl<< "information of A+B is" << endl << A + B << endl;
	cout << endl<< "information of E is" << endl << E << endl;
	


	


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
