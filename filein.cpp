#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
string headline;
int main()
{
	string category;
	float height, mass;
	ofstream outFile("infile", ios::out);
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

	string headline;
	ifstream inFile("outfile", ios::in);
	if (!inFile) {
		cerr << "Failed opening" << endl;
		exit(1);

	}
	getline(inFile, headline);
	cout << headline << endl;
	while (inFile >> height >> mass) {
		cout << height << "\t" << mass << "\t" << endl;

	}

	
	return 0;

}
