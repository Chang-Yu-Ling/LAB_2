
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
float value; int i = 0; float v[10]; string c[10]; int n;
//000000000000000000000000000000000000000000000000000000000000000000000000000
class BMI{
public:
	
	void get(float hight, float mass){
		string line;
		ifstream inFile("outfile", ios::in);
		getline(inFile, line);
		while (inFile >> hight >> mass) {
			bmi(hight, mass); i++; 
			
			}	
	}

	
	void bmi(float hight, float mass){
		float value;
		if (hight != 0&&mass!=0)value = mass / pow((hight / 100), 2); else value = NULL;
		v[i] = value; n = i;
	}


	float set(float value){ 
				
		return value; }



	string cat(float value){
		string cat;
		if (value<15)
		{
			cat = "Very severely underweight";
		}
		else if (value >= 15 && value<16)
		{
			cat = "Severely underweight";
		}
		else if (value >= 16 && value<18.5)
		{
			cat = "Underweight";
		}
		else if (value >= 18.5 && value<25)
		{
			cat = "Normal";
		}
		else if (value >= 25 && value<30)
		{
			cat = "Overweight";
		}
		else if (value >= 30 && value<35)
		{
			cat = "Obese Class I (Moderately obese)";
		}
		else if (value >= 35 && value<40)
		{
			cat = "Obese Class II (Severely obese)";
		}
		else if (value >= 40)
		{
			cat = "Obese Class III (Very severely obese)";
		}
		else{ cout << "wrong"; }
		return cat;
	}


private:
	float height = 0, mass = 0;

};


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
float main(){
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
		outFile << v[i] << "\t" << c[i] << endl;
		cout << v[i] << "\t" << c[i] << "\n";

	}
	
	
	cout << endl;
	file_out();
	
	return 0;
}