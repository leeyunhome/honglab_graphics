// example1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void writePPM();

int main()
{
	const string filename = "example1";
	ofstream ofile("2x2.ppm");

	const int image_width = 2;
	const int image_height = 2;

	ofile << "P3\n" << image_width << ' ' << image_height << "\n255" << "\n";
	ofile << "255 0 0" << ' ' << "0 255 0" << "\n";
	ofile << "0 0 255" << ' ' << "0 0 0";

	return 0;
}

void writePPM()
{

}