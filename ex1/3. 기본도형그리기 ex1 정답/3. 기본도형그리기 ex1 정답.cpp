// 3. 기본도형그리기 ex1 정답.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void drawPixel(const int& x, const int& y, const uint8_t& r, const uint8_t& g, const uint8_t& b, const int& width, vector<uint8_t>& buffer);//Too many parameters
void writePPM(const string& filename, const vector<uint8_t>& pixels, const int& width, const int& height);

int main()
{
	const string filename = "ex1_simplelines.ppm";

	const int image_width = 64;
	const int image_height = 64;

	vector<uint8_t> buffer(image_width * image_height * 3);
	fill(buffer.begin(), buffer.end(), 255); // clear buffer with white background color
	
	for (int i = 0; i < image_width; i++) drawPixel(i, 0, 0, 0, 0, image_width, buffer);
	for (int i = 0; i < image_width; i++) drawPixel(i, image_height - 1, 0, 0, 0, image_width, buffer);
	for (int j = 0; j < image_height; j++) drawPixel(0, j, 0, 0, 0, image_width, buffer);
	for (int j = 0; j < image_height; j++) drawPixel(image_width - 1, j, 0, 0, 0, image_width, buffer);
	for (int i = 0; i < std::min(image_width, image_height); i++) drawPixel(i, i, 0, 0, 0, image_width, buffer);//It's ok if ou assumed width == height.
	for (int i = 0; i < std::min(image_width, image_height); i++) drawPixel(i, image_height - 1 - i, 0, 0, 0, image_width, buffer);

	writePPM(filename, buffer, image_width, image_height);

	return 0;
}

void drawPixel(const int& i, const int& j, const uint8_t& r, const uint8_t& g, const uint8_t& b, const int& width, vector<uint8_t>& buffer)//Too many parameters
{
	const size_t offset = (i + width * j) * 3;
	buffer[offset] = r;
	buffer[offset + 1] = g;
	buffer[offset + 2] = b;
}
void writePPM(const string& filename, const vector<uint8_t>& pixels, const int& width, const int& height)
{
	ofstream ofile(filename);

	ofile << "P3\n" << width << ' ' << height << "\n" << "255\n";

	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; ++i)
		{
			const int offset = (i + width * j) * 3;
			for (int c = 0; c < 3; ++c)
			{
				ofile << (int)pixels[offset + c];
				if (i < width - 1 || c < 2)
				{
					ofile << " ";
				}
			}
		}
		ofile << "\n";
	}
	ofile << flush;
}