// 3. 기본도형그리기 example1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void writePPM(const string& filename, const vector<uint8_t>& pixels, const int& width, const int& height);

int main()
{
	const string filename("example1.ppm");

	const int image_width = 64;
	const int image_height = 64;

	vector<uint8_t> buffer(image_width * image_height * 3);

	for (int row = 0; row < image_height; ++row)
	{
		for (int col = 0; col < image_width; ++col)
		{
			const int offset = (col + image_width * row) * 3;
			if (row == 0 || row == image_height - 1 || col == 0 
				|| col == image_width -1 || row == col || col == image_width -1 -row)
			{
				buffer[offset] = 0;
				buffer[offset + 1] = 0;
				buffer[offset + 2] = 0;
			}
			else
			{
				buffer[offset] = 255;
				buffer[offset + 1] = 255;
				buffer[offset + 2] = 255;
			}
			
		}
	}

	writePPM(filename, buffer, image_width, image_height);

	return 0;
}

void writePPM(const string& filename, const vector<uint8_t>& pixels, const int& width, const int& height)
{
	ofstream ofile(filename);

	ofile << "P3\n" << width << ' ' << height << "\n" << "255\n";

	for (int row = 0; row < height; ++row)
	{
		for (int col = 0; col < width; ++col)
		{
			const int offset = (col + width * row) * 3;
			for (int c = 0; c < 3; ++c)
			{
				ofile << (int)pixels[offset + c];
				if (col < width - 1 || c < 2)
				{
					ofile << " ";
				}
			}
		}
		ofile << "\n";
	}
	ofile << flush;
}