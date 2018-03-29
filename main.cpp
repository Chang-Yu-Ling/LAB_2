
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include<cmath>
#include"class.h"
using namespace std;

//0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
float height, mass;
float file_in()
{
	string category;
	
	ofstream outFile("outfile", ios::out);
	if (!outFile) {
		cerr << "Failed opening" << endl;
		exit(1);

	}
	cout << "Enter height mass		each line.\n"
		<< "0 0 to finish.\n" << "? ";
	outFile << "height\tmass\n";
	while (cin >> height >> mass) {
		outFile << height << "\t" << mass << endl;
		cout << "? ";
		if (height == 0 && mass == 0)break;
	}
	cout << endl;
}


	
float file_out(){
	string line;
	ifstream inFile("infile", ios::in);
	if (!inFile) {
		cerr << "Failed opening" << endl;
		exit(1);

	}
	getline(inFile, line);
	cout << line << endl; 
	for (size_t i = 0; i < n; i++)
	{	inFile >> v[i] >> c[i];
		cout << v[i] << "\t" << c[i] << "\t" << endl;
			
	}
	
	
	
}
int main(){
	string cat;
	
	file_in();
	BMI A;
	A.get(height, mass); 
		
	cout << endl;

	A.set(value);
	for (size_t i = 0; i < n; i++)
	{

		ofstream outFile("outfile", ios::out);
		if (!outFile) {
			cerr << "Failed opening" << endl;
			exit(1);
		}
		
		outFile << "height\tcategory\n";
		c[i] = A.cat(v[i]);
		
		for (size_t i = 0; i < n; i++)
	{outFile << v[i] << "\t" << c[i] << endl;
	
	}
		cout << v[i] << "\t" << c[i] << "\n";	

	}
	
	
	cout << endl;
	file_out();
	
	return 0;
}
